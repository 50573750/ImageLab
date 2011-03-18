// MainFrm.h : CMainFrame ��Ľӿ�
//

#include "ImageBase.h"

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	CImageBase ibDoc;
	afx_msg void OnOpenImage();
	afx_msg void OnGray();
	afx_msg void OnPart();
	afx_msg void OnLinarTrans();
	bool Doit(void);
	afx_msg void OnLogTrans();
	afx_msg void OnLogStdTrans();
	afx_msg void OnExpTrans();
	afx_msg void OnThreshold();
	afx_msg void OnMenu32797();
	afx_msg void OnStretchNearest();
	afx_msg void OnStretchBilinar();
	afx_msg void OnXY();
};


