#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <stdbool.h>

typedef struct {
    int mm, ss;
} Waktu;

typedef struct {
    int x;
    int y;
    int skor;
    char nama[3];
    Waktu wkt;
    bool hint;
} Player;

typedef struct {
    int x;
    int y;
    char status;
} Petak;

/*
Status:
0 - Kosong
1 - Terisi
2 - Hint Move
*/

void tampilPapan(Player pl);

void History(Player pl);

void tampilMisc(Player pl);

void Move(Player pl, Petak pp);

void giveHint(Player pl, Petak pp);

void saveToLB(Player pl);

#endif // GAMEPLAY_H_