#pragma once


// Error_Answer �Ի���

class Error_Answer : public CDialogEx
{
	DECLARE_DYNAMIC(Error_Answer)

public:
	Error_Answer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Error_Answer();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
