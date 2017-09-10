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
int Row = 0;
//bool Maps_Member[10][10];			//�������ÿ�������Ԫ�س�Ա1[],�����һ��������Ԫ�س�Ա��
//int Map_Section[3][3];			//��ʼ���뷨Ҫ�õ�3*3���󣬺�����д���ֲ�û���� ��ע�͵��ˡ�ֻ��֮ǰ���뷨

struct Sudoku {
	int Finnal_Map[10][10] = { 0 };
};
int SafeNum(int n)
{
	for (;;)
	{
		if (n % 216 == 0)
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
			i += 216;
			Times++;
		} while (next_permutation(num, num + 8) && Times != n/216);
	}
	for (int i = 0;i < n;i+=216)
	{
		for (int j = 1;j < 216;j++)
		{
				S[i+j] = S[i];
		}
	}
}


void Changing_Row(int i, struct Sudoku S[]);
void Changing(int n, struct Sudoku S[])
{
	
	int num1[3], num2[3], num3[3];
	for (int i = 0;i < n;)
	{
		int Need = i;
		if (i % 36 == 0)
		{

			for (int j = 3;j < 6;j++)
			{
				num2[j - 3] = S[Need].Finnal_Map[0][j];
			}
			sort(num2, num2 + 3);
			do
			{
				S[Need].Finnal_Map[1][0] = num2[0];
				S[Need].Finnal_Map[1][1] = num2[1];
				S[Need].Finnal_Map[1][2] = num2[2];
				for (int j = 1; j < 6; j++)
				{
					S[Need + j].Finnal_Map[1][0] = S[Need].Finnal_Map[1][0];
					S[Need + j].Finnal_Map[1][1] = S[Need].Finnal_Map[1][1];
					S[Need + j].Finnal_Map[1][2] = S[Need].Finnal_Map[1][2];
				}
				Need += 6;
			} while (next_permutation(num2, num2 + 3));
			Need = i;
		}
		if (i % 216 == 0)
		{
			for (int j = 0;j < 3;j++)
			{
				num3[j] = S[Need].Finnal_Map[0][j];
			}
			sort(num3, num3 + 3);
			do
			{
				S[Need].Finnal_Map[1][6] = num3[0];
				S[Need].Finnal_Map[1][7] = num3[1];
				S[Need].Finnal_Map[1][8] = num3[2];
				for (int j = 1; j < 36; j++)
				{
					S[Need + j].Finnal_Map[1][6] = S[Need].Finnal_Map[1][6];
					S[Need + j].Finnal_Map[1][7] = S[Need].Finnal_Map[1][7];
					S[Need + j].Finnal_Map[1][8] = S[Need].Finnal_Map[1][8];
				}
				Need += 36;
			} while (next_permutation(num3, num3 + 3));
			Need = i;
		}
		for (int Use = 0; Use < 36; Use++)
		{
			for (int j = 6; j < 9; j++)
			{
				num1[j - 6] = S[i].Finnal_Map[0][j];
			}
			sort(num1, num1 + 3);
			do
			{
				S[i].Finnal_Map[1][3] = num1[0];
				S[i].Finnal_Map[1][4] = num1[1];
				S[i].Finnal_Map[1][5] = num1[2];
				for (int k = 6, l = 0, js = 0; js < 9; l++, k = (k + 1) % 9, js++)
				{
					S[i].Finnal_Map[2][l] = S[i].Finnal_Map[0][k];			//������
				}
				Changing_Row(i, S);		//�б任������ʣ�µ�6��3x3����
				i++;
			} while (next_permutation(num1, num1 + 3));
			
		}

		
	}
	
}

void Changing_Row(int i, struct Sudoku S[])
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

void Print(int n, struct Sudoku S[])
{
	string out = "sudoku.txt";
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
				if (Chk_Num[i] <'0' || Chk_Num[i]>'9')
				{
					cout << "������������Ŀ����������ִ�б�����������ȷ��������Ŀ��" << endl;
					return false;
				}
			}
			int NUM;
			stringstream ss;
			ss << Chk_Num;
			ss >> NUM;
			if (NUM > 1000000)
			{
				cout << "������������Ŀ����������ִ�б������������1-1000000������������" << endl;
			}
			else
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
