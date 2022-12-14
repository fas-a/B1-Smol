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

typedef struct {
    int x;
    int y;
    int skor;
    char nama[3];
} Player;

typedef struct {
    int x;
    int y;
    char status;
} Petak;

/*
Status:
O - Kosong
X - Terisi
P - Ditempati player
*/

void PlayGame(Player pl);

void initializePlayer(Player *pl);

void tampilPapan(Player pl);

void History();

void tampilMisc(Player pl);

void Move(Player *p);

void saveToLB(Player pl);

void invgotoxy(int x, int y);

bool validate(int ix, int iy, int x, int y);

bool evaluate(int x, int y);

void gotoxy(int x, int y);

#endif // GAMEPLAY_H_
