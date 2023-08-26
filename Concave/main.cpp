#include <stdio.h>
#include <Windows.h>

#include "Console.h"

#define MAX_KAN 15			//�ٵ��� ũ��
#define MAX 255				//�ٵϾ� ����
#define START_X MAX_KAN / 2	//���� ���� ��ġ X
#define START_Y MAX_KAN / 2	//���� ���� ��ġ Y
#define WIDTH 0				//����
#define LENGTH 1			//����
#define DIAGONAL 3			//������ �Ʒ� �밢��
#define DIAGONAL_1 4		//���� �Ʒ� �밢��

int now_X, now_Y;			//���� ��ġ
int k = 0;					//���� ���� ����

int Blackcount = 0;			//�浹�� ����
int Whitecount = 0;			//�鵹�� ����
void GameStartmenu()		//���� ��ġ�� ���� ��ġ�� ���� �Լ� (1ȸ ����)
{
	now_X = START_X;
	now_Y = START_Y;
}
int Board[MAX_KAN][MAX_KAN] = {						//������
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

void DrawInit() //������ �׸���
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
					printf("����");
				}
				else if (j == MAX_KAN - 1)
				{
					printf("�� ");
				}
				else
				{
					printf("����");
				}
			}
			else if (j == 0)
			{
				if (i == MAX_KAN - 1)
				{
					printf("����");
				}
				else
				{
					printf("����");
				}
			}
			else if (j == MAX_KAN - 1)
			{
				if (i == MAX_KAN - 1)
				{
					printf("�� ");
				}
				else
				{
					printf("�� ");
				}
			}
			else if (i == MAX_KAN - 1)
			{
				printf("����");
			}
			else
			{
				printf("����");
			}
		}
		printf("\n");
	}
}
//���� ���ַ�
bool Renju_Rule()
{
	int Renju_Count = 0;

	if (Board[now_Y][now_X] == 1)
	{
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] == 1 && Board[now_Y][now_X + 3] != 2 && Board[now_Y][now_X + 4] != 2) //���� �а��� ���� �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}	
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] == 1 && Board[now_Y][now_X - 3] != 2 && Board[now_Y][now_X - 4] != 2) //���� �а��� ������ �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] != 2 && Board[now_Y - 4][now_X] != 2) //���� ���� �Ʒ��� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] != 2 && Board[now_Y + 4][now_X] != 2) //���� ���� ���� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] != 2 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] != 1 && Board[now_Y - 4][now_X + 4] != 2) //������ �� ���� �Ʒ�
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X + 1] != 2 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] != 1 && Board[now_Y + 4][now_X - 4] != 2) //������ �� ���� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] != 1 && Board[now_Y][now_X + 3] == 1 && Board[now_Y][now_X + 4] != 2) //���� �а��� ���� �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] != 2 && Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] != 1 && Board[now_Y][now_X - 3] == 1 && Board[now_Y][now_X - 4] != 2) //���� �а��� ������ �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] != 2 && Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1 && Board[now_Y - 4][now_X] != 2) //���� ���� �Ʒ��� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] != 2 && Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1 && Board[now_Y + 4][now_X] != 2) //���� ���� ���� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] != 1 && Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1 && Board[now_Y - 4][now_X + 4] != 2) //������ �� ���� �Ʒ�
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1) //������ �� ���� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] != 1 && Board[now_Y][now_X + 3] == 1) //���� �а��� ���� �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] != 1 && Board[now_Y][now_X - 3] == 1) //���� �а��� ������ �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] != 1 && Board[now_Y - 3][now_X] == 1) //���� ���� �Ʒ��� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] != 1 && Board[now_Y + 3][now_X] == 1) //���� ���� ���� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] != 1 && Board[now_Y - 3][now_X + 3] == 1) //������ �� ���� �Ʒ�
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] != 1 && Board[now_Y + 3][now_X - 3] == 1) //������ �� ���� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X - 1] == 1 && Board[now_Y + 1][now_X] == 1 && Board[now_Y - 1][now_X] == 1) //�����
		{
			Board[now_Y][now_X] = 0;
			GotoXY(40, 20);
			printf("���ַ꿡 �ɸ��ϴ�.");
			k--;
			return true;
		}
		if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 1][now_X - 1] == 1 && Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 1][now_X + 1] == 1) // +��� 
		{
			Board[now_Y][now_X] = 0;
			GotoXY(40, 20);
			printf("���ַ꿡 �ɸ��ϴ�.");
			k--;
			return true;
		}
		if (Board[now_Y][now_X + 1] == 1 && Board[now_Y][now_X + 2] == 1 && Board[now_Y][now_X + 3] == 1) //���� �а��� ���� �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y][now_X - 1] == 1 && Board[now_Y][now_X - 2] == 1 && Board[now_Y][now_X - 3] == 1) //���� �а��� ������ �� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X] == 1 && Board[now_Y - 2][now_X] == 1 && Board[now_Y - 3][now_X] == 1) //���� ���� �Ʒ��� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X] == 1 && Board[now_Y + 2][now_X] == 1 && Board[now_Y + 3][now_X] != 1) //���� ���� ���� �ξ��� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y - 1][now_X + 1] == 1 && Board[now_Y - 2][now_X + 2] == 1 && Board[now_Y - 3][now_X + 3] == 1) //������ �� ���� �Ʒ�
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
				printf("���ַ꿡 �ɸ��ϴ�.");
				k--;
				return true;
			}
			else
			{
				Renju_Count = 0;
			}
		}
		if (Board[now_Y + 1][now_X - 1] == 1 && Board[now_Y + 2][now_X - 2] == 1 && Board[now_Y + 3][now_X - 3] == 1) //������ �� ���� ��
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
				printf("���ַ꿡 �ɸ��ϴ�.");
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
//��ǥ ����
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
//�̵�
void Move() //���� �� ��� / �����̱�
{	
	SetColor(6, 0);
	GotoXY(now_X, now_Y);
	if (now_X == 0 && now_Y == 0)
	{
		printf("��");
		printf(" ");
	}
	else if (now_X != 0 && now_X != MAX_KAN - 1 && now_Y == 0)
	{
		printf("��");
		printf(" ");
	}
	else if (now_X == 0 && now_Y != 0 && now_Y != MAX_KAN - 1)
	{
		printf("��");
		printf(" ");
	}
	else if (now_X == 0 && now_Y == MAX_KAN - 1)
	{
		printf("����");
		printf(" ");
	}
	else if (now_X == MAX_KAN - 1 && now_Y == 0)
	{
		printf("��");
		printf(" ");
	}
	else if (now_Y == MAX_KAN - 1 && now_X != 0 && now_X != MAX_KAN - 1)
	{
		printf("��");
		printf(" ");
	}
	else if (now_X == MAX_KAN - 1 && now_Y == MAX_KAN - 1)
	{
		printf("��");
		printf(" ");
	}
	else if (now_Y != MAX_KAN - 1 && now_X == MAX_KAN - 1 && now_Y != 0)
	{
		printf("��");
		printf(" ");
	}
	else
	{
		printf("��");
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
	printf("��");
	Sleep(50);
}

void DrawInput() // �� ����
{
	for (int y = 0; y < MAX_KAN; y++)
	{
		for (int x = 0; x < MAX_KAN; x++)
		{
			if (Board[y][x] == 1)
			{
				GotoXY(x, y);
				SetColor(6, 0);
				printf("��"); //�浹
				GotoXY(30, 20);
				printf("�浹 : %d", Blackcount);
				GotoXY(42, 20);
				printf("%d", k);
			}
			else if (Board[y][x] == 2)
			{
				GotoXY(x, y);
				SetColor(6, 14);
				printf("��"); //�鵹
				GotoXY(30, 25);
				printf("�鵹 : %d", Whitecount);
			}
		}
	}
}
//���� �¸� ����
int End_Condition()
{
	int Black_End_Count[DIAGONAL_1 + 1] = {0};
	int White_End_Count[DIAGONAL_1 + 1] = {0};
	for (int y = 0; y < MAX_KAN; y++)
	{
		for (int x = 0; x < MAX_KAN; x++)
		{
			//�浹
			if (Board[y][x] == 1) //�浹 ����
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
			if (Board[x][y] == 1) //�浹 ����
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
			//�鵹 
			if (Board[y][x] == 2) //�鵹 ����
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
			if (Board[x][y] == 2) //�鵹 ����
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
				if (y == x + o) //�Ʒ��� �밢��
				{
					if (Board[y][x] == 1) //�浹
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
					if (Board[y][x] == 2) //�鵹
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

				if (y == o - x) //���� �밢��
				{
					if (Board[y][x] == 1) //�浹
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
					if (Board[y][x] == 2) //�鵹
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
//���� �¸� ����
void End_Game()
{
	if (End_Condition() == 1)
	{
		Clear();
		GotoXY(20,10);
		printf("�浹�� �¸��Ͽ����ϴ�!!");
		exit(0);
	}
	else if (End_Condition() == 2 )
	{
		Clear();
		GotoXY(20, 10);
		printf("�鵹�� �¸��Ͽ����ϴ�!!");
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