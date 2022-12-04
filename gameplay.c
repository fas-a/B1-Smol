#include "gameplay.h"
#define N 8

/*
Now for papan, I need some unicode to print the edge, how...

OK found some unicode for box shape from here
https://www.w3.org/TR/xml-entity-names/025.html

Ex:
┏━━━━━┓
┃  X  ┃
┣━━━━━┫
┃  K  ┃
┗━━━━━┛

Ex2:
┏━━━━━━━━┓
┃   XX   ┃
┃   XX   ┃
┣━━━━━━━━┫
┃   KK   ┃
┃   KK   ┃
┗━━━━━━━━┛

KK and XX are subject to be changed
*/

void PlayGame(Player pl) {
    system("clear");
    tampilPapan(pl);
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
    // Inverted because I like the x to be vertically and y to be horizontally
    // Also use 2:1 ratio pls idk why but yeah lmao google it
}

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
    gotoxy(15,7);
    printf("┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓");
    gotoxy(15,9);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,11);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,13);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,15);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,17);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,19);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,21);
    printf("┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫");
    gotoxy(15,23);
    printf("┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛");
    int x=0;
    int y;
    for (i=8;i<8+(N*2-1);i+=2){
        y = 0;
        gotoxy(15,i);
        printf("┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃");
        for (j=3;j<3+(N*6-1);j+=6) {
            gotoxy(15+j,i);
            if (papan[x][y].status=='O') printf("");
            else if (papan[x][y].status=='X') printf("X");
            else if (papan[x][y].status=='H') printf("H");
            else if (papan[x][y].status=='P') printf("K");
            else printf("?");
            y++;
        }
        x++;
    }
    gotoxy(0,26);
    fflush(stdin);
    getchar();
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