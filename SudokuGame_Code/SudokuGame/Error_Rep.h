#pragma once


// Error_Rep �Ի���

class Error_Rep : public CDialogEx
{
	DECLARE_DYNAMIC(Error_Rep)

public:
	Error_Rep(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Error_Rep();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
