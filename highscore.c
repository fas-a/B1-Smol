#include "highscore.h"


/*
Deskripsi	: Modul untuk menampilkan fitur Highscore dimana menampilkan score pemain pemain sebelumnya.
I.S	: Tampilan fitur Highscore belum tampil
F.S	: Tampilan fitur Highscore sudah tampil
*/
void TampilHighscore(){
    int m;
    Player a;
    FILE *frec;
    Sort_file();
    renderLogoHighscore();
    printf("\t\t\t\t\t\tNAMA\t |\tScore\n");
    if ((frec = fopen ("hs.dat", "rb"))==NULL) {
        printf("Error opening");
    } else {
        m = fread(&a, sizeof(a), 1, frec);
        while (m!=0) {
            displayhighscore(a);
            m = fread(&a, sizeof(a), 1, frec);
        }
    }
    fclose(frec);
}

/*
Deskripsi	: Modul untuk menampilkan Nama dan score pemain dari data Player a.
I.S	: Nama dan score pemain dari data Player a belum tampil
F.S	: Nama dan score pemain dari data Player a tampil
*/
void displayhighscore(Player a){
    printf("\t\t\t\t\t\t %s\t |\t %i\n", a.nama,a.skor);
}

/*
Deskripsi	: Modul untuk mengurutkan data pada file hs.dat dari yang terbesar sampai yang terkecil menurut score.
I.S	: Data belum terurut
F.S	: Data sudah terurut
*/
void Sort_file()
{
    FILE *f_rec;
    long i = 0, j,a;
    Player dt, Temp;
    int b;
    a = cekdata();
    f_rec = fopen("hs.dat", "rb+");
    while (i<a)
    {
        fseek(f_rec, i * 16, SEEK_SET);
        fread(&dt, sizeof(dt), 1, f_rec);
        b = sizeof(dt);
        j = i;
        while (j<a)
        {
            j++;
            fseek(f_rec, j * 16 , SEEK_SET);
            fread(&Temp, sizeof(Temp), 1, f_rec);
            if(dt.skor < Temp.skor){
                fseek(f_rec, i * 16, SEEK_SET);
                fwrite(&Temp,sizeof(Temp),1,f_rec);
                fseek(f_rec, j * 16, SEEK_SET);
                fwrite(&dt,sizeof(dt),1,f_rec);
                strcpy(dt.nama, Temp.nama);
                dt.skor = Temp.skor;
            }
        }
        if (i < j)
        {
            fseek(f_rec, 0, SEEK_SET);
            i++;
        }
    }
    fclose(f_rec);
}

/*
Deskripsi	: Modul untuk mengembalikan nilai jumlah dari banyaknya data Player yang ada pada file hs.dat
*/
int cekdata(){
    int m,jumlah;
    Player a;
    FILE *frec;
    if ((frec = fopen ("hs.dat", "rb"))==NULL) {
        printf("Error opening");
    } else {
        m = fread(&a, sizeof(a), 1, frec);
        jumlah = 1;
        while (m!=0) {
            m = fread(&a, sizeof(a), 1, frec);
            jumlah++;
        }
    }
    fclose(frec);
    return jumlah - 2;
}

/*
Deskripsi	: Modul untuk menampilkan title HIGHSCORE.
I.S	: title belum tampil
F.S	: title sudah tampil
*/
void renderLogoHighscore()
{
// =======================================================================================
// |  _     _    _     _____    _     _     _____    ______    ______    _____    _____  |
// | / \   / \  / \   / ____|  / \   / \   /  ___\  /  ____\  /  __  \  |  _  \  |  ___| |
// | | |___| |  | |  / /  ___  | |___| |   | |___   | |       | |  | |  | |_) /  | |__   |
// | |  ___  |  | |  | | |_  \ |  ___  |   \___  \  | |       | |  | |  |    /   |  __|  |
// | | |   | |  | |  \ \___/ / | |   | |   ____| |  | |_____  | |__| |  | |\ \   | |___  |
// | \_/   \_/  \_/   \_____/  \_/   \_/   \_____/  \______/  \______/  |_| \_\  |_____| |
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

 char titletext[][90] = {"\t\t=======================================================================================",
                         "\t\t|  _     _    _     _____    _     _     _____    ______    ______    _____    _____  |",
                         "\t\t| / \\   / \\  / \\   / ____|  / \\   / \\   /  ___\\  /  ____\\  /  __  \\  |  _  \\  |  ___| |",
                         "\t\t| | |___| |  | |  / /  ___  | |___| |   | |___   | |       | |  | |  | |_) /  | |__   |",
                         "\t\t| |  ___  |  | |  | | |_  \\ |  ___  |   \\___  \\  | |       | |  | |  |    /   |  __|  |",
                         "\t\t| | |   | |  | |  \\ \\___/ / | |   | |   ____| |  | |_____  | |__| |  | |\\ \\   | |___  |",
                         "\t\t| \\_/   \\_/  \\_/   \\_____/  \\_/   \\_/   \\_____/  \\______/  \\______/  |_| \\_\\  |_____| |",
                         "\t\t======================================================================================="};

    gotoxy(0,0);
   for (int j = 0; j < 8; j++)
   {
    for(int k = 0; k <= 87; k++){
        printf("%c", titletext[j][k]);
    }
    printf("\n");
   }
}

