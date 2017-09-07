// Sudoku_4.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<istream>
#include<algorithm>
#include<sstream>
using namespace std;
//bool Maps_Member[10][10];			//这个代表每个矩阵的元素成员1[],代表第一个矩阵框的元素成员。
//int Map_Section[3][3];			//开始的想法要用到3*3矩阵，后来边写发现并没有用 就注释掉了。只是之前的想法

struct Sudoku {
	int Finnal_Map[10][10] = { 0 };
};
int SafeNum(int n)
{
	for (;;)
	{
		if (n % 6 == 0)
		{
			return n;
		}
		else
			n++;
	}
}
void First_Line_Init(int n, struct Sudoku S[])
{
	for (int i = 0;i < n;i++)
	{
		S[i].Finnal_Map[0][0] = (0 + 6) % 9 + 1;			//强调一下自己的学号：031502106
	}
	for (int i = 0;i < n;)
	{
		int num[8] = { 1,2,3,4,5,6,8,9 };
		int Times = 0;
		do
		{
			for (int j = 0;j < 8;j++)
			{
					S[i].Finnal_Map[0][j + 1] = num[j];			//下面会写6个原因是A33 = 6所以一个可以出6个不同的矩阵
																//其实感觉，但是如果不是题目的话，最多可以出A33*A33*2个，但是没论证，不确定	
			}
			i += 6;
			Times++;
		} while (next_permutation(num, num + 8) && Times != n/6);
	}
	for (int i = 0;i < n;i+=6)
	{
		for (int j = 1;j < 6;j++)
		{
				S[i+j] = S[i];
		}
	}
}

void Changing_Row(int i, struct Sudoku S[]);
void Changing(int n, struct Sudoku S[])
{
															//行变换，出现三个不同的3x3矩阵,由于后加的要求，导致全排列不够100000数据量，
	int num[3];
	
	for (int i = 0;i < n;)
	{													//而6是不动的，因此我需要全排列第一宫的三个数，A33，肯定满足题目的需要了。
		for (int j = 0;j < 3;j++)
		{
			num[j] = S[i].Finnal_Map[0][j];
		}
		sort(num, num + 3);
		do
		{
			S[i].Finnal_Map[1][6] = num[0];
			S[i].Finnal_Map[1][7] = num[1];
			S[i].Finnal_Map[1][8] = num[2];
			i++;
		} while (next_permutation(num, num + 3));
	}
	
	for (int i = 0;i < n;i++)
	{
		for (int k = 3, l = 0, js = 0;js < 6;l++, k = (k + 1) % 9, js++)
		{
			S[i].Finnal_Map[1][l] = S[i].Finnal_Map[0][k];			//剩余第二行
		}
		for (int k = 6, l = 0, js = 0;js < 9;l++, k = (k + 1) % 9, js++)
		{
			S[i].Finnal_Map[2][l] = S[i].Finnal_Map[0][k];			//第三行
		}
		Changing_Row(i, S);		//列变换，构造剩下的6个3x3矩阵
	}
}

void Changing_Row(int i, struct Sudoku S[])
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
						S[i].Finnal_Map[k + 3][j - 2] = S[i].Finnal_Map[k][j];
					else
						S[i].Finnal_Map[k + 3][j + 1] = S[i].Finnal_Map[k][j];
				}
			}
		for (int l = 0;l < 3;l++)
			for (int j = l * 3;j < 3 * (l + 1);j++)
			{
				for (int k = 0;k < 3;k++)
				{
if (j == 0 || j == 3 || j == 6)
S[i].Finnal_Map[k + 6][j + 2] = S[i].Finnal_Map[k][j];
else
S[i].Finnal_Map[k + 6][j - 1] = S[i].Finnal_Map[k][j];
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
						S[i].Finnal_Map[k + 6][j + 2] = S[i].Finnal_Map[k][j];
					else
						S[i].Finnal_Map[k + 6][j - 1] = S[i].Finnal_Map[k][j];
				}
			}
		for (int l = 0;l < 3;l++)
			for (int j = l * 3;j < 3 * (l + 1);j++)
			{
				for (int k = 0;k < 3;k++)
				{
					if (j == 2 || j == 5 || j == 8)
						S[i].Finnal_Map[k + 3][j - 2] = S[i].Finnal_Map[k][j];
					else
						S[i].Finnal_Map[k + 3][j + 1] = S[i].Finnal_Map[k][j];
				}
			}

	}


}

void Print(int n, struct Sudoku S[])
{
	string out = "Sudoku.txt";
	fstream Out_Put(out, ios::out);
	if (Out_Put.is_open())
	{
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < 9;j++)
			{
				for (int k = 0;k < 9;k++)
				{
					Out_Put << S[i].Finnal_Map[j][k] << " ";
				}
				Out_Put << endl;
			}
			Out_Put << endl;
		}
	}
	else
	{
		Out_Put << "文件打开失败，请重试！" << endl;
	}

	Out_Put.close();

}

bool CMD_Check(int argc, string Chk_CMD, string Chk_Num)
{
	if (argc == 3)
	{
		if (Chk_CMD == "-c")
		{
			for (int i = 0;i < Chk_Num.size();i++)
			{
				if (Chk_Num[i] <'0'||Chk_Num[i]>'9')
				{
					cout << "您输入生成数目错误，请重新执行本程序，输入正确的生成数目！" << endl;
					return false;
				}
			}
			return true;
		}
		else
		{
			cout << "您输入的命令指令错误，请重新执行本程序，输入正确的指令！" << endl;
			return false;
		}
	}
	else
	{
		cout << "您输入的参数数目错误，请重新执行本程序，并输入正确的参数！" << endl;
		return false;
	}
}
int  Input(string input)
{
	int n;
	stringstream ss;
	ss.clear();
	ss << input;
	ss >> n;
	return n;
}

int main(int argc, char* argv[])
{	//最后兼容各种CMD问题
	if (argc < 3)
	{
		cout << "您输入的参数数目错误，请重新执行本程序，并输入正确的参数！" << endl;
		return 0;
	}

	string First = argv[1];
	string Second = argv[2];
	if (CMD_Check(argc, First, Second) == true)
	{
		int n = Input(Second);
		//int n;
		//cin >> n;
		Sudoku * S = new Sudoku[SafeNum(n)];
		First_Line_Init(SafeNum(n), S);
		Changing(SafeNum(n), S);
		Print(n, S);
		return 0;
	}
	else
		return 0;
}
