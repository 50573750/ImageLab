// ImageLabDoc.cpp : CImageLabDoc ���ʵ��
//

#include "stdafx.h"
#include "ImageLab.h"

#include "ImageLabDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageLabDoc

IMPLEMENT_DYNCREATE(CImageLabDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageLabDoc, CDocument)
END_MESSAGE_MAP()


// CImageLabDoc ����/����

CImageLabDoc::CImageLabDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CImageLabDoc::~CImageLabDoc()
{
}

BOOL CImageLabDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CImageLabDoc ���л�

void CImageLabDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CImageLabDoc ���

#ifdef _DEBUG
void CImageLabDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageLabDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageLabDoc ����
