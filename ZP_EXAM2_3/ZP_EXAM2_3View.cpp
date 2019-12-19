
// ZP_EXAM2_3View.cpp : CZP_EXAM2_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZP_EXAM2_3.h"
#endif

#include "ZP_EXAM2_3Doc.h"
#include "ZP_EXAM2_3View.h"
#include "Line.h"
#include "Myfounction.h"
#include "ObjAdd.h"
#include "ObjMng.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//void DrawIco(CDC *pDC,int x,int y,int type,COLORREF color);
void DrawIco(CDC *pDC,int x,int y,int type,int r,int g,int b);

// CZP_EXAM2_3View

IMPLEMENT_DYNCREATE(CZP_EXAM2_3View, CView)

BEGIN_MESSAGE_MAP(CZP_EXAM2_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ADDOBJ, &CZP_EXAM2_3View::OnAddobj)
	ON_COMMAND(ID_MNGOBJ, &CZP_EXAM2_3View::OnMngobj)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CZP_EXAM2_3View ����/����

CZP_EXAM2_3View::CZP_EXAM2_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CZP_EXAM2_3View::~CZP_EXAM2_3View()
{
}

BOOL CZP_EXAM2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZP_EXAM2_3View ����
CString number2char(int number);
void CZP_EXAM2_3View::OnDraw(CDC* pDC)
{
	CZP_EXAM2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	//��ͼ��
	CChart v_Chart;
	//v_Chart.DrawLine(pDC);
	for (int i = 0; i < 10; i++)
	{
		CLine line;
		//��10������
		line.DrawLine(pDC,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,pDoc->m_BottomLeftX+pDoc->m_SpaceX*pDoc->m_MouthCounts,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,1,0,0,0);
	}
	CLine v_line;
	//������
	v_line.DrawLine(pDC,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY-pDoc->m_SpaceY*10,1,0,0,0);


	//v_Chart.DrawTitle(pDC);
	//��ͼ�����
	//�ı�����
	pDC->SetTextAlign(TA_CENTER);
	CString v_title;
	v_title="������������ͼ";
	pDC->TextOutW(pDoc->m_BottomLeftX+pDoc->m_SpaceX*pDoc->m_MouthCounts/2,pDoc->m_BottomLeftY-pDoc->m_SpaceY*11,v_title);

	//���·�
	pDC->SetTextAlign(TA_CENTER);
	CString v_month;
	v_month="ĳ��";
	//v_Chart.DrawMonthX(pDC);
	for (int i = 0; i < pDoc->m_MouthCounts; i++)
	{
		//����ת����
		v_month=number2char(i+1)+_T("��");
		//���·�
		pDC->TextOutW(pDoc->m_BottomLeftX+pDoc->m_SpaceX/2+pDoc->m_SpaceX*i,pDoc->m_BottomLeftY+pDoc->m_SpaceY,v_month);
	}
	
	
	//v_Chart.DrawY(pDC);
	//��Y������
	//�ı��Ҷ���
	pDC->SetTextAlign(TA_RIGHT);
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(L"%d",i*5);
		pDC->TextOutW(pDoc->m_BottomLeftX-10-8,pDoc->m_BottomLeftY-i*pDoc->m_SpaceY-7,str);
	}

	//��Y��̶�
	for (int i = 0; i <10; i++)
	{
		int over=5;
		CLine line;
		line.DrawLine(pDC,pDoc->m_BottomLeftX-over,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,1,0,0,0);
	}

	//��X��̶�
	for (int i = 0; i < 6; i++)
	{
		//�̶ȳ�������5����
		int over=5;
		CLine line;
		line.DrawLine(pDC,pDoc->m_BottomLeftX+pDoc->m_SpaceX*i,pDoc->m_BottomLeftY,pDoc->m_BottomLeftX+pDoc->m_SpaceX*i,pDoc->m_BottomLeftY+over,1,0,0,0);

	}


	//��Ʒ������
	vector<CProduct>::iterator v;
	//ָ���һ��
	v = pDoc->m_vecPro.begin();
	//������Ʒ
	CLine line;
	for (;v!=pDoc->m_vecPro.end(); v++)
	{
		//����Ʒ����
		for (int i = 0; i < pDoc->m_MouthCounts-1; i++)
		{
			int x1=pDoc->m_BottomLeftX+pDoc->m_SpaceX/2+pDoc->m_SpaceX*i;
			int y1=pDoc->m_BottomLeftY-pDoc->m_SpaceY/5*v->m_Output[i];
			int x2=pDoc->m_BottomLeftX+pDoc->m_SpaceX/2+pDoc->m_SpaceX*(i+1);
			int y2=pDoc->m_BottomLeftY-pDoc->m_SpaceY/5*v->m_Output[i+1];
			line.DrawLine(pDC,x1,y1,x2,y2,3,v->m_r,v->m_g,v->m_b);
			DrawIco(pDC,x1,y1,v->m_Graph,v->m_r,v->m_g,v->m_b);
			//�������һ�����ߵ�ʱ����Ҫ�����һ����
			if (i==pDoc->m_MouthCounts-1-1)
			{
				DrawIco(pDC,x2,y2,v->m_Graph,v->m_r,v->m_g,v->m_b);
			}
		}

	}
	
	
	//���Ҳ��Ʒ������Ϣ
	//�ı��������
	pDC->SetTextAlign(TA_LEFT);
	//���Ͻǵĵ�
	POINT left_top;
	//���㷨�������Ͻǵĵ�ʹ�ı���ʾ���У���ӣ��޸Ķ�����У�
	left_top.x=pDoc->m_BottomLeftX+pDoc->m_SpaceX*pDoc->m_MouthCounts+5;
	left_top.y=pDoc->m_BottomLeftY-(pDoc->m_SpaceY*10+pDoc->m_vecPro.size()*15)/2;
	//������ָ����������ĵ�һ��ʵ�����������װ�Ĳ�Ʒ���ݣ�
	v = pDoc->m_vecPro.begin();
	//��¼ʱ�ڼ�����Ʒ������ƫ����
	int ProNum=0;
	for (;v!=pDoc->m_vecPro.end(); v++)
	{
		//����
		line.DrawLine(pDC,left_top.x,left_top.y+ProNum*15,left_top.x+19,left_top.y+ProNum*15,3,v->m_r,v->m_g,v->m_b);
		//��ȫ���Զ��庯����ͼ��
		DrawIco(pDC,left_top.x+10,left_top.y+ProNum*15,v->m_Graph,v->m_r,v->m_g,v->m_b);
		//��ʽ���ı���Ϣ
		CString str;
		str.Format(_T("��Ʒ%d"),ProNum+1);
		//���ı�
		pDC->TextOut(left_top.x+20,left_top.y-8+ProNum*15,str);
		ProNum++;
	}
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}
void CZP_EXAM2_3View::DrawPro(CZP_EXAM2_3Doc* pDoc,CDC * pDC)
{
	
}

// CZP_EXAM2_3View ��ӡ

BOOL CZP_EXAM2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CZP_EXAM2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CZP_EXAM2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CZP_EXAM2_3View ���

#ifdef _DEBUG
void CZP_EXAM2_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_EXAM2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_EXAM2_3Doc* CZP_EXAM2_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_EXAM2_3Doc)));
	return (CZP_EXAM2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZP_EXAM2_3View ��Ϣ�������


void CZP_EXAM2_3View::OnAddobj()
{
	// TODO: �ڴ���������������
	CObjAdd v_ObjAdd;
	v_ObjAdd.DoModal();
	CZP_EXAM2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDoc->UpdateAllViews(NULL);
	CString str;
	str.Format(TEXT("һ����%d������"),pDoc->m_vecPro.size());
	MessageBox(str);
	
}


void CZP_EXAM2_3View::OnMngobj()
{
	// TODO: �ڴ���������������
	CString str;
	str.Format(TEXT("��˫����ɫ�����Զ�����й���"));
	MessageBox(str);
}


void CZP_EXAM2_3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pdc = GetDC();
	//��ȡ������ص�
	COLORREF color = pdc->GetPixel(point);
	//��ȡ��ɫֵ
	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);


	CZP_EXAM2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//��Ʒ
	vector<CProduct>::iterator v;
	v = pDoc->m_vecPro.begin();
	//������Ʒ
	CLine line;
	for (;v!=pDoc->m_vecPro.end(); v++)
	{
		//������ɫ�ж�ѡ���ĸ���Ʒ
		if (v->m_r==r&&v->m_g==g&&v->m_b==b)
		{
			CObjMng v_ObjMng;
			//��ʾ���ݵ��Ի���
			v_ObjMng.v=v;
			v_ObjMng.m_R=v->m_r;
			v_ObjMng.m_G=v->m_g;
			v_ObjMng.m_B=v->m_b;
			v_ObjMng.m_Type=v->m_Graph;
			v_ObjMng.m_M1=v->m_Output[0];
			v_ObjMng.m_M2=v->m_Output[1];
			v_ObjMng.m_M3=v->m_Output[2];
			v_ObjMng.m_M4=v->m_Output[3];
			v_ObjMng.m_M5=v->m_Output[4];
			UpdateData(FALSE);
			//��ʾ�Ի���
			v_ObjMng.DoModal();
			break;
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}
