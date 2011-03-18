// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "ImageLab.h"
#include "ValueDialog.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_OPEN_IMAGE, &CMainFrame::OnOpenImage)
	ON_COMMAND(ID_GRAY, &CMainFrame::OnGray)
	ON_COMMAND(ID_PART, &CMainFrame::OnPart)
	ON_COMMAND(ID_LINAR_TRANS, &CMainFrame::OnLinarTrans)
	ON_COMMAND(ID_LOG_TRANS, &CMainFrame::OnLogTrans)
	ON_COMMAND(ID_LOG_STD_TRANS, &CMainFrame::OnLogStdTrans)
	ON_COMMAND(ID_EXP_TRANS, &CMainFrame::OnExpTrans)
	ON_COMMAND(ID_THRESHOLD, &CMainFrame::OnThreshold)
	ON_COMMAND(ID_Menu32797, &CMainFrame::OnMenu32797)
	ON_COMMAND(ID_STRETCH_NEAREST, &CMainFrame::OnStretchNearest)
	ON_COMMAND(ID_STRETCH_BILINAR, &CMainFrame::OnStretchBilinar)
	ON_COMMAND(ID_X_Y, &CMainFrame::OnXY)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetMenu(NULL);

	CMenu menuMain;
	menuMain.LoadMenu(IDR_MAINMENU);

	SetMenu(&menuMain);

	menuMain.Detach();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������




void CMainFrame::OnOpenImage()
{
	CFileDialog dlgFile(true,NULL,NULL,NULL,L"BMP ͼ���ļ�|*.bmp||");
	
	if (dlgFile.DoModal() == IDOK)
	{
		CImageBase ib;
		ibDoc.Load(dlgFile.GetPathName());
		//ibDoc.ModelFrom(&ib);

		GetActiveView()->Invalidate();
	}
}

void CMainFrame::OnGray()
{
	ibDoc.Gray();

	GetActiveView()->Invalidate();
}

void CMainFrame::OnPart()
{
	CRect rect;

	CValueDialog vd;
	vd.strShow = L"������ X ��λ�ã�";
	if (vd.DoModal() == IDOK)
	{
		rect.left = vd.Value;
	}
	else
	{
		return;
	}

	vd.strShow = L"������ Y ��λ�ã�";
	if (vd.DoModal() == IDOK)
	{
		rect.top = vd.Value;
	}
	else
	{
		return;
	}

	vd.strShow = L"������ Width ��λ�ã�";
	if (vd.DoModal() == IDOK)
	{
		rect.right = rect.left + vd.Value;
	}
	else
	{
		return;
	}

	vd.strShow = L"������ Height ��λ�ã�";
	if (vd.DoModal() == IDOK)
	{
		rect.bottom = rect.top + vd.Value;
	}
	else
	{
		return;
	}

	ibDoc.Part(rect);

	GetActiveView()->Invalidate();
}

void CMainFrame::OnLinarTrans()
{
	Doit();

	CValueDialog vd;
	vd.strShow = L"���������Ա任��ϵ��ֵ��";

	double dFa = 0.0;

	if (vd.DoModal() == IDOK)
	{
		dFa = vd.Value;
	}
	else
	{
		return;
	}

	vd.strShow = L"���������Ա任�Ľھࣺ";

	double dFb = 0.0;

	if (vd.DoModal() == IDOK)
	{
		dFb = vd.Value;
	}
	else
	{
		return;
	}

	ibDoc.LinarTrans(dFa,dFb);

	GetActiveView()->Invalidate();
}

bool CMainFrame::Doit(void)
{
	return true;
}

void CMainFrame::OnLogTrans()
{
	Doit();

	CValueDialog vd;
	vd.strShow = L"���������ϵ����";

	double dLog = 0.0;

	if (vd.DoModal() == IDOK)
	{
		dLog = vd.Value;
	}
	else
	{
		return;
	}

	ibDoc.LogTrans(dLog);

	GetActiveView()->Invalidate();
}

void CMainFrame::OnLogStdTrans()
{
	Doit();

	ibDoc.LogTransStd();

	GetActiveView()->Invalidate();
}

void CMainFrame::OnExpTrans()
{
	Doit();

	CValueDialog vd;
	vd.strShow = L"������ָ���任��ָ��ϵ����";

	double dExp = 0.0;

	if (vd.DoModal() == IDOK)
	{
		dExp = vd.Value;
	}
	else
	{
		return;
	}

	vd.strShow = L"������ָ���任�ļ�Ȩϵ����";

	double dR = 0.0;

	if (vd.DoModal() == IDOK)
	{
		dR = vd.Value;
	}
	else
	{
		return;
	}

	ibDoc.ExpTrans(dExp,dR);

	GetActiveView()->Invalidate();
}

void CMainFrame::OnThreshold()
{
	Doit();

	CValueDialog vd;
	vd.strShow = L"��������ֵ��";

	double dThre = 0.0;

	if (vd.DoModal() == IDOK)
	{
		dThre = vd.Value;
	}
	else
	{
		return;
	}

	ibDoc.Threshold(int(dThre));

	GetActiveView()->Invalidate();
}

void CMainFrame::OnMenu32797()
{
	Doit();

	ibDoc.HistEq();

	GetActiveView()->Invalidate();
}

void CMainFrame::OnStretchNearest()
{
	Doit();

	CRect rct = CRect(0,0,0,0);

	CValueDialog vd;
	
	vd.strShow = L"������ԭ���ε�Left��";
	if (vd.DoModal() == IDOK)
	{
		rct.left = int(vd.Value);
	}
	else
	{
		return;
	}

	vd.strShow = L"������ԭ���ε�Right��";
	if (vd.DoModal() == IDOK)
	{
		rct.right = int(vd.Value);
	}
	else
	{
		return;
	}

	vd.strShow = L"������ԭ���ε�Top��";
	if (vd.DoModal() == IDOK)
	{
		rct.top = int(vd.Value);
	}
	else
	{
		return;
	}

	vd.strShow = L"������ԭ���ε�Bottom��";
	if (vd.DoModal() == IDOK)
	{
		rct.bottom = int(vd.Value);
	}
	else
	{
		return;
	}

	ibDoc.StretchNearest(rct,CRect(0,0,ibDoc.GetWidth(),ibDoc.GetHeight()));

	GetActiveView()->Invalidate();
}

void CMainFrame::OnStretchBilinar()
{
	Doit();

	CRect rct = CRect(0,0,0,0);

	CValueDialog vd;

	vd.strShow = L"������ԭ���ε�Left��";
	if (vd.DoModal() == IDOK)
	{
		rct.left = int(vd.Value);
	}
	else
	{
		return;
	}

	vd.strShow = L"������ԭ���ε�Right��";
	if (vd.DoModal() == IDOK)
	{
		rct.right = int(vd.Value);
	}
	else
	{
		return;
	}

	vd.strShow = L"������ԭ���ε�Top��";
	if (vd.DoModal() == IDOK)
	{
		rct.top = int(vd.Value);
	}
	else
	{
		return;
	}

	vd.strShow = L"������ԭ���ε�Bottom��";
	if (vd.DoModal() == IDOK)
	{
		rct.bottom = int(vd.Value);
	}
	else
	{
		return;
	}


	ibDoc.StretchBilinar(rct,CRect(0,0,ibDoc.GetWidth(),ibDoc.GetHeight()));

	GetActiveView()->Invalidate();
}

void CMainFrame::OnXY()
{
	ibDoc.Threshold(127);
	ibDoc.ReduceEdge(100);
	ibDoc.Convex(true);

	GetActiveView()->Invalidate();
}
