#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char task[100];
    int isCompleted;
    int day;
    int month;
    int year;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Node *createNode(const char *task, int day, int month, int year) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    sprintf(newNode->task, "%s", task);
    newNode->isCompleted = 0;
    newNode->day = day;
    newNode->month = month;
    newNode->year = year;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue *queue, const char *task, int day, int month, int year) {
    Node *newNode = createNode(task, day, month, year);

    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        if (day < queue->front->day) {
            newNode->next = queue->front;
            queue->front = newNode;
        } else {
            Node *temp = queue->front;
            while (temp->next != NULL && day >= temp->next->day) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == queue->rear) {
                queue->rear = newNode;
            }
        }
    }

    printf("Task added to the queue.\n");
}

void dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("Task removed from the queue.\n");
}

void displayQueue(Queue *queue) {
    if (queue->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Node *temp = queue->front;
    int index = 1;
    printf("Queue:\n");
    while (temp != NULL) {
        printf("%d. [%c] %s - %02d/%02d/%d\n", index, temp->isCompleted ? 'X' : ' ', temp->task, temp->day, temp->month, temp->year);
        temp = temp->next;
        index++;
    }
}

void freeQueue(Queue *queue) {
    Node *temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    queue->rear = NULL;
}

int main() {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    int choice;
    char task[100];
    int day, month, year;
    int taskIndex;

    do {
        printf("\nMenu:\n");
        printf("1. Add Task to Queue\n");
        printf("2. Remove Task from Queue\n");
        printf("3. Edit Task\n");
        printf("4. Edit Due Date\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task: ");
                scanf(" %[^\n]s", task);
                printf("Enter due date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                enqueue(&queue, task, day, month, year);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                printf("Enter task index to edit: ");
                scanf("%d", &taskIndex);
                break;
            case 4:
                displayQueue(&queue);
                printf("Enter task index to edit the due date: ");
                scanf("%d", &taskIndex);
                break;
            case 5:
                displayQueue(&queue);
                break;
            case 6:
                freeQueue(&queue);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

