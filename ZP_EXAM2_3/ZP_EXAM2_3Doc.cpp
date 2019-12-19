
// ZP_EXAM2_3Doc.cpp : CZP_EXAM2_3Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZP_EXAM2_3.h"
#endif

#include "ZP_EXAM2_3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZP_EXAM2_3Doc

IMPLEMENT_DYNCREATE(CZP_EXAM2_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CZP_EXAM2_3Doc, CDocument)
END_MESSAGE_MAP()


// CZP_EXAM2_3Doc ����/����

CZP_EXAM2_3Doc::CZP_EXAM2_3Doc()
{
	// TODO: �ڴ����һ���Թ������
	//��ʼ������
	//���½�λ��
	m_BottomLeftX=200;
	m_BottomLeftY=300;
	//X������Y����
	m_SpaceX=50;
	m_SpaceY=20;
	//�·��������������Ϊ����·ݣ�
	m_MouthCounts=5;

	int m_Output[5];
	m_Output[0]=40;
	m_Output[1]=37;
	m_Output[2]=23;
	m_Output[3]=23;
	m_Output[4]=40;
	AddPro(0,m_Output,255,0,0);

	m_Output[0]=30;
	m_Output[1]=26;
	m_Output[2]=27;
	m_Output[3]=35;
	m_Output[4]=24;
	AddPro(1,m_Output,0,255,0);

	m_Output[0]=28;
	m_Output[1]=21;
	m_Output[2]=38;
	m_Output[3]=37;
	m_Output[4]=21;
	AddPro(2,m_Output,0,0,255);

	m_Output[0]=10;
	m_Output[1]=15;
	m_Output[2]=17;
	m_Output[3]=10;
	m_Output[4]=26;
	AddPro(2,m_Output,0,255,255);

	m_Output[0]=15;
	m_Output[1]=6;
	m_Output[2]=27;
	m_Output[3]=8;
	m_Output[4]=6;
	AddPro(0,m_Output,255,0,255);
}

CZP_EXAM2_3Doc::~CZP_EXAM2_3Doc()
{
}

BOOL CZP_EXAM2_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CZP_EXAM2_3Doc ���л�

void CZP_EXAM2_3Doc::Serialize(CArchive& ar)
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

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CZP_EXAM2_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CZP_EXAM2_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CZP_EXAM2_3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CZP_EXAM2_3Doc ���

#ifdef _DEBUG
void CZP_EXAM2_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZP_EXAM2_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CZP_EXAM2_3Doc ����
void CZP_EXAM2_3Doc::AddPro(int grapg,int output[],int r,int g,int b)
{
	CProduct pro;
	pro.SetData(grapg,output,r,g,b);
	m_vecPro.push_back(pro);
}