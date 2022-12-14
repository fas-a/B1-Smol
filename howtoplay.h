#ifndef HOWTOPLAY_H_
#define HOWTOPLAY_H_
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);

void howtoplay();

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

int Demo();

int isSafe(int x, int y, int sol[N][N]);

void TampilSol(int sol[N][N]);

void gotoxy(int x, int y);

#endif // HOWTOPLAY_H_

