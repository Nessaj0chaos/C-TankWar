#pragma once
#include"map.h"
#include<Windows.h>

//��ӡ�߽�
void printBound()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("������������������������������������������������������������ |�i�i�i�i�i�i�i�i�i�i�i�i�i|\n");
	for (int i = 0; i<13; i++)
		printf("��                                                        �� |                          |\n");
	printf("��                                                        �� |--------------------------|\n");
	for (int j = 14; j<28; j++)
		printf("��                                                        �� |                          |\n");
	printf("������������������������������������������������������������ |�l�l�l�l�l�l�l�l�l�l�l�l�l|\n");
}