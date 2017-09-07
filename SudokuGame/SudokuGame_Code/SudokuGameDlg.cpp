
// SudokuGameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SudokuGame.h"
#include "SudokuGameDlg.h"
#include "afxdialogex.h"
#include"Deal_Maps_Work.h"
#include"Finnal_Produce.h"
#include"Scan_Finnal_Maps.h"
#include<iostream>
#include<string>
#include"Error_Rep.h"
#include"Error_Answer.h"
#include"Won.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int Record[82];
struct Sudoku
{
	int Finnal_Maps[10][10];
};
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSudokuGameDlg 对话框



CSudokuGameDlg::CSudokuGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SUDOKUGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CSudokuGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSudokuGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CSudokuGameDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CSudokuGameDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSudokuGameDlg 消息处理程序

BOOL CSudokuGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSudokuGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();

	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSudokuGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}


}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSudokuGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSudokuGameDlg::OnBnClickedButton3()
{
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT5)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT6)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT7)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT8)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT9)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT10)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT11)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT12)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT13)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT14)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT15)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT16)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT17)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT18)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT19)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT20)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT21)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT22)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT23)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT24)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT25)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT26)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT27)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT28)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT29)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT30)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT31)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT32)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT33)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT34)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT35)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT36)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT37)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT38)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT39)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT40)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT41)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT42)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT43)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT44)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT45)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT46)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT47)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT48)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT49)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT50)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT51)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT52)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT53)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT54)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT55)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT56)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT57)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT58)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT59)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT60)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT61)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT62)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT63)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT64)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT65)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT66)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT67)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT68)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT69)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT70)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT71)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT72)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT73)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT74)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT75)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT76)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT77)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT78)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT79)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT80)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT81)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT8)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT9)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT10)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT11)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT12)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT13)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT14)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT15)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT16)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT17)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT18)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT19)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT20)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT21)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT22)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT23)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT24)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT25)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT26)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT27)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT28)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT29)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT30)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT31)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT32)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT33)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT34)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT35)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT36)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT37)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT38)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT39)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT40)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT41)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT42)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT43)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT44)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT45)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT46)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT47)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT48)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT49)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT50)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT51)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT52)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT53)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT54)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT55)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT56)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT57)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT58)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT59)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT60)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT61)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT62)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT63)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT64)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT65)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT66)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT67)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT68)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT69)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT70)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT71)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT72)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT73)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT74)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT75)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT76)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT77)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT78)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT79)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT80)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT81)->EnableWindow(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	Sudoku S1,S2;
	Finnal_Produce FP;
	Scan_Finnal_Maps SFM;
	S1 = SFM.Finnal_Map_Scan();
	for (int i = 0, js = 0; i < 9;i++)
	{
		for (int j = 0;j < 9;j++, js++)
		{
			Record[js] = S1.Finnal_Maps[i][j];
		}
	}
	S2 = FP.Fin_Pro(S1);
	CString Num[82];
	for (int i = 0,js = 0; i < 9;i++)
	{
		for (int j = 0;j < 9;j++,js++)
		{
			Num[js].Format(_T("%d"),S2.Finnal_Maps[i][j]);
		}
	}
	if (Num[0].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT1)->SetWindowText(Num[0]);
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	}
	if (Num[1].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT2)->SetWindowText(Num[1]);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	}
	if (Num[2].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT3)->SetWindowText(Num[2]);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	}
	if (Num[3].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(Num[3]);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	}
	if (Num[4].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT5)->SetWindowText(Num[4]);
		GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	}
	if (Num[5].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT6)->SetWindowText(Num[5]);
		GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	}
	if (Num[6].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT7)->SetWindowText(Num[6]);
		GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);

	}
	if (Num[7].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT8)->SetWindowText(Num[7]);
		GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);
	}
	if (Num[8].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT9)->SetWindowText(Num[8]);
		GetDlgItem(IDC_EDIT9)->EnableWindow(FALSE);
	}
	if (Num[9].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT10)->SetWindowText(Num[9]);
		GetDlgItem(IDC_EDIT10)->EnableWindow(FALSE);
	}
	if (Num[10].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT11)->SetWindowText(Num[10]);
		GetDlgItem(IDC_EDIT11)->EnableWindow(FALSE);
	}
	if (Num[11].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT12)->SetWindowText(Num[11]);
		GetDlgItem(IDC_EDIT12)->EnableWindow(FALSE);
	}
	if (Num[12].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT13)->SetWindowText(Num[12]);
		GetDlgItem(IDC_EDIT13)->EnableWindow(FALSE);
	}
	if (Num[13].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT14)->SetWindowText(Num[13]);
		GetDlgItem(IDC_EDIT14)->EnableWindow(FALSE);
	}
	if (Num[14].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT15)->SetWindowText(Num[14]);
		GetDlgItem(IDC_EDIT15)->EnableWindow(FALSE);
	}
	if (Num[15].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT16)->SetWindowText(Num[15]);
		GetDlgItem(IDC_EDIT16)->EnableWindow(FALSE);
	}
	if (Num[16].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT17)->SetWindowText(Num[16]);
		GetDlgItem(IDC_EDIT17)->EnableWindow(FALSE);
	}
	if (Num[17].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT18)->SetWindowText(Num[17]);
		GetDlgItem(IDC_EDIT18)->EnableWindow(FALSE);
	}
	if (Num[18].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT19)->SetWindowText(Num[18]);
		GetDlgItem(IDC_EDIT19)->EnableWindow(FALSE);
	}
	if (Num[19].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT20)->SetWindowText(Num[19]);
		GetDlgItem(IDC_EDIT20)->EnableWindow(FALSE);
	}
	if (Num[20].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT21)->SetWindowText(Num[20]);
		GetDlgItem(IDC_EDIT21)->EnableWindow(FALSE);
	}
	if (Num[21].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT22)->SetWindowText(Num[21]);
		GetDlgItem(IDC_EDIT22)->EnableWindow(FALSE);
	}
	if (Num[22].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT23)->SetWindowText(Num[22]);
		GetDlgItem(IDC_EDIT23)->EnableWindow(FALSE);
	}
	if (Num[23].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT24)->SetWindowText(Num[23]);
		GetDlgItem(IDC_EDIT24)->EnableWindow(FALSE);
	}
	if (Num[24].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT25)->SetWindowText(Num[24]);
		GetDlgItem(IDC_EDIT25)->EnableWindow(FALSE);
	}
	if (Num[25].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT26)->SetWindowText(Num[25]);
		GetDlgItem(IDC_EDIT26)->EnableWindow(FALSE);
	}
	if (Num[26].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT27)->SetWindowText(Num[26]);
		GetDlgItem(IDC_EDIT27)->EnableWindow(FALSE);
	}
	if (Num[27].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT28)->SetWindowText(Num[27]);
		GetDlgItem(IDC_EDIT28)->EnableWindow(FALSE);
	}
	if (Num[28].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT29)->SetWindowText(Num[28]);
		GetDlgItem(IDC_EDIT29)->EnableWindow(FALSE);
	}
	if (Num[29].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT30)->SetWindowText(Num[29]);
		GetDlgItem(IDC_EDIT30)->EnableWindow(FALSE);
	}
	if (Num[30].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT31)->SetWindowText(Num[30]);
		GetDlgItem(IDC_EDIT31)->EnableWindow(FALSE);
	}
	if (Num[31].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT32)->SetWindowText(Num[31]);
		GetDlgItem(IDC_EDIT32)->EnableWindow(FALSE);
	}
	if (Num[32].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT33)->SetWindowText(Num[32]);
		GetDlgItem(IDC_EDIT33)->EnableWindow(FALSE);
	}
	if (Num[33].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT34)->SetWindowText(Num[33]);
		GetDlgItem(IDC_EDIT34)->EnableWindow(FALSE);

	}
	if (Num[34].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT35)->SetWindowText(Num[34]);
		GetDlgItem(IDC_EDIT35)->EnableWindow(FALSE);
	}
	if (Num[35].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT36)->SetWindowText(Num[35]);
		GetDlgItem(IDC_EDIT36)->EnableWindow(FALSE);
	}
	if (Num[36].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT37)->SetWindowText(Num[36]);
		GetDlgItem(IDC_EDIT37)->EnableWindow(FALSE);
	}
	if (Num[37].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT38)->SetWindowText(Num[37]);
		GetDlgItem(IDC_EDIT38)->EnableWindow(FALSE);
	}
	if (Num[38].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT39)->SetWindowText(Num[38]);
		GetDlgItem(IDC_EDIT39)->EnableWindow(FALSE);
	}
	if (Num[39].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT40)->SetWindowText(Num[39]);
		GetDlgItem(IDC_EDIT40)->EnableWindow(FALSE);
	}
	if (Num[40].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT41)->SetWindowText(Num[40]);
		GetDlgItem(IDC_EDIT41)->EnableWindow(FALSE);
	}
	if (Num[41].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT42)->SetWindowText(Num[41]);
		GetDlgItem(IDC_EDIT42)->EnableWindow(FALSE);
	}
	if (Num[42].Compare(_T("0")))
	{
		GetDlgItem(IDC_EDIT43)->SetWindowText(Num[42]);
		GetDlgItem(IDC_EDIT43)->EnableWindow(FALSE);
	}
	if (Num[43] != _T("0"))
	{
		GetDlgItem(IDC_EDIT44)->SetWindowText(Num[43]);
		GetDlgItem(IDC_EDIT44)->EnableWindow(FALSE);
	}
	if (Num[44] != _T("0"))
	{
		GetDlgItem(IDC_EDIT45)->SetWindowText(Num[44]);
		GetDlgItem(IDC_EDIT45)->EnableWindow(FALSE);
	}
	if (Num[45] != _T("0"))
	{
		GetDlgItem(IDC_EDIT46)->SetWindowText(Num[45]);
		GetDlgItem(IDC_EDIT46)->EnableWindow(FALSE);
	}
	if (Num[46] != _T("0"))
	{
		GetDlgItem(IDC_EDIT47)->SetWindowText(Num[46]);
		GetDlgItem(IDC_EDIT47)->EnableWindow(FALSE);
	}
	if (Num[47] != _T("0"))
	{
		GetDlgItem(IDC_EDIT48)->SetWindowText(Num[47]);
		GetDlgItem(IDC_EDIT48)->EnableWindow(FALSE);
	}
	if (Num[48] != _T("0"))
	{
		GetDlgItem(IDC_EDIT49)->SetWindowText(Num[48]);
		GetDlgItem(IDC_EDIT49)->EnableWindow(FALSE);
	}
	if (Num[49] != _T("0"))
	{
		GetDlgItem(IDC_EDIT50)->SetWindowText(Num[49]);
		GetDlgItem(IDC_EDIT50)->EnableWindow(FALSE);
	}
	if (Num[50] != _T("0"))
	{
		GetDlgItem(IDC_EDIT51)->SetWindowText(Num[50]);
		GetDlgItem(IDC_EDIT51)->EnableWindow(FALSE);
	}
	if (Num[51] != _T("0"))
	{
		GetDlgItem(IDC_EDIT52)->SetWindowText(Num[51]);
		GetDlgItem(IDC_EDIT52)->EnableWindow(FALSE);
	}
	if (Num[52] != _T("0"))
	{
		GetDlgItem(IDC_EDIT53)->SetWindowText(Num[52]);
		GetDlgItem(IDC_EDIT53)->EnableWindow(FALSE);
	}
	if (Num[53] != _T("0"))
	{
		GetDlgItem(IDC_EDIT54)->SetWindowText(Num[53]);
		GetDlgItem(IDC_EDIT54)->EnableWindow(FALSE);

	}
	if (Num[54] != _T("0"))
	{
		GetDlgItem(IDC_EDIT55)->SetWindowText(Num[54]);
		GetDlgItem(IDC_EDIT55)->EnableWindow(FALSE);
	}
	if (Num[55] != _T("0"))
	{
		GetDlgItem(IDC_EDIT56)->SetWindowText(Num[55]);
		GetDlgItem(IDC_EDIT56)->EnableWindow(FALSE);
	}
	if (Num[56] != _T("0"))
	{
		GetDlgItem(IDC_EDIT57)->SetWindowText(Num[56]);
		GetDlgItem(IDC_EDIT57)->EnableWindow(FALSE);
	}
	if (Num[57] != _T("0"))
	{
		GetDlgItem(IDC_EDIT58)->SetWindowText(Num[57]);
		GetDlgItem(IDC_EDIT58)->EnableWindow(FALSE);
	}
	if (Num[58] != _T("0"))
	{
		GetDlgItem(IDC_EDIT59)->SetWindowText(Num[58]);
		GetDlgItem(IDC_EDIT59)->EnableWindow(FALSE);
	}
	if (Num[59] != _T("0"))
	{
		GetDlgItem(IDC_EDIT60)->SetWindowText(Num[59]);
		GetDlgItem(IDC_EDIT60)->EnableWindow(FALSE);
	}
	if (Num[60] != _T("0"))
	{
		GetDlgItem(IDC_EDIT61)->SetWindowText(Num[60]);
		GetDlgItem(IDC_EDIT61)->EnableWindow(FALSE);
	}
	if (Num[61] != _T("0"))
	{
		GetDlgItem(IDC_EDIT62)->SetWindowText(Num[61]);
		GetDlgItem(IDC_EDIT62)->EnableWindow(FALSE);
	}
	if (Num[62] != _T("0"))
	{
		GetDlgItem(IDC_EDIT63)->SetWindowText(Num[62]);
		GetDlgItem(IDC_EDIT63)->EnableWindow(FALSE);
	}
	if (Num[63] != _T("0"))
	{
		GetDlgItem(IDC_EDIT64)->SetWindowText(Num[63]);
		GetDlgItem(IDC_EDIT64)->EnableWindow(FALSE);
	}
	if (Num[64] != _T("0"))
	{
		GetDlgItem(IDC_EDIT65)->SetWindowText(Num[64]);
		GetDlgItem(IDC_EDIT65)->EnableWindow(FALSE);
	}
	if (Num[65] != _T("0"))
	{
		GetDlgItem(IDC_EDIT66)->SetWindowText(Num[65]);
		GetDlgItem(IDC_EDIT66)->EnableWindow(FALSE);
	}
	if (Num[66] != _T("0"))
	{
		GetDlgItem(IDC_EDIT67)->SetWindowText(Num[66]);
		GetDlgItem(IDC_EDIT67)->EnableWindow(FALSE);
	}
	if (Num[67] != _T("0"))
	{
		GetDlgItem(IDC_EDIT68)->SetWindowText(Num[67]);
		GetDlgItem(IDC_EDIT68)->EnableWindow(FALSE);
	}
	if (Num[68] != _T("0"))
	{
		GetDlgItem(IDC_EDIT69)->SetWindowText(Num[68]);
		GetDlgItem(IDC_EDIT69)->EnableWindow(FALSE);
	}
	if (Num[69] != _T("0"))
	{
		GetDlgItem(IDC_EDIT70)->SetWindowText(Num[69]);
		GetDlgItem(IDC_EDIT70)->EnableWindow(FALSE);
	}
	if (Num[70] != _T("0"))
	{
		GetDlgItem(IDC_EDIT71)->SetWindowText(Num[70]);
		GetDlgItem(IDC_EDIT71)->EnableWindow(FALSE);
	}
	if (Num[71] != _T("0"))
	{
		GetDlgItem(IDC_EDIT72)->SetWindowText(Num[71]);
		GetDlgItem(IDC_EDIT72)->EnableWindow(FALSE);
	}
	if (Num[72] != _T("0"))
	{
		GetDlgItem(IDC_EDIT73)->SetWindowText(Num[72]);
		GetDlgItem(IDC_EDIT73)->EnableWindow(FALSE);
	}
	if (Num[73] != _T("0"))
	{
		GetDlgItem(IDC_EDIT74)->SetWindowText(Num[73]);
		GetDlgItem(IDC_EDIT74)->EnableWindow(FALSE);

	}
	if (Num[74] != _T("0"))
	{
		GetDlgItem(IDC_EDIT75)->SetWindowText(Num[74]);
		GetDlgItem(IDC_EDIT75)->EnableWindow(FALSE);
	}
	if (Num[75] != _T("0"))
	{
		GetDlgItem(IDC_EDIT76)->SetWindowText(Num[75]);
		GetDlgItem(IDC_EDIT76)->EnableWindow(FALSE);
	}
	if (Num[76] != _T("0"))
	{
		GetDlgItem(IDC_EDIT77)->SetWindowText(Num[76]);
		GetDlgItem(IDC_EDIT77)->EnableWindow(FALSE);
	}
	if (Num[77] != _T("0"))
	{
		GetDlgItem(IDC_EDIT78)->SetWindowText(Num[77]);
		GetDlgItem(IDC_EDIT78)->EnableWindow(FALSE);
	}
	if (Num[78] != _T("0"))
	{
		GetDlgItem(IDC_EDIT79)->SetWindowText(Num[78]);
		GetDlgItem(IDC_EDIT79)->EnableWindow(FALSE);
	}
	if (Num[79] != _T("0"))
	{
		GetDlgItem(IDC_EDIT80)->SetWindowText(Num[79]);
		GetDlgItem(IDC_EDIT80)->EnableWindow(FALSE);
	}
	if (Num[80] != _T("0"))
	{
		GetDlgItem(IDC_EDIT81)->SetWindowText(Num[80]);
		GetDlgItem(IDC_EDIT81)->EnableWindow(FALSE);
	}
}


void CSudokuGameDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Num[82];
	GetDlgItem(IDC_EDIT1)->GetWindowText(Num[0]);
	GetDlgItem(IDC_EDIT2)->GetWindowText(Num[1]);
	GetDlgItem(IDC_EDIT3)->GetWindowText(Num[2]);
	GetDlgItem(IDC_EDIT4)->GetWindowText(Num[3]);
	GetDlgItem(IDC_EDIT5)->GetWindowText(Num[4]);
	GetDlgItem(IDC_EDIT6)->GetWindowText(Num[5]);
	GetDlgItem(IDC_EDIT7)->GetWindowText(Num[6]);
	GetDlgItem(IDC_EDIT8)->GetWindowText(Num[7]);
	GetDlgItem(IDC_EDIT9)->GetWindowText(Num[8]);
	GetDlgItem(IDC_EDIT10)->GetWindowText(Num[9]);
	GetDlgItem(IDC_EDIT11)->GetWindowText(Num[10]);
	GetDlgItem(IDC_EDIT12)->GetWindowText(Num[11]);
	GetDlgItem(IDC_EDIT13)->GetWindowText(Num[12]);
	GetDlgItem(IDC_EDIT14)->GetWindowText(Num[13]);
	GetDlgItem(IDC_EDIT15)->GetWindowText(Num[14]);
	GetDlgItem(IDC_EDIT16)->GetWindowText(Num[15]);
	GetDlgItem(IDC_EDIT17)->GetWindowText(Num[16]);
	GetDlgItem(IDC_EDIT18)->GetWindowText(Num[17]);
	GetDlgItem(IDC_EDIT19)->GetWindowText(Num[18]);
	GetDlgItem(IDC_EDIT20)->GetWindowText(Num[19]);
	GetDlgItem(IDC_EDIT21)->GetWindowText(Num[20]);
	GetDlgItem(IDC_EDIT22)->GetWindowText(Num[21]);
	GetDlgItem(IDC_EDIT23)->GetWindowText(Num[22]);
	GetDlgItem(IDC_EDIT24)->GetWindowText(Num[23]);
	GetDlgItem(IDC_EDIT25)->GetWindowText(Num[24]);
	GetDlgItem(IDC_EDIT26)->GetWindowText(Num[25]);
	GetDlgItem(IDC_EDIT27)->GetWindowText(Num[26]);
	GetDlgItem(IDC_EDIT28)->GetWindowText(Num[27]);
	GetDlgItem(IDC_EDIT29)->GetWindowText(Num[28]);
	GetDlgItem(IDC_EDIT30)->GetWindowText(Num[29]);
	GetDlgItem(IDC_EDIT31)->GetWindowText(Num[30]);
	GetDlgItem(IDC_EDIT32)->GetWindowText(Num[31]);
	GetDlgItem(IDC_EDIT33)->GetWindowText(Num[32]);
	GetDlgItem(IDC_EDIT34)->GetWindowText(Num[33]);
	GetDlgItem(IDC_EDIT35)->GetWindowText(Num[34]);
	GetDlgItem(IDC_EDIT36)->GetWindowText(Num[35]);
	GetDlgItem(IDC_EDIT37)->GetWindowText(Num[36]);
	GetDlgItem(IDC_EDIT38)->GetWindowText(Num[37]);
	GetDlgItem(IDC_EDIT39)->GetWindowText(Num[38]);
	GetDlgItem(IDC_EDIT40)->GetWindowText(Num[39]);
	GetDlgItem(IDC_EDIT41)->GetWindowText(Num[40]);
	GetDlgItem(IDC_EDIT42)->GetWindowText(Num[41]);
	GetDlgItem(IDC_EDIT43)->GetWindowText(Num[42]);
	GetDlgItem(IDC_EDIT44)->GetWindowText(Num[43]);
	GetDlgItem(IDC_EDIT45)->GetWindowText(Num[44]);
	GetDlgItem(IDC_EDIT46)->GetWindowText(Num[45]);
	GetDlgItem(IDC_EDIT47)->GetWindowText(Num[46]);
	GetDlgItem(IDC_EDIT48)->GetWindowText(Num[47]);
	GetDlgItem(IDC_EDIT49)->GetWindowText(Num[48]);
	GetDlgItem(IDC_EDIT50)->GetWindowText(Num[49]);
	GetDlgItem(IDC_EDIT51)->GetWindowText(Num[50]);
	GetDlgItem(IDC_EDIT52)->GetWindowText(Num[51]);
	GetDlgItem(IDC_EDIT53)->GetWindowText(Num[52]);
	GetDlgItem(IDC_EDIT54)->GetWindowText(Num[53]);
	GetDlgItem(IDC_EDIT55)->GetWindowText(Num[54]);
	GetDlgItem(IDC_EDIT56)->GetWindowText(Num[55]);
	GetDlgItem(IDC_EDIT57)->GetWindowText(Num[56]);
	GetDlgItem(IDC_EDIT58)->GetWindowText(Num[57]);
	GetDlgItem(IDC_EDIT59)->GetWindowText(Num[58]);
	GetDlgItem(IDC_EDIT60)->GetWindowText(Num[59]);
	GetDlgItem(IDC_EDIT61)->GetWindowText(Num[60]);
	GetDlgItem(IDC_EDIT62)->GetWindowText(Num[61]);
	GetDlgItem(IDC_EDIT63)->GetWindowText(Num[62]);
	GetDlgItem(IDC_EDIT64)->GetWindowText(Num[63]);
	GetDlgItem(IDC_EDIT65)->GetWindowText(Num[64]);
	GetDlgItem(IDC_EDIT66)->GetWindowText(Num[65]);
	GetDlgItem(IDC_EDIT67)->GetWindowText(Num[66]);
	GetDlgItem(IDC_EDIT68)->GetWindowText(Num[67]);
	GetDlgItem(IDC_EDIT69)->GetWindowText(Num[68]);
	GetDlgItem(IDC_EDIT70)->GetWindowText(Num[69]);
	GetDlgItem(IDC_EDIT71)->GetWindowText(Num[70]);
	GetDlgItem(IDC_EDIT72)->GetWindowText(Num[71]);
	GetDlgItem(IDC_EDIT73)->GetWindowText(Num[72]);
	GetDlgItem(IDC_EDIT74)->GetWindowText(Num[73]);
	GetDlgItem(IDC_EDIT75)->GetWindowText(Num[74]);
	GetDlgItem(IDC_EDIT76)->GetWindowText(Num[75]);
	GetDlgItem(IDC_EDIT77)->GetWindowText(Num[76]);
	GetDlgItem(IDC_EDIT78)->GetWindowText(Num[77]);
	GetDlgItem(IDC_EDIT79)->GetWindowText(Num[78]);
	GetDlgItem(IDC_EDIT80)->GetWindowText(Num[79]);
	GetDlgItem(IDC_EDIT81)->GetWindowText(Num[80]);

	for (int js = 0;js < 81;js++)
	{
		if (Num[js][0] > '0'&&Num[js][0] <= '9'&&Num[js].GetLength() == 1)
		{
			continue;
		}
		else
		{
			Error_Rep ER;
			ER.DoModal();
			return;
		}
	}


	for (int i = 0,js =0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++,js++)
		{
			if (_ttoi(Num[js]) == Record[js])
			{
				continue;
			}
			else
			{
				Error_Answer EA;
				EA.DoModal();
				return;
			}
		}
	}

	Won won;
	won.DoModal();

}
