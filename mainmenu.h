#ifndef MAINMENU_H_
#define MAINMENU_H_


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>



/*
Deskripsi	: Modul untuk menentukan letak panah berada.
I.S	: Panah tidak tampil
F.S	: Panah tampil sesuai dengan data
*/
void arrowhere(int realPosition, int arrowPosition);

/*
Deskripsi	: Modul untuk mengembalikan nilai opsi dari pilihan yang dipilih sesuai dengan tampilan panah berada. 
Ex, panah ada disebelah "Play", pemain menekan tombol enter, modul mengembalikan nilai 1
*/
int PilihMenu();

/*
Deskripsi	: Modul untuk menampilkan title Knights Tour.
I.S	: title belum tampil
F.S	: title sudah tampil
*/
void TampilLogo();

/*
Deskripsi	: Modul untuk menghentikan program selama ms dengan satuan milisecond.
I.S	: Program berjalan normal
F.S	: Program berhenti selama ms satuan milisecond
*/
void delay(int ms);

/*
Deskripsi	: Modul untuk menampilkan title Knights Tour dengan animasi.
I.S	: title belum tampil
F.S	: title sudah tampil
*/
void renderLogo();

void gotoxy(int x, int y);

/*
Deskripsi	: Modul untuk menyembunyikan kursor.
I.S	: Kursor tampil pada layar
F.S	: Kursor tidak tampil pada layar
*/
void hideCursor();

#endif