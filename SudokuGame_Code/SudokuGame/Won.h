#pragma once


// Won 对话框

class Won : public CDialogEx
{
	DECLARE_DYNAMIC(Won)

public:
	Won(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Won();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
