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

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
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

void editTask(Node *head, int taskIndex) {
    Node *temp = head;
    int index = 1;

    while (temp != NULL) {
        if (index == taskIndex) {
            printf("Enter new task: ");
            scanf(" %[^\n]s", temp->task);
            printf("Task edited.\n");
            return;
        }
        temp = temp->next;
        index++;
    }

    printf("Invalid task index.\n");
}

void editDate(Node *head, int taskIndex) {
    Node *temp = head;
    int index = 1;

    while (temp != NULL) {
        if (index == taskIndex) {
            printf("Enter new due date (DD MM YYYY): ");
            scanf("%d %d %d", &temp->day, &temp->month, &temp->year);
            printf("Date edited.\n");
        return;
    }
    temp = temp->next;
    index++;
	}	

	printf("Invalid task index.\n");
}

int getCount(Node *head) {
	int count = 0;
	Node *temp = head;
	while (temp != NULL) {
	count++;
	temp = temp->next;
	}
	return count;
}

void bubbleSort(Node *head) {
	int swapped, i;
	Node *ptr;
	Node *end = NULL;
	if (head == NULL)
    return;

	do {
    swapped = 0;
    ptr = head;

    while (ptr->next != end) {
        if (ptr->year > ptr->next->year ||
            (ptr->year == ptr->next->year && ptr->month > ptr->next->month) ||
            (ptr->year == ptr->next->year && ptr->month == ptr->next->month && ptr->day > ptr->next->day)) {
            // Swap the nodes
            Node *temp = ptr->next;
            ptr->next = temp->next;
            temp->next = ptr;

            if (ptr == head) {
                head = temp;
            } else {
                Node *prev = head;
                while (prev->next != ptr) {
                    prev = prev->next;
                }
                prev->next = temp;
            }

            ptr = temp;
            swapped = 1;
        }
        ptr = ptr->next;
    }
    end = ptr;
	} while (swapped);

}

void displayList(Node *head) {
	if (head == NULL) {
	printf("The list is empty.\n");
	return;
	}

	int count = getCount(head);
	Node *temp = head;

	printf("List:\n");
	int i;
	for (i = 1; i <= count; i++) {
    printf("%d. [%c] %s - %02d/%02d/%d\n", i, temp->isCompleted ? 'X' : ' ', temp->task, temp->day, temp->month, temp->year);
    temp = temp->next;
	}

}

void freeList(Node *head) {
	Node *temp;
	while (head != NULL) {
	temp = head;
	head = head->next;
	free(temp);
	}
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
    printf("6. Display Sorted List\n");
    printf("7. Exit\n");
    printf("Choice: ");
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
            editTask(queue.front, taskIndex);
            break;
        case 4:
                displayQueue(&queue);
                printf("Enter task index to edit the due date: ");
                scanf("%d", &taskIndex);
                editDate(queue.front, taskIndex);
                break;
            case 5:
                displayQueue(&queue);
                break;
            case 6:
                displayList(queue.front);
                break;
            case 7:
                freeQueue(&queue);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    freeList(queue.front);

    return 0;
}
