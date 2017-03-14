#include "stdafx.h"
#include "windowsSet.h"

bool setWindwosSize(char * pszWindowsTitle, int nX, int nY)
{
	//设置控制台的标题
	SetConsoleTitleA(pszWindowsTitle);
	HANDLE hstdIn, hstdOut;
	hstdIn = GetStdHandle(STD_INPUT_HANDLE);
	hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//获取最大控制台窗口大小
	COORD pos = GetLargestConsoleWindowSize(hstdOut);
	COORD buffSize = { pos.X + 1,pos.Y + 1 };
	//设置控制台缓冲区的大小
	if (!SetConsoleScreenBufferSize(hstdOut, buffSize)) {
		//设置控制台缓冲区失败
		printf("Buffer err(%d,%d) %d\n", buffSize.X, buffSize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0,0,nX,nY };
	if (!SetConsoleWindowInfo(hstdOut, true, &srctWindow)) {
		//设置控制台窗口大小失败
		printf("size err%d \n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1,nY + 1 };
	if (!SetConsoleScreenBufferSize(hstdOut, Buffer)) {
		//设置控制台窗口大小失败
		printf("buffer err (%d,%d)%d\n", buffSize.X, buffSize.Y, GetLastError());
		return false;
	}
	return true;
}
