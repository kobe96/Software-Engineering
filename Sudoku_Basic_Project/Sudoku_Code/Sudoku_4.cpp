// Sudoku_4.cpp : �������̨Ӧ�ó������ڵ㡣
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
//bool Maps_Member[10][10];			//�������ÿ�������Ԫ�س�Ա1[],�����һ��������Ԫ�س�Ա��
//int Map_Section[3][3];			//��ʼ���뷨Ҫ�õ�3*3���󣬺�����д���ֲ�û���� ��ע�͵��ˡ�ֻ��֮ǰ���뷨

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
		S[i].Finnal_Map[0][0] = (0 + 6) % 9 + 1;			//ǿ��һ���Լ���ѧ�ţ�031502106
	}
	for (int i = 0;i < n;)
	{
		int num[8] = { 1,2,3,4,5,6,8,9 };
		int Times = 0;
		do
		{
			for (int j = 0;j < 8;j++)
			{
					S[i].Finnal_Map[0][j + 1] = num[j];			//�����д6��ԭ����A33 = 6����һ�����Գ�6����ͬ�ľ���
																//��ʵ�о����������������Ŀ�Ļ��������Գ�A33*A33*2��������û��֤����ȷ��	
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
															//�б任������������ͬ��3x3����,���ں�ӵ�Ҫ�󣬵���ȫ���в���100000��������
	int num[3];
	
	for (int i = 0;i < n;)
	{													//��6�ǲ����ģ��������Ҫȫ���е�һ������������A33���϶�������Ŀ����Ҫ�ˡ�
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
			S[i].Finnal_Map[1][l] = S[i].Finnal_Map[0][k];			//ʣ��ڶ���
		}
		for (int k = 6, l = 0, js = 0;js < 9;l++, k = (k + 1) % 9, js++)
		{
			S[i].Finnal_Map[2][l] = S[i].Finnal_Map[0][k];			//������
		}
		Changing_Row(i, S);		//�б任������ʣ�µ�6��3x3����
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
		Out_Put << "�ļ���ʧ�ܣ������ԣ�" << endl;
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
					cout << "������������Ŀ����������ִ�б�����������ȷ��������Ŀ��" << endl;
					return false;
				}
			}
			return true;
		}
		else
		{
			cout << "�����������ָ�����������ִ�б�����������ȷ��ָ�" << endl;
			return false;
		}
	}
	else
	{
		cout << "������Ĳ�����Ŀ����������ִ�б����򣬲�������ȷ�Ĳ�����" << endl;
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
{	//�����ݸ���CMD����
	if (argc < 3)
	{
		cout << "������Ĳ�����Ŀ����������ִ�б����򣬲�������ȷ�Ĳ�����" << endl;
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
