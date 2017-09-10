#pragma once


// Error_Rep 对话框

class Error_Rep : public CDialogEx
{
	DECLARE_DYNAMIC(Error_Rep)

public:
	Error_Rep(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Error_Rep();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
