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

void insertNode(Node **head, const char *task, int day, int month, int year) {
    Node *newNode = createNode(task, day, month, year);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Task added.\n");
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("To-Do List is empty.\n");
    } else {
        Node *temp = head;
        int index = 1;
        printf("To-Do List:\n");
        while (temp != NULL) {
            printf("%d. [%c] %s - %02d/%02d/%d\n", index, temp->isCompleted ? 'X' : ' ', temp->task, temp->day, temp->month, temp->year);
            temp = temp->next;
            index++;
        }
    }
}

void completeTask(Node *head, int taskIndex) {
    Node *temp = head;
    int index = 1;

    while (temp != NULL) {
        if (index == taskIndex) {
            temp->isCompleted = 1;
            printf("Task completed.\n");
            return;
        }
        temp = temp->next;
        index++;
    }

    printf("Invalid task index.\n");
}

Node *findNode(Node *head, int taskIndex) {
    Node *temp = head;
    int index = 1;

    while (temp != NULL) {
        if (index == taskIndex) {
            return temp;
        }
        temp = temp->next;
        index++;
    }

    return NULL;
}

void editTask(Node *head, int taskIndex) {
    Node *node = findNode(head, taskIndex);

    if (node != NULL) {
        printf("Enter new task: ");
        scanf(" %[^\n]s", node->task);
        printf("Task edited.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void editDate(Node *head, int taskIndex) {
    Node *node = findNode(head, taskIndex);

    if (node != NULL) {
        printf("Enter new due date (DD MM YYYY): ");
        scanf("%d %d %d", &node->day, &node->month, &node->year);
        printf("Date edited.\n");
    } else {
        printf("Invalid task index.\n");
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
    Node *head = NULL;

    int choice;
    char task[100];
    int day, month, year;
    int taskIndex;

    do {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Edit Due Date\n");
        printf("4. Complete Task\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task: ");
                scanf(" %[^\n]s", task);
                printf("Enter due date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                insertNode(&head, task, day, month, year);
                break;
            case 2:
                displayList(head);
                printf("Enter task index to edit: ");
                scanf("%d", &taskIndex);
                editTask(head, taskIndex);
                break;
            case 3:
                displayList(head);
                printf("Enter task index to edit due date: ");
                scanf("%d", &taskIndex);
                editDate(head, taskIndex);
                break;
            case 4:
                displayList(head);
                printf("Enter task index to complete: ");
                scanf("%d", &taskIndex);
                completeTask(head, taskIndex);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                freeList(head);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

