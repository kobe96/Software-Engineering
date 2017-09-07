// Won.cpp : 实现文件
//

#include "stdafx.h"
#include "SudokuGame.h"
#include "Won.h"
#include "afxdialogex.h"


// Won 对话框

IMPLEMENT_DYNAMIC(Won, CDialogEx)

Won::Won(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Won::~Won()
{
}

void Won::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Won, CDialogEx)
END_MESSAGE_MAP()


// Won 消息处理程序
