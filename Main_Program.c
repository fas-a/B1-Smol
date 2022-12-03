#include<stdio.h>
#include<stdbool.h>

#define QUIT 99

//Masukin ke representating file nanti
typedef struct {
    int mm;
    int ss;
}Waktu;

typedef struct {
    int x;
    int y;
    bool hint;
    char nama[3];
    Waktu wkt;
    int score;
}Player;

typedef struct {
    int x;
    int y;
    char status;
}Petak;

typedef struct {
    char nama[3];
    int score;
    Waktu time;
}Highscore;

void TampilMenu();
/*

*/

int PilihMenu();
/*

*/

void TampilPapan(Player pl);
/*

*/

void TampilHighscore();
/*

*/

void PlayGame();
/*

*/

void SetPosition();
/*

*/

void Move();
/*

*/

void Hint();
/*

*/

void HowToPlay();
/*

*/

int main(){
    Player pl;
    pl.hint = false;
    int opsi;
    
    TampilMenu(pl);
    do {
        opsi = PilihMenu();
        if(opsi==1) {
            PlayGame();
        } else if(opsi==2) {
            HowToPlay();
        } else if(opsi==3) {
            TampilHighscore();
        } else if(opsi==4) {
            //toggle hint
            pl.hint = !pl.hint;
            system("cls");
            TampilMenu(pl.hint);
        }
    } while(opsi!=QUIT);
    
    return 0;
}
