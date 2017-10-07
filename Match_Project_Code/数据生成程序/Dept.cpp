#include "stdafx.h"
#include "Dept.h"
#include"Member.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string Dept::reON()
{
	return Own_Num;
}

void Dept::Produce(string Num)
{
	Own_Num = Num;
	init();
}

void Dept::Translate()
{
	//兴趣转换成字符
	for (int i = 0, len = 0;i < 5;i++)
	{
		if (Need[i] == 0)
		{
			break;
		}
		else
		{
			if (Need[i] == 1)
				Need_string[i] = "Game";
			else if (Need[i] == 2)
				Need_string[i] = "Musical_Instruments";
			else if (Need[i] == 3)
				Need_string[i] = "Dance";
			else if (Need[i] == 4)
				Need_string[i] = "Broadcast_host";
			else if (Need[i] == 5)
				Need_string[i] = "Sports_Specialty";
			else if (Need[i] == 6)
				Need_string[i] = "Musical_talent";
			else if (Need[i] == 7)
				Need_string[i] = "Recitation";
			else if (Need[i] == 8)
				Need_string[i] = "Painting_expertise";
			else if (Need[i] == 9)
				Need_string[i] = "Ps_Design_Fundamentals";
			else if (Need[i] == 10)
				Need_string[i] = "Pr_application_foundation";
			else if (Need[i] == 11)
				Need_string[i] = "AE_application_foundation";
			else if (Need[i] == 12)
				Need_string[i] = "Au_application_foundation";

		}
	}

	//空闲时间转化为字符 默认工作时间为8 - 24 点，一段时间为2小时 
	//数组的第一位为0-6代表星期1-日，后一位，代表小时 8 - 24
	int len = 0;
	for (int i = 0;i < 7;i++)
		for (int j = 0;j < 8;j++)
		{
			if (WorkTimes[i][j] == true)
			{
				stringstream ss;
				ss << 2 * j + 8;
				string use, use2;
				ss >> use;
				ss.clear();
				ss << 2 * j + 8 + 2;
				ss >> use2;
				if (i == 0)
				{
					WorkTimes_string[len++] = "Mon." + use + ":00~" + use2 + ":00";
				}
				else if (i == 1)
				{
					WorkTimes_string[len++] = "Tues." + use + ":00~" + use2 + ":00";
				}
				else if (i == 2)
				{
					WorkTimes_string[len++] = "Wed." + use + ":00~" + use2 + ":00";
				}
				else if (i == 3)
				{
					WorkTimes_string[len++] = "Thur." + use + ":00~" + use2 + ":00";
				}
				else if (i == 4)
				{
					WorkTimes_string[len++] = "Fri." + use + ":00~" + use2 + ":00";
				}
				else if (i == 5)
				{
					WorkTimes_string[len++] = "Sat." + use + ":00~" + use2 + ":00";
				}
				else if (i == 6)
				{
					WorkTimes_string[len++] = "Sun." + use + ":00~" + use2 + ":00";
				}
			}
		}
}

string * Dept::reWorkTime_string()
{
	return WorkTimes_string;
}

string * Dept::reNeed_string()
{
	return Need_string;
}

int Dept::reMaxM()
{
	return MaxM;
}

void Dept::init()
{
	//工作时间
		int Lef = rand() % 7;
		int Rig = rand() % 8;
		WorkTimes[Lef][Rig] = true;
		Lef = (rand() % 7)%7;
		Rig = (rand() % 8) % 8;
		WorkTimes[Lef][Rig] = true;
		for (int i = 0;i < 2;i++)
		{
			if (rand() % 5 == 1)
			{
				int Lef = rand() % 7;
				int Rig = rand() % 8;
				WorkTimes[Lef][Rig] = true;
			}
			else
			{
				break;
			}
		}



	//兴趣标签，需求
		bool interest[13];
		memset(interest, true, 13);
		int len = 0;
		for (int i = 0;i < 3;i++)
		{
			if (i == 0)
			{
				int Num = rand() % 12 + 1;
				interest[Num] = false;
				Need[len++] = Num;
				continue;
			}
			if (i == 1)
			{
				int Num = rand() % 12 + 1;
				if (interest[Num] == false)
				{
					interest[(Num + 1) % 12 + 1] == false;
					Need[len++] = Num;
					continue;
				}
				else
				{
					interest[Num] = false;
					Need[len++] = Num;
					continue;
				}
			}
			int Num = rand() % 13;
			if (Num == 0)
				break;
			else if (interest[Num] == false)
			{
				break;
			}
			else
			{
				interest[Num] = false;
				Need[len++] = Num;
			}
		}


		//初始化最大量
		MaxM = rand()%6 + 10;
}
