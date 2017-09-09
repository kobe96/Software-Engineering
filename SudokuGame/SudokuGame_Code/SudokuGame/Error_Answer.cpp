// Error_Answer.cpp : 实现文件
//

#include "stdafx.h"
#include "SudokuGame.h"
#include "Error_Answer.h"
#include "afxdialogex.h"


// Error_Answer 对话框

IMPLEMENT_DYNAMIC(Error_Answer, CDialogEx)

Error_Answer::Error_Answer(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Error_Answer::~Error_Answer()
{
}

void Error_Answer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Error_Answer, CDialogEx)
END_MESSAGE_MAP()


// Error_Answer 消息处理程序
