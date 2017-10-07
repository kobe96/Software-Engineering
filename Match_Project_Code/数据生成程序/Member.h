#pragma once
#include<string>
using namespace std;
class Member
{
public:	
	void Produce(string Num);
	void Translate(string * DeptNum);
	string* reFreeTime();
	string reStuNum();
	string* reSelect();
	string* reTags_string();
	
private:
	bool FreeTime[8][9] = { false };	//空闲时间
	int Tags[5];						//兴趣标签
	int MaxS = 5;						//最大部门申请量
	int Select_int[5];
	string Select[5];					//部门选择
	string StuNum;						//学生ID
	string Tags_string[5];
	string FreeTimes[21];
	string Admitted[5];					//被选中的部门
	void init();

};