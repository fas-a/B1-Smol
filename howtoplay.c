#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);

void howtoplay(){
	printf("\t\t _____   _____   _____    _____     _____   _____   _____    __  __   _____   _____   __   _ \n");
	printf("\t\t|  ___| |  _  | |  _  \\  |  _  |   |  _  \\ |  ___| |  _  \\  |  \\/  | |  _  | |_   _| |  \\ | | \n");
	printf("\t\t| |     | |_| | | |_| |  | |_| |   | |_| | | |__   | |_| |  |      | | |_| |   | |   |   \\| | \n");
	printf("\t\t| |     |  _  | |  _  /  |  _  |   |  _ <  |  __|  |  _  /  | |\\/| | |  _  |   | |   | |\\   | \n");
	printf("\t\t| |___  | | | | | | \\ \\  | | | |   | |_| | | |___  | | \\ \\  | |  | | | | | |  _| |_  | | \\  | \n");
	printf("\t\t|_____| |_| |_| |_|  \\_\\ |_| |_|   |_____/ |_____| |_|  \\_\\ |_|  |_| |_| |_| |_____| |_|  |_| \n");
	printf("\t\t=============================================================================================\n\n");
	printf("1. Permainan dimulai dengan sebuah papan kosong berukuran 8x8.\n");
	printf("2. Pemain memilih petak pada papan untuk dijadikan petak awal atau home.\n");
	printf("3. Pemain meletakkan bidak pada petak kosong dengan jalur membentuk huruf L\n");
	printf("4. Pemain mendapatkan skor ketika meletakkan bidak pada petak kosong.\n");
	printf("5. Skor maksimal adalah 64 dimana semua petak pada papan harus dilalui.\n");
	printf("6. Pemain kalah jika sudah tidak terdapat petak yang dapat dilalui sebelum mencapai skor maksimal.\n\n");
	
	gotoxy(35,16);
	printf("Contoh :\n");
	Demo();
}

#define N 8

//Cek valid atau tidak
int isSafe(int x, int y, int sol[N][N]){
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

#define H "\033[0;32m"
#define P "\033[0;37m"
#define R "\033[0;31m"
//Tampilkan Solusi
void TampilSol(int sol[N][N]){
	int x, y;
	for (x = 0; x < N; x++) {
		gotoxy(22,17+x);
		for (y = 0; y < N; y++)
			if (sol[x][y] == 0) {
				printf(H);
				printf(" %2d ", sol[x][y]);
				printf(P);
			} else if (sol[x][y] == N*N-1) {
				printf(R);
				printf(" %2d ", sol[x][y]);
				printf(P);
			}
			else printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}

int Demo(){
	int sol[N][N];

	//Inisialisasi Solusi pada matriks
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	//Pergerakan bidak
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	sol[0][0] = 0;

	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		printf("Tidak ada Solusi");
		return 0;
	}
	else
		TampilSol(sol);

	return 1;
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]){
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;

	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
				return 1;
			else
				sol[next_x][next_y] = -1; //backtracking
		}
	}

	return 0;
}

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
