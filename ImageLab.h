// ImageLab.h : ImageLab Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CImageLabApp:
// �йش����ʵ�֣������ ImageLab.cpp
//

class CImageLabApp : public CWinApp
{
public:
	CImageLabApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CImageLabApp theApp;