#pragma once
class Deal_Maps_Work
{
public:
	bool Work_Out_Check(struct Sudoku &S);
	void init(struct Sudoku &S);
	void Dist(int StarNum);
	bool Test_Check(int Hor, int Ver, int Test_Num);
	int Maps_Dist[9][9];
	int Times = 0;
	int isTrue = 0;
	
};

