// ImageLabView.h : CImageLabView ��Ľӿ�
//


#pragma once


class CImageLabView : public CView
{
protected: // �������л�����
	CImageLabView();
	DECLARE_DYNCREATE(CImageLabView)

// ����
public:
	CImageLabDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CImageLabView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ImageLabView.cpp �еĵ��԰汾
inline CImageLabDoc* CImageLabView::GetDocument() const
   { return reinterpret_cast<CImageLabDoc*>(m_pDocument); }
#endif

