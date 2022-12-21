#include "gameplay.h"
#include "mainmenu.h"
#include "howtoplay.h"
#include "highscore.h"
#include <stdio.h>




int main(){

    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED); //Mengubah tampilan cmd agar fullscreen
    hideCursor(); //Menyembunyikan cursor
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
            system("cls");
            howtoplay();
            system("pause");
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
