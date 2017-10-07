#pragma once
#include<string>
using namespace std;
class Dept
{
public:
	string reON();
	void Produce(string Num);
	void Translate();
	string * reWorkTime_string();
	string * reNeed_string();
	int reMaxM();
private:
	bool WorkTimes[8][9];			//活动时间
	int Need[10];					//需要的兴趣方向
	string Own_Num;					//部门编号
	int MaxM;						//上限人数
	void init();
	string Need_string[10];
	string WorkTimes_string[21];
	
	
	
};

