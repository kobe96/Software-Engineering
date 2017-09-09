#pragma once


// Error_Answer 对话框

class Error_Answer : public CDialogEx
{
	DECLARE_DYNAMIC(Error_Answer)

public:
	Error_Answer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Error_Answer();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
