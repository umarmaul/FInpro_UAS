#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char name[100];
    int day;
    int month;
    int year;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Node *createNode(const char *name, int day, int month, int year) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    sprintf(newNode->name, "%s", name);
    newNode->day = day;
    newNode->month = month;
    newNode->year = year;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue *queue, const char *name, int day, int month, int year) {
    Node *newNode = createNode(name, day, month, year);

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

    printf("\nPesanan baru telah masuk ke daftar antrian.\n");
}

void dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("\nPesanan telah dihapus dari antrian.\n\n");
}

void displayQueue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Pesanan kosong.\n");
        return;
    }

    Node *temp = queue->front;
    int index = 1;
    printf("Queue:\n");
    while (temp != NULL) {
        printf("%d. %s - %02d/%02d/%d\n", index, temp->name, temp->day, temp->month, temp->year);
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

void editName(Node *head, int taskIndex) {
    Node *temp = head;
    int index = 1;

    while (temp != NULL) {
        if (index == taskIndex) {
            printf("Masukkan nama baru: ");
            scanf(" %[^\n]s", temp->name);
            printf("\nNama baru telah tersimpan.\n");
            return;
        }
        temp = temp->next;
        index++;
    }

    printf("Permintaan tidak valid.\n");
}

void editDate(Node *head, int taskIndex) {
    Node *temp = head;
    int index = 1;

    while (temp != NULL) {
        if (index == taskIndex) {
            printf("Masukkan tanggal baru (DD MM YYYY): ");
            scanf("%d %d %d", &temp->day, &temp->month, &temp->year);
            printf("\nTanggal telah diubah.\n");
        return;
        
    }
    temp = temp->next;
    index++;
	}	

	printf("Permintaan tidak valid.\n");
}

void freeList(Node *head) {
	Node *temp;
	while (head != NULL) {
	temp = head;
	head = head->next;
	free(temp);
	}
}

void cetakTanggal(int day, int month, int year){
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Array untuk nama-nama bulan
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array untuk jumlah tanggal dalam setiap bulan
	int i, j, firstDayOfMonth;
	
    // Memeriksa apakah tahun kabisat
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[1] = 29;
    	}

    // Menghitung tanggal awal pada bulan yang diminta
    day = 1;
    for (i = 0; i < month - 1; i++) {
        day += daysInMonth[i];
   		}	
	firstDayOfMonth = (day + (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;


	printf("\n%s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
			
    // Mengisi bagian kosong pada minggu pertama dengan spasi
    for (i = 0; i < firstDayOfMonth; i++) {
        printf("    ");
        }

	// Mencetak tanggal dalam kalender
    for (i = 1, j = firstDayOfMonth; i <= daysInMonth[month - 1]; i++, j++) {
    // Jika sudah mencapai akhir minggu, lanjut ke minggu berikutnya
    if (j > 6) {
        printf("\n");
        j = 0;
        }
    
	// Mencetak tanggal
    printf(" %2d ", i);
    }
    
	printf("\n");
}

int main() {
	Queue queue;
	queue.front = NULL;
	queue.rear = NULL;
	int choice;
	char name[100];
	int day, month, year;
	int taskIndex;

    int i;
    for(i = 0; i < 50; i++){
        	printf("=");
		}
    printf("\n\tProgram Pre-Order Kue Ulang Tahun\n");
    printf("\n\tKelompok 8:\n");
    printf("\tDaniel Valerian\t- 2106728295 \n\tElvina Sunardi\t- 2106706413 \n\tUmar Maulana\t- 2106631034\n");
    for(i = 0; i < 50; i++){
        printf("=");
	}
    printf("\n\n");

    system("pause");
    system("cls");
    
do {
     for(i = 0; i < 20; i++){
        	printf("=");
		}
    printf("\n\tMenu\n");
     for(i = 0; i < 20; i++){
        	printf("=");
		}
    printf("\n1. Masukkan pesanan\n");
    printf("2. Pesanan selesai\n");
    printf("3. Edit nama pemesan\n");
    printf("4. Edit tanggal pengambilan\n");
    printf("5. Menampilkan pesanan\n");
    printf("6. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: //Memasukkan pesanan baru
            system("cls");
            printf("Masukkan nama: ");
            scanf(" %[^\n]s", name);
            printf("Masukkan tanggal pengambilan (DD MM YYYY): ");
            scanf("%d %d %d", &day, &month, &year);
            cetakTanggal(day, month, year);
            enqueue(&queue, name, day, month, year);
            system("pause");
            system("cls");
            break;
        case 2: //Menghapus antrian
            system("cls");
            printf("Antrian sebelumnya:\n");
            displayQueue(&queue);
            dequeue(&queue);
            printf("Antrian sekarang:\n");
            displayQueue(&queue);
            system("pause");
            system("cls");
            break;
        case 3: //Edit nama pemesam
            system("cls");
            displayQueue(&queue);
            printf("Pesanan ke berapa yang ingin diedit: ");
            scanf("%d", &taskIndex);
            editName(queue.front, taskIndex);
            system("pause");
            system("cls");
            break;
        case 4: //Edit tanggal pengambilan
            system("cls");
            displayQueue(&queue);
            printf("Pesanan ke berapa yang ingin diedit: ");
            scanf("%d", &taskIndex);
            editDate(queue.front, taskIndex);
            system("pause");
            system("cls");
            break;
        case 5: //Menampilkan pesanan
            system("cls");
            cetakTanggal(day, month, year);
            printf("\n");
            displayQueue(&queue);
            system("pause");
            system("cls");
            break;
        case 6: //Keluar
            system("cls");
            freeQueue(&queue);
            printf("Exiting program.\n");
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            printf("Invalid choice. Please try again.\n");
            system("pause");
            system("cls");
            break;
        }
    } while (choice != 6);

    freeList(queue.front);

    return 0;
}