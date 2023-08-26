﻿#include <Windows.h>
#include <stdio.h>

void GotoXY(int _x, int _y) 
{
	COORD pos = { _x * 2, _y };


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서의 x, y위치를 알려주는 함수
COORD GetXY(void) 
{
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO curInfor;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	pos.X = curInfor.dwCursorPosition.X;
	pos.Y = curInfor.dwCursorPosition.Y;

	return pos;
}
//화면을 지우는 함수
void Clear(void) {
	system("cls");
}
//타이틀을 변경하는 함수
void SetTitle(char* _szConsoleName) {
	SetConsoleTitle(_szConsoleName);
}
// 글자색, 배경색을 변경하는 함수
void SetColor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;
	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

//커서를 보이게 하거나 (TRUE) 보이지 않게 하는 함수(FALSE)
void SetCursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	curInfor.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
}

