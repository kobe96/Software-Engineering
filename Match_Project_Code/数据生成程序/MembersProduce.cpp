// MembersProduce.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"Dept.h"
#include<stdlib.h>
#include<time.h>
#include"Member.h"
using namespace std;
Member Student[300];
Dept Department[20];
int All_Student_No[300];
string All_Dept_No[21] = {
	"D001","D002", "D003", "D004", "D005", "D006","D007",
	"D008", "D009", "D010", "D011", "D012","D013","D014",
	"D015","D016", "D017", "D018","D019","D020" };
string All_Student_No_string[300];

int main()
{
	srand((unsigned)time(NULL));
	void init();
	void Print_Dept();
	void Print_Stu();
	init();
	Print_Stu();
	Print_Dept();
    return 0;
}

void Print_Stu();
void init()
{
	//��ʼ�����źͳ�Ա���
	All_Student_No[300];
	All_Student_No_string[300];
	for (int i = 0;i < 300;i++)
	{
		stringstream ss;
		All_Student_No[i] = 1 + i;
		ss << All_Student_No[i];
		ss >> All_Student_No_string[i];
		ss.clear();
	}

	//��ʼ����Ա
	for (int i = 0;i < 300;i++)
	{
		Student[i].Produce(All_Student_No_string[i]);
		Student[i].Translate(All_Dept_No);
	}
	//��ʼ������
	for (int i = 0;i < 20;i++)
	{
		Department[i].Produce(All_Dept_No[i]);
		Department[i].Translate();
	}
}

void Print_Stu()
{
	string out = "input_data.txt";
	fstream Out_Put(out, ios::out);
	if (Out_Put.is_open())
	{
		Out_Put << "{" << endl<<"	"<<"\"students\":["<<endl;

		for (int i = 0;i < 300;i++)
		{

			//freetime �������
			Out_Put << "		{" << endl << "			\"free_time\":[" << endl;
			for (int j = 0;j < 20;j++)
			{
				string * Mid = Student[i].reFreeTime();
				if (Mid[j] == "")
				{
					Out_Put << "			]," << endl;
						break;
				}
				else
				{
					if (Mid[j + 1] == ""||j==19)
						Out_Put << "				" << "\"" << Mid[j] << "\"" << endl;
					else
						Out_Put << "				" << "\"" << Mid[j] << "\"," << endl;
				}
				if (j == 19)
				{
					Out_Put << "			]," << endl;
					break;
				}
			}

			//����������
			Out_Put << "			\"student_no\":\"" << Student[i].reStuNum()<<"\","<<endl;

			//����ѡ�񲿷�
			Out_Put << "			\"applications_department\":[" << endl;
			for (int j = 0;j < 5;j++)
			{
				string * Mid = Student[i].reSelect();
				
				if (Mid[j] == "")
				{
					Out_Put << "			]," << endl;
					break;
				}
				else
				{
					if (Mid[j + 1] == ""||j==4)
						Out_Put << "				" << "\"" << Mid[j] << "\"" << endl;
					else
						Out_Put << "				" << "\"" << Mid[j] << "\"," << endl;
				}
				if (j == 4)
				{
					Out_Put << "			]," << endl;
					break;
				}
			}

			//��Ȥ���ò���
			Out_Put << "			\"tags\":[" << endl;
			for (int j = 0;j < 5;j++)
			{
				string * Mid = Student[i].reTags_string();

				if (Mid[j] == "")
				{
					Out_Put << "			]" << endl;
					break;
				}
				else
				{
					if (Mid[j + 1] == ""||j==4)
						Out_Put << "				" << "\"" << Mid[j] << "\"" << endl;
					else
						Out_Put << "				" << "\"" << Mid[j] << "\"," << endl;
				}
				if (j == 4)
				{
					Out_Put << "			]" << endl;
					break;
				}
			}

			if(i!=299)
			Out_Put << "		}," << endl;
			else
			Out_Put << "		}" << endl;
		}
		Out_Put << "	]," << endl;
	}
	else
	{
		Out_Put << "�ļ���ʧ�ܣ������ԣ�" << endl;
	}

	Out_Put.close();
}

void Print_Dept()
{
	string out = "input_data.txt";
	fstream Out_Put(out, ios::app);
	if (Out_Put.is_open())
	{
		//����ʱ�䲿��
		Out_Put << "	" << "\"departments\": ["<<endl;
		for (int i = 0;i < 20;i++)
		{
			Out_Put << "		{" << endl << "			\"event_schedules\": [" << endl;
			for (int j = 0;j < 20;j++)
			{
				string * Mid = Department[i].reWorkTime_string();
				if (Mid[j] == "")
				{
					Out_Put << "			]," << endl;
					break;
				}
				else
				{
					if (Mid[j + 1] == ""||j==4)
						Out_Put << "				" << "\"" << Mid[j] << "\"" << endl;
					else
						Out_Put << "				" << "\"" << Mid[j] << "\"," << endl;
				}
				if (j == 19)
				{
					Out_Put << "			]," << endl;
					break;
				}
			}

			//�������������
			Out_Put << "			\"member_limit\":\"" << Department[i].reMaxM() << "\"," << endl;

			//���ű��
			Out_Put << "			\"department_no\":\"" << Department[i].reON() << "\"," << endl;


			//��Ȥ��ǩ����
			Out_Put << "			\"tags\":[" << endl;
			for (int j = 0;j < 5;j++)
			{
				string * Mid = Department[i].reNeed_string();

				if (Mid[j] == "")
				{
					Out_Put << "			]" << endl;
					break;
				}
				else
				{
					if (Mid[j + 1] == ""||j==4)
						Out_Put << "				" << "\"" << Mid[j] << "\"" << endl;
					else
						Out_Put << "				" << "\"" << Mid[j] << "\"," << endl;
				}
				if (j == 4)
				{
					Out_Put << "			]" << endl;
					break;
				}

			}
			if (i != 19)
				Out_Put << "		}," << endl;
			else
				Out_Put << "		}" << endl;

		}
		Out_Put << "	]" << endl<<"}";
	}
	else
	{
		Out_Put << "�ļ���ʧ�ܣ������ԣ�" << endl;
	}

	Out_Put.close();
}