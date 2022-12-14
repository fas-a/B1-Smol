#ifndef MAINMENU_H_
#define MAINMENU_H_


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>




void arrowhere(int realPosition, int arrowPosition);

int PilihMenu();

void TampilLogo();

void delay(int ms);

void renderLogo();

void gotoxy(int x, int y);

void hideCursor();

#endif