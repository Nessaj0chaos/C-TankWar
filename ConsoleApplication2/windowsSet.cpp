#include "stdafx.h"
#include "windowsSet.h"

bool setWindwosSize(char * pszWindowsTitle, int nX, int nY)
{
	//���ÿ���̨�ı���
	SetConsoleTitleA(pszWindowsTitle);
	HANDLE hstdIn, hstdOut;
	hstdIn = GetStdHandle(STD_INPUT_HANDLE);
	hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ������̨���ڴ�С
	COORD pos = GetLargestConsoleWindowSize(hstdOut);
	COORD buffSize = { pos.X + 1,pos.Y + 1 };
	//���ÿ���̨�������Ĵ�С
	if (!SetConsoleScreenBufferSize(hstdOut, buffSize)) {
		//���ÿ���̨������ʧ��
		printf("Buffer err(%d,%d) %d\n", buffSize.X, buffSize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0,0,nX,nY };
	if (!SetConsoleWindowInfo(hstdOut, true, &srctWindow)) {
		//���ÿ���̨���ڴ�Сʧ��
		printf("size err%d \n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1,nY + 1 };
	if (!SetConsoleScreenBufferSize(hstdOut, Buffer)) {
		//���ÿ���̨���ڴ�Сʧ��
		printf("buffer err (%d,%d)%d\n", buffSize.X, buffSize.Y, GetLastError());
		return false;
	}
	return true;
}
