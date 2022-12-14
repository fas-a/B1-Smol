#include "gameplay.h"
#define N 8

/*
Now for papan, I need some unicode to print the edge, how...

OK found some unicode for box shape from here
https://www.w3.org/TR/xml-entity-names/025.html

This doesn't work

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

We will use this instead
 _______________________________________________
|-----|-----|-----|-----|-----|-----|-----|-----|
|     |     |     |     |     |     |     |     |
|-----|-----|-----|-----|-----|-----|-----|-----|


KK and XX are subject to be changed
*/

// File manipulation

FILE *frec;

// Inisialisasi papan
Petak papan[N][N];
Petak eks[N][N];
int xX,xY;
int iX, iY;
int hX = 70;
int hY = 5;
int wkt;

void PlayGame(Player pl) {
    // Hide cursor
    printf("\33[?25l");
    int i,j;
    system("cls");

    for(i=0;i<N;++i) {
        for(j=0;j<N;++j) {
            papan[i][j].status = 'O';
        }
    }
    initializePlayer(&pl);

    // Hitung mundur
    int x;
    for (x=5;x>=1;--x) {
        gotoxy(15,2);
        printf("Permainan di mulai dalam : %d", x);
        Sleep(1000);
    }
    gotoxy(15,2);
    printf("                                              ");

    tampilMisc(pl);
    fflush(stdin);
    Move(&pl);

    for(i=0;i<N;++i) {
        for(j=0;j<N;++j) {
            eks[i][j].status = 'O';
        }
    }
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

    papan[Px][Py].status = 'P';

    // Tampilan papan
    gotoxy(15,5);
    printf(" _______________________________________________");
    for (i=7;i<=21;i+=2) {
        gotoxy(15,i);
        printf("|-----|-----|-----|-----|-----|-----|-----|-----|");
    }
    int x=0;
    int y;
    for (i=6;i<6+(N*2-1);i+=2){
        y = 0;
        gotoxy(15,i);
        printf("|     |     |     |     |     |     |     |     |");
        for (j=3;j<3+(N*6-1);j+=6) {
            gotoxy(15+j,i);
            if (papan[x][y].status=='O') printf("");
            else if (papan[x][y].status=='X') printf("X");
            else if (papan[x][y].status=='H') printf("H");
            else if (papan[x][y].status=='P') printf("O");
            else printf("?");
            y++;
        }
        x++;
    }
    fflush(stdin);
}

void initializePlayer(Player *pl) {
    int x,y;
    do {
        gotoxy(15,2);
        printf("                                                   ");
        gotoxy(15,2);
        printf("Masukkan koordinat petak pertama (x,y) = ");
        scanf("%d %d", &x, &y);
        fflush(stdin);
        if (x<1 || x>8 || y<1 || y>8) {
            gotoxy(15,3);
            printf("Masukkan koordinat yang tepat");
        }
    } while (x<1 || x>8 || y<1 || y>8);
    
    gotoxy(15,3);
    printf("Masukkan waktu batas tiap gerakan (dalam detik) = ");
    scanf("%d", &wkt);
    fflush(stdin);
    pl->x = y-1;
    pl->y = x-1;
    iX = pl->x;
    iY = pl->y;
    pl->skor = 0;
    system("cls");
    tampilPapan(*pl);
}

void tampilMisc(Player pl) {
    gotoxy(15,23);
    printf("Skor = %d", pl.skor);
}

/*
Validasi

1. possible move
x+1,y+2 
x-1,y+2 
x+2,y+1
x+2,y-1
x+1,y-2
x-1,y-2
x-2,y-1
x-2,y+1

2. array out of bound
1>=x>=8 atau 1>=y>=8
*/

bool validate(int ix, int iy, int x, int y) {
    int i;
    int possibleMove[8][2] = {{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
    for (i=0;i<8;++i) {
        if (ix+possibleMove[i][0]==x && iy+possibleMove[i][1]==y) {
            return true;
        }
    }
    return false;
}

// True : lanjut
// False : kalah

bool evaluate(int x, int y) {
    int i;
    int n=0;
    int possibleMove[8][2] = {{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
    for (i=0;i<8;++i) {
        if (x+possibleMove[i][0]>=0 && x+possibleMove[i][0]<=7 && y+possibleMove[i][1]>=0 && y+possibleMove[i][1]<=7) {
            if (eks[x+possibleMove[i][0]][y+possibleMove[i][1]].status!='X') {
                return true;
            } 
        }
    }
    return false;
}

void History() {
    if (hY==25){
        hY=5;
        hX+=11;
    }
    gotoxy(hX, hY);
    printf("X: %d Y: %d",iY+1, iX+1);
    hY++;
}

void Move(Player *pl){
    int x,y;
    bool beres = false;
    bool menang;
    do { 
        time_t start_time = clock();
        for( ;clock() - start_time <= wkt*CLOCKS_PER_SEC; )
        {   
            gotoxy(15,3);
            printf("Timer : %d", (clock()-start_time)/1000);
            if(kbhit() > 0)  // some key is pressed
            {
                x = pl->x;
                y = pl->y;
                char c = getch();
                switch(c) { // the real value
                    case '\r':
                        if (!validate(iX,iY,x,y) || eks[x][y].status=='X') {
                            gotoxy(15, 4);
                            printf("Ini bukan langkah kuda yang valid!");
                        } else {
                            papan[iX][iY].status = 'X';
                            eks[iX][iY].status = 'X';

                            History();

                            gotoxy(15, 3);
                            printf("                                     ");
                            gotoxy(15, 4);
                            printf("                                     ");

                            iX = x;
                            iY = y;

                            pl->skor+=1;
                            if(pl->skor==64) {
                                beres = true;
                                goto next_loop;
                            }

                            fflush(stdin);

                            papan[x][y].status = 'O';
                            papan[iX][iY].status = 'H';
                            if (!evaluate(x,y)) beres = true;

                            tampilPapan(*pl);
                            tampilMisc(*pl);

                            goto next_loop;
                        }
                        break;
                    case 72:
                        if (pl->x-1>=0) {
                            pl->x-=1;
                            papan[pl->x][pl->y].status = 'P';
                            break;
                        } else break;
                    case 80:
                        if (pl->x+1<=7) {
                            pl->x+=1;
                            papan[pl->x][pl->y].status = 'P';
                            break;
                        } else break;
                    case 77:
                        if (pl->y+1<=7) {
                            pl->y+=1;
                            papan[pl->x][pl->y].status = 'P';
                            break;
                        } else break;
                    case 75:
                        if (pl->y-1>=0) {
                            pl->y-=1;
                            papan[pl->x][pl->y].status = 'P';
                            break;
                        } else break;
                }
                fflush(stdin);

                papan[x][y].status = 'O';
                papan[iX][iY].status = 'H';

                if (eks[x][y].status=='X') papan[x][y].status = 'X';

                tampilPapan(*pl);
                tampilMisc(*pl);
            }
        }
        menang = false;
        beres = true;
        next_loop: ;
    } while(!beres);
    if (!menang) {
        gotoxy(15,2);
        printf("                                              ");
        gotoxy(15,3);
        printf("                                              ");
        gotoxy(15,2);
        printf("Anda kalah, wek");
    } else {
        gotoxy(15,2);
        printf("                                              ");
        gotoxy(15,3);
        printf("                                              ");
        gotoxy(15,2);
        printf("Anda menang, yey");
    }
    gotoxy(15,3);
        printf("Masukkan nama : ");
        int i;
        for (i=0;i<3;i++) {
            pl->nama[i] = getch();
            printf("%c", pl->nama[i]);
        }
        saveToLB(*pl);
}

void saveToLB(Player pl){
    Player tPl;
    if ((frec=fopen("hs.dat","ab+"))!=NULL) {
        // buka file,mode append dalam format biner
        tPl.x = pl.x;
        tPl.y = pl.y;
        tPl.skor = pl.skor;
        int i;
        strcpy(tPl.nama, pl.nama);
        fwrite(&tPl,sizeof(tPl),1,frec);
    }
    fclose(frec);
}
