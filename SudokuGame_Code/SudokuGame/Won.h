#pragma once


// Won �Ի���

class Won : public CDialogEx
{
	DECLARE_DYNAMIC(Won)

public:
	Won(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Won();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
