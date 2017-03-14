#include"stdafx.h"
#include"map.h"
#include<stdio.h>
#include<Windows.h>
extern int g_nMap[40][40];

//int g_nMap[40][40] = { 0 };
//extern int g_nMap[40][40];
//void writeChar(int High, int Wide, char* pszChar, WORD wArr);
void drawMap()
{
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			if (g_nMap[i][j] == 1) {
				writeChar(i, j, "①", BACKGROUND_GREEN);
			}
			else if (g_nMap[i][j] == 2) {
				writeChar(i, j, "≡", BACKGROUND_RED);
			}
			else if (g_nMap[i][j] == 4) {
				writeChar(i, j, "▓", BACKGROUND_BLUE);
			}
			else
			{
				writeChar(i, j, "  ", FOREGROUND_INTENSITY);
			}
		}
	}
}
void writeChar(int High, int Wide, char* pszChar, WORD wArr)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(pszChar);
}