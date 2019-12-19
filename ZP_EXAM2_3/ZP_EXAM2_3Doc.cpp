
// ZP_EXAM2_3Doc.cpp : CZP_EXAM2_3Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CZP_EXAM2_3Doc 构造/析构

CZP_EXAM2_3Doc::CZP_EXAM2_3Doc()
{
	// TODO: 在此添加一次性构造代码
	//初始化数据
	//左下角位置
	m_BottomLeftX=200;
	m_BottomLeftY=300;
	//X轴间隔，Y轴间隔
	m_SpaceX=50;
	m_SpaceY=20;
	//月份数量（可以理解为最大月份）
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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CZP_EXAM2_3Doc 序列化

void CZP_EXAM2_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CZP_EXAM2_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CZP_EXAM2_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CZP_EXAM2_3Doc 诊断

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


// CZP_EXAM2_3Doc 命令
void CZP_EXAM2_3Doc::AddPro(int grapg,int output[],int r,int g,int b)
{
	CProduct pro;
	pro.SetData(grapg,output,r,g,b);
	m_vecPro.push_back(pro);
}