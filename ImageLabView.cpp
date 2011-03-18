// ImageLabView.cpp : CImageLabView ���ʵ��
//

#include "stdafx.h"
#include "ImageLab.h"

#include "ImageLabDoc.h"
#include "ImageLabView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageLabView

IMPLEMENT_DYNCREATE(CImageLabView, CView)

BEGIN_MESSAGE_MAP(CImageLabView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CImageLabView ����/����

CImageLabView::CImageLabView()
{
	// TODO: �ڴ˴���ӹ������

}

CImageLabView::~CImageLabView()
{
}

BOOL CImageLabView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CImageLabView ����

void CImageLabView::OnDraw(CDC* pDC)
{
	CImageLabDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* mf = (CMainFrame*)AfxGetMainWnd();

	mf->ibDoc.Display(pDC);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CImageLabView ��ӡ

BOOL CImageLabView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CImageLabView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CImageLabView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CImageLabView ���

#ifdef _DEBUG
void CImageLabView::AssertValid() const
{
	CView::AssertValid();
}

void CImageLabView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageLabDoc* CImageLabView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageLabDoc)));
	return (CImageLabDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageLabView ��Ϣ�������
