// Error_Rep.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SudokuGame.h"
#include "Error_Rep.h"
#include "afxdialogex.h"


// Error_Rep �Ի���

IMPLEMENT_DYNAMIC(Error_Rep, CDialogEx)

Error_Rep::Error_Rep(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Error_Rep::~Error_Rep()
{
}

void Error_Rep::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Error_Rep, CDialogEx)
	ON_BN_CLICKED(IDOK, &Error_Rep::OnBnClickedOk)
END_MESSAGE_MAP()


// Error_Rep ��Ϣ�������


void Error_Rep::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
