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
	bool WorkTimes[8][9];			//�ʱ��
	int Need[10];					//��Ҫ����Ȥ����
	string Own_Num;					//���ű��
	int MaxM;						//��������
	void init();
	string Need_string[10];
	string WorkTimes_string[21];
	
	
	
};

