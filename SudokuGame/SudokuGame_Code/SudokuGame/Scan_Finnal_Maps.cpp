#include "stdafx.h"
#include "Scan_Finnal_Maps.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
struct Sudoku
{
	int Finnal_Map[10][10] = { 0 };
};
	

void Scan_Finnal_Maps::Init()
{
	for (int i = 0;i <= 9;i++)
	{
		for (int j = 0;j <= 9;j++)
		{
			MapCheckHor[i][j] = true;
			MapCheckVer[i][j] = true;
		}
	}
}

bool Scan_Finnal_Maps::Check(int j, int k, int num)
{
	if (MapCheckHor[j][num - 1] == true && MapCheckVer[num - 1][k] == true) //判断棋盘上的横行和纵行，num的值有没有被使用，
	{														//num有没有被使用与横行总行的num位置的true false有关
		MapCheckHor[j][num - 1] = false;
		MapCheckVer[num - 1][k] = false;
		return true;
	}
	else
		return false;
}

void Scan_Finnal_Maps::First_Line_Init(int n, Sudoku &S)
{
	srand((unsigned)time(NULL));
	int num;
	for (int i = 0;i < n;i++)
	{
		Init();
		for (int j = 0;j < 1;j++)
		{
			for (int k = 0;k < 9;k++)
			{
				num = rand() % 9 + 1;
				if (Check(j, k, num) == true)
				{
					S.Finnal_Map[j][k] = num;
				}
				else
				{
					for (;;)
					{
						num = num % 9 + 1;
						if (Check(j, k, num) == true)
						{
							S.Finnal_Map[j][k] = num;
							break;
						}
					}
				}
			}
		}
	}
}

void Scan_Finnal_Maps::Changing_Row(int i, Sudoku &S)
{
	int num = rand() % 2;
	if (num == 1)
	{
		for (int l = 0;l < 3;l++)
			for (int j = l * 3;j < 3 * (l + 1);j++)
			{
				for (int k = 0;k < 3;k++)
				{
					if (j == 2 || j == 5 || j == 8)
						S.Finnal_Map[k + 3][j - 2] = S.Finnal_Map[k][j];
					else
						S.Finnal_Map[k + 3][j + 1] = S.Finnal_Map[k][j];
				}
			}
		for (int l = 0;l < 3;l++)
			for (int j = l * 3;j < 3 * (l + 1);j++)
			{
				for (int k = 0;k < 3;k++)
				{
					if (j == 0 || j == 3 || j == 6)
						S.Finnal_Map[k + 6][j + 2] = S.Finnal_Map[k][j];
					else
						S.Finnal_Map[k + 6][j - 1] = S.Finnal_Map[k][j];
				}
			}
	}
	else
	{
		for (int l = 0;l < 3;l++)
			for (int j = l * 3;j < 3 * (l + 1);j++)
			{
				for (int k = 0;k < 3;k++)
				{
					if (j == 0 || j == 3 || j == 6)
						S.Finnal_Map[k + 6][j + 2] = S.Finnal_Map[k][j];
					else
						S.Finnal_Map[k + 6][j - 1] = S.Finnal_Map[k][j];
				}
			}
		for (int l = 0;l < 3;l++)
			for (int j = l * 3;j < 3 * (l + 1);j++)
			{
				for (int k = 0;k < 3;k++)
				{
					if (j == 2 || j == 5 || j == 8)
						S.Finnal_Map[k + 3][j - 2] = S.Finnal_Map[k][j];
					else
						S.Finnal_Map[k + 3][j + 1] = S.Finnal_Map[k][j];
				}
			}

	}
}
void Scan_Finnal_Maps::Changing(int n, Sudoku &S)
{
	for (int i = 0;i < n;i++)
	{														//行变换，出现三个不同的3x3矩阵
		for (int k = 3, l = 0, js = 0;js < 9;l++, k = (k + 1) % 9, js++)
		{
			S.Finnal_Map[1][l] = S.Finnal_Map[0][k];
		}
		for (int k = 6, l = 0, js = 0;js < 9;l++, k = (k + 1) % 9, js++)
		{
			S.Finnal_Map[2][l] = S.Finnal_Map[0][k];
		}
		Changing_Row(i, S);											//列变换，构造剩下的6个3x3矩阵
	}
}

struct Sudoku Scan_Finnal_Maps::Finnal_Map_Scan()
{
	struct Sudoku S;
	First_Line_Init(1, S);
	Changing(1, S);
	return S;
}
