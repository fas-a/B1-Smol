#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "gameplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>


void TampilHighscore();

void renderLogoHighscore();

void displayhighscore(Player a);

void Sort_file();

int cekdata();

void arrowhere(int realPosition, int arrowPosition);

int PilihMenu();

void TampilLogo();

void delay(int ms);

void renderLogo();

void gotoxyfaris(int x, int y);

void hideCursor();

#endif