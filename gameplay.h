#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

/*
    Author : Farhan Muhammad Luthfi
    Date   : 18/12/2022
*/

typedef struct {
    int x;
    int y;
    int skor;
    char nama[3];
} Player;

/*
Status:
O - Kosong
X - Terisi
P - Ditempati player
*/

typedef struct {
    int x;
    int y;
    char status;
} Petak;

/*
Deskripsi	: Modul ini sebagai modul utama untuk bermain. Dari sini tampilan akan direset dan berubah menjadi tampilan untuk bermain yang berisi papan catur, timer, skor,
dan riwayat gerakan player.
I.S	: Game belum dijalankan
F.S	: Game dijalankan
*/

void PlayGame(Player pl);

/*
Deskripsi	: Modul untuk mengatur posisi awal x dan y player pada papan. Data x dan y dari struct Player diubah lalu melakukan perubahan pada papan sesuai lokasi player
pada papan. Juga untuk pengaturan timer yang diinginkan, dan inisialisasi skor.
I.S	: Posisi awal player belum diketahui
F.S	: Posisi awal player sudah diketahui, timer dan skor sudah diinisialisasi.
*/

void initializePlayer(Player *pl);

/*
Deskripsi	: Modul ini digunakan untuk menampilkan papan. Papan akan diprint ulang setiap kali pemain melakukan gerakan untuk memutakhirkan papan sesuai dengan kondisi
atau state masing-masing petak. Dalam modul ini akan dilakukan pengecekan status dari setiap petak lalu melakukan pencetakan tergantung status tersebut.
I.S	: Papan catur tidak tampil
F.S	: Papan catur ditampilkan
*/

void tampilPapan(Player pl);

/*
Deskripsi	: Menampilkan jejak langkah pemain selama permainan berlangsung.
I.S	: Jejak terbaru belum ditampilkan.
F.S	: Jejak terbaru sudah ditampilkan.
*/

void history();

/*
Deskripsi	: Menampilkan skor
I.S	: Skor belum diupdate.
F.S	: Skor terupdate
*/

void tampilMisc(Player pl);

/*
Deskripsi	: Modul untuk pemain memilih petak selanjutnya yang akan ditempati. Dengan menggunakan arrow key, pemain diberikan keluasaan untuk bergerak pada petak manapun.
Tetapi petak yang bisa ditempati hanya petak yang sesuai dengan langkah kudapada catur (8 kemungkinan).
I.S	: Posisi player pada suatu petak diketahui.
F.S	: Posisi player berada pada petak lain dan status petak yang ditempati saat ini berubah.
*/

void Move(Player *p);

/*
Deskripsi	: Menyimpan hasil permainan pemain setelah permainan selesai dengan kondisi baik menang maupun kalah.
I.S	: Jejak terbaru belum ditampilkan.
F.S	: Jejak terbaru sudah ditampilkan.
*/

void saveToLB(Player pl);

/*
Deskripsi	: Modul untuk memindahkan posisi cursor pada console. X dan y dibalik untuk kebutuhan papan.
I.S	: Cursor berada di titik asal
F.S	: Cursor berpindah ke titik yang diinput
*/

void invgotoxy(int x, int y);

/*
Deskripsi	: Memvalidasi apakah petak yang dituju merupakan langkah kuda.
I.S	: Tidak diketahui status validasi petak.
F.S	: Diketahui status validasi petak.
*/

bool validate(int ix, int iy, int x, int y);

/*
Deskripsi	: Memvalidasi apakah masih ada petak yang bisa ditempati oleh pemain.
I.S	: Tidak diketahui status evaluasi petak.
F.S	: Diketahui status evaluasi petak.
*/

bool evaluate(int x, int y);

void gotoxy(int x, int y);

#endif // GAMEPLAY_H_
