#include <stdio.h>
#include <Windows.h>

#include "Console.h"

#define MAX_KAN 15			//바둑판 크기
#define MAX 255				//바둑알 개수
#define START_X MAX_KAN / 2	//돌의 시작 위치 X
#define START_Y MAX_KAN / 2	//돌의 시작 위치 Y
#define WIDTH 0				//가로
#define LENGTH 1			//세로
#define DIAGONAL 3			//오른쪽 아래 대각선
#define DIAGONAL_1 4		//왼쪽 아래 대각선

int now_X, now_Y;			//현재 위치
int k = 0;					//놓은 돌의 개수

int Blackcount = 0;			//흑돌의 개수
int Whitecount = 0;			//백돌의 개수
void GameStartmenu()		//현재 위치를 시작 위치로 변경 함수 (1회 실행)
{
	now_X = START_X;
	now_Y = START_Y;
}
int Board[MAX_KAN][MAX_KAN] = {						//오목판
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

void DrawInit() //오목판 그리기
{
	GotoXY(0, 0);
	SetColor(6, 0);
	for (int i = 0; i < MAX_KAN; i++)
	{
		for (int j = 0; j < MAX_KAN; j++)
		{
			GotoXY(j, i);
			if (i == 0)
			{
				if (j == 0)
				{
					printf("┌─");
				}
				else if (j == MAX_KAN - 1)
				{
					printf("┐ ");
				}
				else
				{
					printf("┬─");
				}
			}
			else if (j == 0)
			{
				if (i == MAX_KAN - 1)
				{
					printf("└─");
				}
				else
				{
					printf("├─");
				}
			}
			else if (j == MAX_KAN - 1)
			{
				if (i == MAX_KAN - 1)
				{
					printf("┘ ");
				}
				else
				{
					printf("┤ ");
				}
			}
			else if (i == MAX_KAN - 1)
			{
				printf("┴─");
			}
			else
			{
				printf("┼─");
			}
		}
		printf("\n");
	}
}
//오목 렌주룰
bool Renju_Rule()
{
	int Renju_Count = 0;

	if (Board[now_Y][now_X] == 1)
	{
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] == 1 && Board[now_Y][now_X + 3] != 2 && Board[now_Y][now_X + 4] != 2) //현재 둔곳이 왼쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] != 1 && Board[now_Y + 4][now_X] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] != 1 && Board[now_Y - 4][now_X] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}	
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] == 1 && Board[now_Y][now_X - 3] != 2 && Board[now_Y][now_X - 4] != 2) //현재 둔곳이 오른쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] != 1 && Board[now_Y - 4][now_X] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] != 1 && Board[now_Y + 4][now_X] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y][now_X + 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] != 1 && Board[now_Y + 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] != 2 && Board[now_Y - 4][now_X] != 2) //현재 돌을 아래에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] != 1 && Board[now_Y + 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] != 2 && Board[now_Y + 4][now_X] != 2) //현재 돌을 위에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] !=2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] != 1 && Board[now_Y + 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1 && Board[now_Y - 4][now_X + 4] != 2) //오른쪽 위 방향 아래
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] != 1 && Board[now_Y + 4][now_X - 4] != 2) //오른쪽 위 방향 위
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1 && Board[now_Y - 4][now_X - 4] != 2 )
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] != 1 && Board[now_Y][now_X + 3] == 1 && Board[now_Y][now_X + 4] != 2) //현재 둔곳이 왼쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] != 1 && Board[now_Y + 4][now_X] == 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] != 1 && Board[now_Y - 4][now_X] == 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] != 1 && Board[now_Y][now_X - 3] == 1 && Board[now_Y][now_X - 4] != 2) //현재 둔곳이 오른쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1 && Board[now_Y - 4][now_X] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1 && Board[now_Y + 4][now_X] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y][now_X + 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1 && Board[now_Y + 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1 && Board[now_Y - 4][now_X] != 2) //현재 돌을 아래에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1 && Board[now_Y + 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1 && Board[now_Y + 4][now_X] != 2) //현재 돌을 위에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1 && Board[now_Y - 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1 && Board[now_Y + 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] != 1 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1 && Board[now_Y - 4][now_X + 4] != 2) //오른쪽 위 방향 아래
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X - 1] != 2 && Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1 && Board[now_Y + 4][now_X + 4] != 2)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] != 2 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1 && Board[now_Y - 4][now_X - 4] != 2)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1) //오른쪽 위 방향 위
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] != 1 && Board[now_Y][now_X + 3] == 1) //현재 둔곳이 왼쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] != 1 && Board[now_Y][now_X - 3] == 1) //현재 둔곳이 오른쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1) //현재 돌을 아래에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] != 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1) //현재 돌을 위에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] != 1 && Board[now_Y][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] != 1 && Board[now_Y][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1) //오른쪽 위 방향 아래
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1) //오른쪽 위 방향 위
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] != 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] != 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X - 1] == 1 && Board[now_Y + 1][now_X] == 1 && Board[now_Y - 1][now_X] == 1) //ㅁ모양
		{
			Board[now_Y][now_X] = 0;
			GotoXY(40, 20);
			printf("렌주룰에 걸립니다.");
			k--;
			return true;
		}
		if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 1][now_X + 1] == 1) // +모양 
		{
			Board[now_Y][now_X] = 0;
			GotoXY(40, 20);
			printf("렌주룰에 걸립니다.");
			k--;
			return true;
		}
		if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] == 1 && Board[now_Y][now_X + 3] == 1) //현재 둔곳이 왼쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] == 1 && Board[now_Y][now_X - 3] == 1) //현재 둔곳이 오른쪽 일 때
		{
			Renju_Count++;
			if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] == 1) //현재 돌을 아래에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] != 1) //현재 돌을 위에 두었을 때
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] != 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] != 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] != 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] == 1) //오른쪽 위 방향 아래
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] == 1) //오른쪽 위 방향 위
		{
			Renju_Count++;
			if (Board[now_Y + 1][now_X + 1] == 1 && Board[now_Y + 2][now_X + 2] == 1 && Board[now_Y + 3][now_X + 3] == 1)
			{
				Renju_Count++;
			}
			if (Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y - 2][now_X - 2] == 1 && Board[now_Y - 3][now_X - 3] == 1)
			{
				Renju_Count++;
			}
			if (Renju_Count >= 2)
			{
				Board[now_Y][now_X] = 0;
				GotoXY(40, 20);
				printf("렌주룰에 걸립니다.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
	}

}
//좌표 저장
int SaveXY()
{
	if (Board[now_Y][now_X] == 0)
	{
		if (k % 2 == 0)
		{
			Board[now_Y][now_X] = 1;
			Blackcount++;
		}
		if (k % 2 == 1)
		{
			Board[now_Y][now_X] = 2;
			Whitecount++;
		}
		return 1;
	}
}
//이동
void Move() //예비 돌 출력 / 움직이기
{	
	SetColor(6, 0);
	GotoXY(now_X, now_Y);
	if (now_X == 0 && now_Y == 0)
	{
		printf("┌");
		printf(" ");
	}
	else if (now_X != 0 && now_X != MAX_KAN - 1 && now_Y == 0)
	{
		printf("┬");
		printf(" ");
	}
	else if (now_X == 0 && now_Y != 0 && now_Y != MAX_KAN - 1)
	{
		printf("├");
		printf(" ");
	}
	else if (now_X == 0 && now_Y == MAX_KAN - 1)
	{
		printf("└─");
		printf(" ");
	}
	else if (now_X == MAX_KAN - 1 && now_Y == 0)
	{
		printf("┐");
		printf(" ");
	}
	else if (now_Y == MAX_KAN - 1 && now_X != 0 && now_X != MAX_KAN - 1)
	{
		printf("┴");
		printf(" ");
	}
	else if (now_X == MAX_KAN - 1 && now_Y == MAX_KAN - 1)
	{
		printf("┘");
		printf(" ");
	}
	else if (now_Y != MAX_KAN - 1 && now_X == MAX_KAN - 1 && now_Y != 0)
	{
		printf("┤");
		printf(" ");
	}
	else
	{
		printf("┼");
		printf(" ");
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		now_X -= 1;
		if (now_X < 1)
		{
			now_X = 0;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		now_X += 1;
		if (now_X > 14)
		{
			now_X = 14;
		}
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		now_Y -= 1;
		if (now_Y < 1)
		{
			now_Y = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{	
		now_Y += 1;
		if (now_Y > 14)
		{
			now_Y = 14;
		}
	}
	else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (SaveXY() == 1 && k < MAX)
		{
			k++;
		}
		Sleep(100);
	}
	GotoXY(now_X, now_Y);
	printf("◎");
	Sleep(50);
}

void DrawInput() // 돌 놓기
{
	for (int y = 0; y < MAX_KAN; y++)
	{
		for (int x = 0; x < MAX_KAN; x++)
		{
			if (Board[y][x] == 1)
			{
				GotoXY(x, y);
				SetColor(6, 0);
				printf("●"); //흑돌
				GotoXY(30, 20);
				printf("흑돌 : %d", Blackcount);
				GotoXY(42, 20);
				printf("%d", k);
			}
			else if (Board[y][x] == 2)
			{
				GotoXY(x, y);
				SetColor(6, 14);
				printf("●"); //백돌
				GotoXY(30, 25);
				printf("백돌 : %d", Whitecount);
			}
		}
	}
}
//오목 승리 조건
int End_Condition()
{
	int Black_End_Count[DIAGONAL_1 + 1] = {0};
	int White_End_Count[DIAGONAL_1 + 1] = {0};
	for (int y = 0; y < MAX_KAN; y++)
	{
		for (int x = 0; x < MAX_KAN; x++)
		{
			//흑돌
			if (Board[y][x] == 1) //흑돌 가로
			{
				Black_End_Count[WIDTH]++;
				if (Black_End_Count[WIDTH] == 5)
				{
					return 1;
				}
			}
			else
			{
				Black_End_Count[WIDTH] = 0;
			}
			//////////////////////////////////////////////////
			if (Board[x][y] == 1) //흑돌 세로
			{
				Black_End_Count[LENGTH]++;
				if (Black_End_Count[LENGTH] == 5)
				{
					return 1;
				}
			}
			else
			{
				Black_End_Count[LENGTH] = 0;
			}
			//////////////////////////////////////////////////
			//백돌 
			if (Board[y][x] == 2) //백돌 가로
			{
				White_End_Count[WIDTH]++;
				if (White_End_Count[WIDTH] == 5)
				{
					return 2;
				}
			}
			else
			{
				White_End_Count[WIDTH] = 0;
			}
			//////////////////////////////////////////////////
			if (Board[x][y] == 2) //백돌 세로
			{
				White_End_Count[LENGTH]++;
				if (White_End_Count[LENGTH] == 5)
				{
					return 2;
				}
			}
			else
			{
				White_End_Count[LENGTH] = 0;
			}
			//////////////////////////////////////////////////

		}
	}
	for (int o = -15; o < MAX_KAN; o++)
	{
		for (int y = 0; y < MAX_KAN; y++)
		{
			for (int x = 0; x < MAX_KAN; x++)
			{
				if (y == x + o) //아래쪽 대각선
				{
					if (Board[y][x] == 1) //흑돌
					{
						Black_End_Count[DIAGONAL]++;
						if (Black_End_Count[DIAGONAL] == 5)
						{
							return 1;
						}
					}
					else
					{
						Black_End_Count[DIAGONAL] = 0;
					}
					if (Board[y][x] == 2) //백돌
					{
						White_End_Count[DIAGONAL]++;
						if (White_End_Count[DIAGONAL] == 5)
						{
							return 2;
						}
					}
					else
					{
						White_End_Count[DIAGONAL] = 0;
					}
				}

				if (y == o - x) //왼쪽 대각선
				{
					if (Board[y][x] == 1) //흑돌
					{
						Black_End_Count[DIAGONAL_1]++;
						if (Black_End_Count[DIAGONAL_1] == 5)
						{
							return 1;
						}
					}
					else
					{
						Black_End_Count[DIAGONAL_1] = 0;
					}
					if (Board[y][x] == 2) //백돌
					{
						White_End_Count[DIAGONAL_1]++;
						if (White_End_Count[DIAGONAL_1] == 5)
						{
							return 2;
						}
					}
					else
					{
						White_End_Count[DIAGONAL_1] = 0;
					}
				}
			}
		}
	}
}
//오목 승리 문구
void End_Game()
{
	if (End_Condition() == 1)
	{
		Clear();
		GotoXY(20,10);
		printf("흑돌이 승리하였습니다!!");
		exit(0);
	}
	else if (End_Condition() == 2 )
	{
		Clear();
		GotoXY(20, 10);
		printf("백돌이 승리하였습니다!!");
		exit(0);
	}
}

int main()
{
	DrawInit();
	GameStartmenu();
	while(1)
	{
		Move();
		DrawInput();
		Renju_Rule();
		End_Condition();
		End_Game();
		GotoXY(40, 20);
	}
	return 0;
}