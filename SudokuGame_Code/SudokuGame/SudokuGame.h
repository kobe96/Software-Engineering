
// SudokuGame.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSudokuGameApp: 
// �йش����ʵ�֣������ SudokuGame.cpp
//

class CSudokuGameApp : public CWinApp
{
public:
	CSudokuGameApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSudokuGameApp theApp;
