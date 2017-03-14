#include "stdafx.h"
#include<stdio.h>
#include "tank.h"

extern int g_nMap[40][40];
//̹�˵Ľṹ��
TANK * tank()
{
	TANK *myTank = (TANK*)malloc(sizeof(TANK));
	myTank->nX = 38;
	myTank->nY = 9;
	myTank->nDiretion = up;
	return myTank;
}
//����̹�ˡ�
void printTank(TANK *myTank)
{
	if ((*myTank).nDiretion == up) {
		writeChar((*myTank).nX, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if ((*myTank).nDiretion == down) {
		writeChar((*myTank).nX, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if ((*myTank).nDiretion == left) {
		writeChar((*myTank).nX, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if ((*myTank).nDiretion == right) {
		writeChar((*myTank).nX, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX, (*myTank).nY + 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX + 1, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeChar((*myTank).nX - 1, (*myTank).nY - 1, "��", FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
}
//̹�˵��ƶ�����
void moveTank(TANK *myTank)
{
	while (true)
	{

		if (_kbhit) {
			char key = _getch();
			switch (key)
			{
			case 'w':
			{
				if ((*myTank).nX > 1) {
					clearTank(myTank);
					if ((*myTank).nDiretion == up) {
						if (g_nMap[(*myTank).nX - 2][(*myTank).nY ] == 0 &&
							g_nMap[(*myTank).nX - 2][(*myTank).nY - 1] == 0 &&
							g_nMap[(*myTank).nX - 2][(*myTank).nY + 1] == 0) {	//��ǰ��������Ҫ�˶��ķ���ͬ
																				//ͨ���ж�̹�˵ķ����ǲ����˶��ķ���ͬ��
							(*myTank).nX -= 1;									//���ͬ��̹�˵����귢���仯
						}
					}
					(*myTank).nDiretion = up;									//����Ҫ�˶��ķ���ֵ��myTank.nDirection
					printTank(myTank);
				}
			
			}
			break;
			case 's':
			{
				if ((*myTank).nX < 38) {
					clearTank(myTank);
					if ((*myTank).nDiretion == down) {
						if (g_nMap[(*myTank).nX + 2][(*myTank).nY - 1] == 0 &&
							g_nMap[(*myTank).nX + 2][(*myTank).nY + 1] == 0 &&
							g_nMap[(*myTank).nX + 2][(*myTank).nY] == 0) {
							(*myTank).nX += 1;
						}
					}
					(*myTank).nDiretion = down;
					printTank(myTank);
				}
			}
			break;
			case 'a':
			{
				if ((*myTank).nY > 1) {
					clearTank(myTank);
					if ((*myTank).nDiretion == left) {
						
					
						if (g_nMap[(*myTank).nX][(*myTank).nY - 2] == 0 &&
							g_nMap[(*myTank).nX + 1][(*myTank).nY - 2] == 0 &&
							g_nMap[(*myTank).nX - 1][(*myTank).nY - 2] == 0) {
							(*myTank).nY -= 1;
						}
					}
					(*myTank).nDiretion = left;
					printTank(myTank);
				}
			}
			break;
			case 'd':
			{
				if ((*myTank).nY < 38) {
					clearTank(myTank);
					if ((*myTank).nDiretion == right) {
						if (g_nMap[(*myTank).nX][(*myTank).nY + 2] == 0 &&
							g_nMap[(*myTank).nX - 1][(*myTank).nY + 2] == 0 &&
							g_nMap[(*myTank).nX + 1][(*myTank).nY + 2] == 0) {
							(*myTank).nY += 1;
						}
					}
					(*myTank).nDiretion = right;
					printTank(myTank);
				}
			}
			default:
				break;
			}
			//printf("%d,%d", (*myTank).nX, (*myTank).nY);
		}

	}
}
//����˶�֮ǰ��̹��
void clearTank(TANK *myTank)
{
	writeChar((*myTank).nX - 1, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX - 1, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX - 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX + 1, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX + 1, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
	writeChar((*myTank).nX + 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
}
//void clearTank(TANK *myTank)
//{
//	if ((*myTank).nDiretion == up) {
//		writeChar((*myTank).nX, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//
//	}
//	if ((*myTank).nDiretion == down) {
//		writeChar((*myTank).nX, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//	}
//	if ((*myTank).nDiretion == left) {
//		writeChar((*myTank).nX, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//	}
//	if ((*myTank).nDiretion == right) {
//
//		writeChar((*myTank).nX, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY + 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX + 1, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX - 1, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//		writeChar((*myTank).nX, (*myTank).nY - 1, "  ", FOREGROUND_INTENSITY);
//	}
//}