#pragma once
#include "afxwin.h"


// CValueDialog �Ի���

class CValueDialog : public CDialog
{
	DECLARE_DYNAMIC(CValueDialog)
public:
	double Value;
	CString strShow;

public:
	CValueDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CValueDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_edtValue;
	CEdit m_edtShow;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk2();
};
