#include "stdafx.h"
#include "Deal_Maps_Work.h"
#include"Scan_Finnal_Maps.h"
struct Sudoku
{
	int Finnal_Map[10][10] = { 0 };
};

bool Deal_Maps_Work::Work_Out_Check(Sudoku &S)
{
	init(S);
	Dist(0);
	if (isTrue == -1)
	{
		Times = 0;
		isTrue = 0;
		return false;
	}
	else
	{
		Times = 0;
		isTrue = 0;
		return true;
	}
}

void Deal_Maps_Work::init(struct Sudoku &S)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			 Maps_Dist[i][j] = S.Finnal_Map[i][j];
		}
	}
}

void Deal_Maps_Work::Dist(int StartNum)	//递归求解是否唯一
{
	int i, j, Hor, Ver;
	if (Times > 1)						//	不唯一直接返回
		return;
	else if (StartNum >= 81)				//	第一次唯一会被记录
	{
		Times++;
		if (Times > 1)
		{
			isTrue = -1;
			return;
		}
	}
	else
	{
		Hor = StartNum / 9;
		Ver = StartNum % 9;
		if (Maps_Dist[Hor][Ver] != 0)
		{
			Dist(StartNum + 1);
		}
		for (i = 1; i <= 9; i++)			//	1到9开始试验
		{
			if (Test_Check(Hor, Ver, i) == true)	//符合标准,继续
			{
				Maps_Dist[Hor][Ver] = i;		
				Dist(StartNum + 1);
				Maps_Dist[Hor][Ver] = 0;
			}
		}

	}
}

bool Deal_Maps_Work::Test_Check(int Hor, int Ver, int TestNum)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		if (Maps_Dist[Hor][i] == TestNum || Maps_Dist[i][Ver] == TestNum)	//横竖行有缺失，则结束
		{
			return false;
		}
	}	//横竖满足进行下面操作
		for (i = (Hor / 3) * 3; i < (Hor / 3) * 3 + 3; i++)	//本九宫格中存在一个相同的数字。结束
		{
			for (j = (Ver / 3) * 3; j < (Ver / 3) * 3 + 3; j++)
			{
				if (Maps_Dist[i][j] == TestNum)
				{
					return false;
				}
			}
		}
		return true;					//完成以上两项检验，且不存在问题,接受

}
