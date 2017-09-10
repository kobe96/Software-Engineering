#pragma once
class Scan_Finnal_Maps
{
public:
	void Init();
	bool Check(int j, int k, int num);
	void First_Line_Init(int n, struct Sudoku &S);
	void Changing_Row(int i, struct Sudoku &S);
	void Changing(int n, struct Sudoku &S);
	struct Sudoku  Finnal_Map_Scan();
	bool MapCheckHor[10][10];			//ºáÐÐ
	bool MapCheckVer[10][10];			//×ÝÐÐ
	
};

