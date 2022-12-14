#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "mainmenu.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

typedef struct {
    int x;
    int y;
    int skor;
    char nama[3];
}Player;


void renderLogoHighscore();

void TampilHighscore();

void displayhighscore(Player a);

void Sort_file();

int cekdata();

#endif