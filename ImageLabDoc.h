// ImageLabDoc.h : CImageLabDoc ��Ľӿ�
//


#pragma once


class CImageLabDoc : public CDocument
{
protected: // �������л�����
	CImageLabDoc();
	DECLARE_DYNCREATE(CImageLabDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CImageLabDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


