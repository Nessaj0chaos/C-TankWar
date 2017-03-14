#pragma once
#include"map.h"
#include<Windows.h>

//湖荂晚賜
void printBound()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("←←←←←←←←←←←←←←←←←←←←←←←←←←←←←← |姆姆姆姆姆姆姆姆姆姆姆姆姆|\n");
	for (int i = 0; i<13; i++)
		printf("←                                                        ← |                          |\n");
	printf("←                                                        ← |--------------------------|\n");
	for (int j = 14; j<28; j++)
		printf("←                                                        ← |                          |\n");
	printf("←←←←←←←←←←←←←←←←←←←←←←←←←←←←←← |始始始始始始始始始始始始始|\n");
}