#include "mainmenu.h"

int PilihMenu(){
  int position = 1;
    int keypress = 0;
    
    while(keypress != 13){
        gotoxy(30,10); arrowhere(1, position); printf(" Play \n");
        gotoxy(30,11); arrowhere(2, position); printf(" How To Play \n");
        gotoxy(30,12); arrowhere(3, position); printf(" Highscore \n");
        gotoxy(30,13); arrowhere(4, position); printf(" Exit \n");
        keypress = getch();
        fflush(stdin);
        if(keypress == 80){
            if(position == 4) position = 1;
            else position++;
        }
        else if (keypress == 72){
            if(position == 1) position = 4;
            else position--;
        }
    }
    return position;
}

void arrowhere(int realPosition, int arrowPosition){
    if(realPosition == arrowPosition) printf("  ---->> ");
    else printf("        ");
}

void delay(int ms)
{
  Sleep(ms);
}

void renderLogo()
{
//  _   _      _        _     _   _       _____ 
// | | / /    (_)      | |   | | ( )     |_   _|
// | |/ / _ _   _  __ _| |__ | |_|/ ___    | | ___  _   _ _ __ 
// |    \| '_ \| |/ _` | '_ \| __| / __|   | |/ _ \| | | | '__|
// | |\  \ | | | | (_| | | | | |_  \__ \   | | (_) | |_| | |
// \_| \_/_| |_|_|\__, |_| |_|\__| |___/   \_/\___/ \__,_|_|
//                 __/ |
//                |___/
 char titletext[][80] = {"             _   _      _        _     _   _       _____                    ",
                         "            | | / /    (_)      | |   | | ( )     |_   _|                   ",
                         "            | |/ / _ _   _  __ _| |__ | |_|/ ___    | | ___  _   _ _ __     ",
                         "            |    \\| '_ \\| |/ _` | '_ \\| __| / __|   | |/ _ \\| | | | '__|    ",
                         "            | |\\  \\ | | | | (_| | | | | |_  \\__ \\   | | (_) | |_| | |       ",
                         "            \\_| \\_/_| |_|_|\\__, |_| |_|\\__| |___/   \\_/\\___/ \\__,_|_|       ",
                         "                            __/ |                                           ",
                         "                           |___/                                            "};
 for (int i = 0; i <= 76; i++)
 {
   gotoxy(0, 0);
   for (int j = 0; j < 8; j++)
   {
    for(int k = 0; k <= i; k++){
        printf("%c", titletext[j][k]);
    }
    printf("\n");
   }
   delay(5);
 }
}

void TampilLogo(){
   char titletext[][80] = {"             _   _      _        _     _   _       _____                    ",
                         "            | | / /    (_)      | |   | | ( )     |_   _|                   ",
                         "            | |/ / _ _   _  __ _| |__ | |_|/ ___    | | ___  _   _ _ __     ",
                         "            |    \\| '_ \\| |/ _` | '_ \\| __| / __|   | |/ _ \\| | | | '__|    ",
                         "            | |\\  \\ | | | | (_| | | | | |_  \\__ \\   | | (_) | |_| | |       ",
                         "            \\_| \\_/_| |_|_|\\__, |_| |_|\\__| |___/   \\_/\\___/ \\__,_|_|       ",
                         "                            __/ |                                           ",
                         "                           |___/                                            "};

   gotoxy(0, 0);
   for (int j = 0; j < 8; j++)
   {
    for(int k = 0; k <= 76; k++){
        printf("%c", titletext[j][k]);
    }
    printf("\n");
   
 }
}

void hideCursor()
{
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &info);
}
