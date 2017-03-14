#pragma once
#include"map.h"
#include<conio.h>

enum tankDir
{
	up, down, left, right
};

typedef struct _TANK {
	unsigned int nBuildType = 0;
	unsigned int nTankType	= 0;
	unsigned int nDiretion	= 0;
	unsigned int nX			= 0;
	unsigned int nY			= 0;
}TANK;

TANK *tank();

void printTank(TANK *myTank);
void moveTank(TANK *myTank);
void clearTank(TANK *myTank);