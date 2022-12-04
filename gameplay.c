#include "gameplay.h"
#define N 8

void tampilPapan(Player pl) {
    // Inisialisasi var
    int i,j;
    int Px = pl.x;
    int Py = pl.y;

    // Inisialisasi papan
    Petak papan[N][N];

    for(i=0;i<N;++i) {
        for(j=0;j<N;++j) {
            papan[i][j].status = 'O';
        }
    }

    // Tampilan papan
    printf("");
}

void History(Player pl) {

}

void tampilMisc(Player pl) {

}

void Move(Player pl, Petak pp){

}

void giveHint(Player pl, Petak pp){

}

void saveToLB(Player pl){

}