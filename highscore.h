#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include "gameplay.h"
#include "mainmenu.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

/*
Deskripsi	: Modul untuk menampilkan title HIGHSCORE.
I.S	: title belum tampil
F.S	: title sudah tampil
*/
void renderLogoHighscore();

/*
Deskripsi	: Modul untuk menampilkan fitur Highscore dimana menampilkan score pemain pemain sebelumnya.
I.S	: Tampilan fitur Highscore belum tampil
F.S	: Tampilan fitur Highscore sudah tampil
*/
void TampilHighscore();

/*
Deskripsi	: Modul untuk menampilkan Nama dan score pemain dari data Player a.
I.S	: Nama dan score pemain dari data Player a belum tampil
F.S	: Nama dan score pemain dari data Player a tampil
*/
void displayhighscore(Player a);

/*
Deskripsi	: Modul untuk mengurutkan data pada file hs.dat dari yang terbesar sampai yang terkecil menurut score.
I.S	: Data belum terurut
F.S	: Data sudah terurut
*/
void Sort_file();

/*
Deskripsi	: Modul untuk mengembalikan nilai jumlah dari banyaknya data Player yang ada pada file hs.dat
*/
int cekdata();

#endif