// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>
#include"map.h"
#include"windowsSet.h"
#include"Print.h"
#include"tank.h"

int main()
{
	TANK *myTank = tank();
	//SetConsoleTitle(L"坦克大战");
	setWindwosSize("坦克大战", 120, 160);
	//printBound();
	drawMap();
	printTank(myTank);
	//intTank(myTank);
	moveTank(myTank);
	
	system("pause");
    return 0;
}
