#include "stdafx.h"
#include "Finnal_Produce.h"
#include "Deal_Maps_Work.h"
#include"Scan_Finnal_Maps.h"
#include<algorithm>
#include<time.h>
#include<iostream>
struct Sudoku {
	int Finnal_Maps[10][10];
};
bool Maps[10][10];

Sudoku Finnal_Produce::Fin_Pro()			//还要一个深度优先遍历，有点累，以后改进，担心GUI没有时间做了，以后更新优化的代码现在最多30-47左右空
{

	init();
	Deal_Maps_Work DMW;
	Scan_Finnal_Maps SFM;
	struct Sudoku S;
	S = SFM.Finnal_Map_Scan();					
	srand((unsigned)time(NULL));			//后测试发现，随机太任意，更改只随机本次，然后遍历所有解法，搜索为随机数字空的图
	Times = rand() % 30 + 30;    //随机30+个空
	int RunningTimes = 0;	//防程序一直死锁
	int Re1, Re2=-1;
	for (int i = 0,Re1 = i;i < Times&&RunningTimes<300;Re1 = i)
	{
		if (Re1 == Re2)
		{
			RunningTimes++;
		}
		else
		{
			Re2 = i;
		}
		int Num_V = rand()%9;
		int Num_H = rand()%9;
		if (Maps[Num_H][Num_V] == true)
		{
			Maps[Num_H][Num_V] = false;
			int Record = S.Finnal_Maps[Num_H][Num_V];
			S.Finnal_Maps[Num_H][Num_V] = 0;
			
			if (DMW.Work_Out_Check(S) == true)
			{
				i++;
				continue;
			}
			else
			{
				S.Finnal_Maps[Num_H][Num_V] = Record;
			}
		}
		else
		{
			bool Brk = false;
			for (int jsV=0;Brk == false&&jsV<9;Num_V = (Num_V + 1) % 9,jsV++)
			{
				for (int jsH =0;Brk == false&&jsH<9;Num_H = (Num_H + 1) % 9,jsH++)
				{
					if (Maps[Num_H][Num_V] == true)
					{
						Brk = true;
						Maps[Num_H][Num_V] = false;
						int Record = S.Finnal_Maps[Num_H][Num_V];
						S.Finnal_Maps[Num_H][Num_V] = 0;
						if (DMW.Work_Out_Check(S) == true)
						{
							i++;
							continue;
						}
						else
						{
							S.Finnal_Maps[Num_H][Num_V] = Record;
						}
					}
				}
			}
		}
		//std::cout << i << std::endl;
 	}
	return S;
}

void Finnal_Produce::init()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			Maps[i][j] = true;
		}
	}
}

Sudoku Finnal_Produce::Fin_Pro(Sudoku & S)			//可以记录原图
{
	init();
	Deal_Maps_Work DMW;
	Scan_Finnal_Maps SFM;
	srand((unsigned)time(NULL));			//后测试发现，随机太任意，更改只随机本次，然后遍历所有解法，搜索为随机数字空的图
	Times = rand() % 30 + 30;    //随机30+个空
	int RunningTimes = 0;	//防程序一直死锁
	int Re1, Re2 = -1;
	for (int i = 0, Re1 = i;i < Times&&RunningTimes<300;Re1 = i)	//以后优化部分，写一个深搜比较好，而且可以按需要挖空。RunningTimes属于凑合用的。
	{
		if (Re1 == Re2)
		{
			RunningTimes++;
		}
		else
		{
			Re2 = i;
		}
		int Num_V = rand() % 9;
		int Num_H = rand() % 9;
		if (Maps[Num_H][Num_V] == true)
		{
			Maps[Num_H][Num_V] = false;
			int Record = S.Finnal_Maps[Num_H][Num_V];
			S.Finnal_Maps[Num_H][Num_V] = 0;

			if (DMW.Work_Out_Check(S) == true)
			{
				i++;
				continue;
			}
			else
			{
				S.Finnal_Maps[Num_H][Num_V] = Record;
			}
		}
		else
		{
			bool Brk = false;
			for (int jsV = 0;Brk == false && jsV<9;Num_V = (Num_V + 1) % 9, jsV++)
			{
				for (int jsH = 0;Brk == false && jsH<9;Num_H = (Num_H + 1) % 9, jsH++)
				{
					if (Maps[Num_H][Num_V] == true)
					{
						Brk = true;
						Maps[Num_H][Num_V] = false;
						int Record = S.Finnal_Maps[Num_H][Num_V];
						S.Finnal_Maps[Num_H][Num_V] = 0;
						if (DMW.Work_Out_Check(S) == true)
						{
							i++;
							continue;
						}
						else
						{
							S.Finnal_Maps[Num_H][Num_V] = Record;
						}
					}
				}
			}
		}
		//std::cout << i << std::endl;
	}
	return S;
}
