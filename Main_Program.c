#include "gameplay.h"
#include "mainmenu.h"
#include <stdio.h>




int main(){
    //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    //hideCursor();
    printf("\33[?25l");
    renderLogo();
    int opsi;
    opsi = PilihMenu();
    while(opsi != 4){
        switch (opsi)
        {
        case 1:
            Player pl;
            pl = (Player) {0,0,0,""};
            PlayGame(pl);
            break;
        case 2:
            printf("Modul How to Play");
            break;
        case 3:
            system("cls");
            TampilHighscore();
            system("pause");
            break;
        case 4:
            system("quit");
            break;
        default:
            break;
        }
        system("cls");
        TampilLogo();
        opsi = PilihMenu();
    }
    
    return 0;
}
