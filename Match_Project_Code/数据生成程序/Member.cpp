#include "stdafx.h"
#include "Member.h"
#include<iostream>
#include<string>
#include<time.h>
#include<Windows.h>
#include"Dept.h"
#include<sstream>
#include<stdlib.h>
using namespace std;
void Member::Produce(string Num)
{
	StuNum = Num;
	init();
}

void Member::Translate(string* DeptNum)
{	//部门转换成字符
	for (int i = 0;i < MaxS;i++)
	{
		if (Select_int[i] == -1)
			break;
		else
		{
			if (Select_int[i] == -1)
				break;
			else 
				Select[i] = DeptNum[Select_int[i]];
		}
	}

	//兴趣转换成字符
	for (int i = 0,len=0;i < 5;i++)
	{
		if (Tags[i] == 0)
		{
			break;
		}
		else
		{
			if (Tags[i] == 1)
				Tags_string[i] = "Game";
			else if (Tags[i] == 2)
				Tags_string[i] = "Musical_Instruments";
			else if (Tags[i] == 3)
				Tags_string[i] = "Dance";
			else if (Tags[i] == 4)
				Tags_string[i] = "Broadcast_host";
			else if (Tags[i] == 5)
				Tags_string[i] = "Sports_Specialty";
			else if (Tags[i] == 6)
				Tags_string[i] = "Musical_talent";
			else if (Tags[i] == 7)
				Tags_string[i] = "Recitation";
			else if (Tags[i] == 8)
				Tags_string[i] = "Painting_expertise";
			else if (Tags[i] == 9)
				Tags_string[i] = "Ps_Design_Fundamentals";
			else if (Tags[i] == 10)
				Tags_string[i] = "Pr_application_foundation";
			else if (Tags[i] == 11)
				Tags_string[i] = "AE_application_foundation";
			else if (Tags[i] == 12)
				Tags_string[i] = "Au_application_foundation";

		}
	}

	//空闲时间转化为字符 默认工作时间为8 - 24 点，一段时间为2小时 
	//数组的第一位为0-6代表星期1-日，后一位，代表小时 8 - 24
	int len = 0;
	for (int i = 0;i < 7;i++)
		for (int j = 0;j < 8;j++)
		{
			if (FreeTime[i][j] == true)
			{
				stringstream ss;
				ss << 2*j + 8;
				string use,use2;
				ss >> use;
				ss.clear();
				ss<<2*j+8+2;
				ss >> use2;
				if (i == 0)
				{
					FreeTimes[len++] = "Mon." + use + ":00~" + use2 + ":00";
				}
				else if (i == 1)
				{
					FreeTimes[len++] = "Tues." + use + ":00~" + use2 + ":00";
				}
				else if (i == 2)
				{
					FreeTimes[len++] = "Wed." + use + ":00~" + use2 + ":00";
				}
				else if (i == 3)
				{
					FreeTimes[len++] = "Thur." + use + ":00~" + use2 + ":00";
				}
				else if (i == 4)
				{
					FreeTimes[len++] = "Fri." + use + ":00~" + use2 + ":00";
				}
				else if (i == 5)
				{
					FreeTimes[len++] = "Sat." + use + ":00~" + use2 + ":00";
				}
				else if (i == 6)
				{
					FreeTimes[len++] = "Sun." + use + ":00~" + use2 + ":00";
				}
			}
		}

}

string * Member::reFreeTime()
{
	string * p = &FreeTimes[0];
	return p;
}

string Member::reStuNum()
{
	return StuNum;
}

string * Member::reSelect()
{
	string * p = &Select[0];
	return p;
}

string * Member::reTags_string()
{
	string * p = &Tags_string[0];
	return p;
}


void Member::init()
{
	/*  0、无兴趣
		1、"Game"				  游戏专长
		2、"Musical_Instruments" 乐器
		3、"Dance"				  舞蹈专长	
		4、"Broadcast_host"	` 播音主持
		5、"Sports_Specialty"	  体育特长
		6、"Musical_talent"	  音乐天赋
		7、"Recitation"		  朗诵特长
		8、"Painting_expertise"  绘画特长
		9、"Ps Design Fundamentals"		Ps设计特长
		10、"Pr application foundation"		Pr应用基础
		11、"AE application foundation"		AE应用基础
		12、"Au application foundation"		Au应用基础
	*/


		//初始化空闲时间，随机安排。

	for (int i = 0;i < 7;i++)
	{
		int Num;
		Num = rand() % 8;
		FreeTime[i][Num] = true;

		if(rand()%2 == 1)
		{
			Num = rand() % 8;
			FreeTime[i][Num] = true;
		}
		if(rand()%2 == 1)
		{
			Num = rand() % 8;
			FreeTime[i][Num] = true;
		}
		if (rand() % 2 == 1)
		{
			Num = rand() % 8;
			FreeTime[i][Num] = true;
		}
		if (rand() % 2 == 1)
		{
			Num = rand() % 8;
			FreeTime[i][Num] = true;
		}
		if (rand() % 2 == 1)
		{
			Num = rand() % 8;
			FreeTime[i][Num] = true;
		}
	}

		//初始化兴趣列表
	bool Interest[13];
	memset(Interest, true, 13);
	int len = 0;
	for (int i = 0;i < 5;i++)
	{
		if (i == 0)
		{
			int Num = rand() % 12 + 1;
			Interest[Num] = false;
			Tags[len++] = Num;
			continue;
		}
		if (i == 1)
		{
			int Num = rand() % 12 + 1;
			if (Interest[Num] == false)
			{
				Interest[(Num + 1) % 12 + 1] == false;
				Tags[len++] = Num;
				continue;
			}
			else
			{
				Interest[Num] = false;
				Tags[len++] = Num;
				continue;
			}
		}
		int Num = rand() % 13;
		if (Num == 0)
			break;
		else if(Interest[Num] == false)
		{
			break;
		}
		else
		{
			Interest[Num] = false;
			Tags[len++] = Num;
		}
	}

		//初始化部门选择
	bool select[20];
	memset(Select_int, -1, 21);
	memset(select, true, 20);
	for (int i = 0;i < MaxS;i++)
	{
		int getId = rand() % 20;
		if (select[getId] == true)
		{
			select[getId] = false;
			Select_int[i] = getId;
		}
		else
			break;
	}












}
