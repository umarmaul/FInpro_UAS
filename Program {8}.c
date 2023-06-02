#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printOpening(){
     int i;
     
     for(i = 0; i < 45; i++){
        	printf("=");
		}
        printf("\n\tAplikasi Penjualan Mobil Bekas\n");
        printf("\n\tKelompok 8:\n");
        printf("\tDaniel Valerian\t- 2106728295 \n\tElvina Sunardi\t- 2106706413 \n\tUmar Maulana\t- 2106631034\n");
        for(i = 0; i < 45; i++){
        	printf("=");
		}
    printf("\n\n");
    system("pause");
    system("cls");
}

void cetakTanggal(int month, int year, int firstDayOfMonth, int kalender[]){
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Array untuk nama-nama bulan
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array untuk jumlah tanggal dalam setiap bulan
	int i, j;
	
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
    if (kalender[i-1] == 1) {
        printf(" %2d*", i);
        } else {
            printf(" %2d ", i);
            }
    }
    
	printf("\n");
}

int main(){
    int i, year, month, day, firstDayOfMonth;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array untuk jumlah date dalam setiap bulan
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Array untuk nama-nama bulan
    int kalender[31] = {0}; // Array untuk menyimpan penyewa pada tiap tanggal
    
    printOpening;

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
    
    cetakTanggal(month, year, firstDayOfMonth, kalender);

    return 0;
}