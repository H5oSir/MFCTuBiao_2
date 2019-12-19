
// ZP_EXAM2_3View.cpp : CZP_EXAM2_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ADDOBJ, &CZP_EXAM2_3View::OnAddobj)
	ON_COMMAND(ID_MNGOBJ, &CZP_EXAM2_3View::OnMngobj)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CZP_EXAM2_3View 构造/析构

CZP_EXAM2_3View::CZP_EXAM2_3View()
{
	// TODO: 在此处添加构造代码

}

CZP_EXAM2_3View::~CZP_EXAM2_3View()
{
}

BOOL CZP_EXAM2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZP_EXAM2_3View 绘制
CString number2char(int number);
void CZP_EXAM2_3View::OnDraw(CDC* pDC)
{
	CZP_EXAM2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	//画图表
	CChart v_Chart;
	//v_Chart.DrawLine(pDC);
	for (int i = 0; i < 10; i++)
	{
		CLine line;
		//画10个横线
		line.DrawLine(pDC,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,pDoc->m_BottomLeftX+pDoc->m_SpaceX*pDoc->m_MouthCounts,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,1,0,0,0);
	}
	CLine v_line;
	//画竖线
	v_line.DrawLine(pDC,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY-pDoc->m_SpaceY*10,1,0,0,0);


	//v_Chart.DrawTitle(pDC);
	//画图表标题
	//文本居中
	pDC->SetTextAlign(TA_CENTER);
	CString v_title;
	v_title="车床生产数据图";
	pDC->TextOutW(pDoc->m_BottomLeftX+pDoc->m_SpaceX*pDoc->m_MouthCounts/2,pDoc->m_BottomLeftY-pDoc->m_SpaceY*11,v_title);

	//画月份
	pDC->SetTextAlign(TA_CENTER);
	CString v_month;
	v_month="某月";
	//v_Chart.DrawMonthX(pDC);
	for (int i = 0; i < pDoc->m_MouthCounts; i++)
	{
		//数字转中文
		v_month=number2char(i+1)+_T("月");
		//画月份
		pDC->TextOutW(pDoc->m_BottomLeftX+pDoc->m_SpaceX/2+pDoc->m_SpaceX*i,pDoc->m_BottomLeftY+pDoc->m_SpaceY,v_month);
	}
	
	
	//v_Chart.DrawY(pDC);
	//画Y轴数字
	//文本右对齐
	pDC->SetTextAlign(TA_RIGHT);
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(L"%d",i*5);
		pDC->TextOutW(pDoc->m_BottomLeftX-10-8,pDoc->m_BottomLeftY-i*pDoc->m_SpaceY-7,str);
	}

	//画Y轴刻度
	for (int i = 0; i <10; i++)
	{
		int over=5;
		CLine line;
		line.DrawLine(pDC,pDoc->m_BottomLeftX-over,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,pDoc->m_BottomLeftX,pDoc->m_BottomLeftY-pDoc->m_SpaceY*i,1,0,0,0);
	}

	//画X轴刻度
	for (int i = 0; i < 6; i++)
	{
		//刻度超出部分5像素
		int over=5;
		CLine line;
		line.DrawLine(pDC,pDoc->m_BottomLeftX+pDoc->m_SpaceX*i,pDoc->m_BottomLeftY,pDoc->m_BottomLeftX+pDoc->m_SpaceX*i,pDoc->m_BottomLeftY+over,1,0,0,0);

	}


	//产品迭代器
	vector<CProduct>::iterator v;
	//指向第一个
	v = pDoc->m_vecPro.begin();
	//遍历产品
	CLine line;
	for (;v!=pDoc->m_vecPro.end(); v++)
	{
		//画产品曲线
		for (int i = 0; i < pDoc->m_MouthCounts-1; i++)
		{
			int x1=pDoc->m_BottomLeftX+pDoc->m_SpaceX/2+pDoc->m_SpaceX*i;
			int y1=pDoc->m_BottomLeftY-pDoc->m_SpaceY/5*v->m_Output[i];
			int x2=pDoc->m_BottomLeftX+pDoc->m_SpaceX/2+pDoc->m_SpaceX*(i+1);
			int y2=pDoc->m_BottomLeftY-pDoc->m_SpaceY/5*v->m_Output[i+1];
			line.DrawLine(pDC,x1,y1,x2,y2,3,v->m_r,v->m_g,v->m_b);
			DrawIco(pDC,x1,y1,v->m_Graph,v->m_r,v->m_g,v->m_b);
			//当画最后一根曲线的时候，需要画最后一个点
			if (i==pDoc->m_MouthCounts-1-1)
			{
				DrawIco(pDC,x2,y2,v->m_Graph,v->m_r,v->m_g,v->m_b);
			}
		}

	}
	
	
	//画右侧产品文字信息
	//文本向左对齐
	pDC->SetTextAlign(TA_LEFT);
	//左上角的点
	POINT left_top;
	//用算法计算左上角的点使文本显示居中（添加，修改都会居中）
	left_top.x=pDoc->m_BottomLeftX+pDoc->m_SpaceX*pDoc->m_MouthCounts+5;
	left_top.y=pDoc->m_BottomLeftY-(pDoc->m_SpaceY*10+pDoc->m_vecPro.size()*15)/2;
	//迭代器指向容器里面的第一个实例（设计用类装的产品数据）
	v = pDoc->m_vecPro.begin();
	//记录时第几个产品，计算偏移量
	int ProNum=0;
	for (;v!=pDoc->m_vecPro.end(); v++)
	{
		//画线
		line.DrawLine(pDC,left_top.x,left_top.y+ProNum*15,left_top.x+19,left_top.y+ProNum*15,3,v->m_r,v->m_g,v->m_b);
		//用全局自定义函数画图案
		DrawIco(pDC,left_top.x+10,left_top.y+ProNum*15,v->m_Graph,v->m_r,v->m_g,v->m_b);
		//格式化文本信息
		CString str;
		str.Format(_T("产品%d"),ProNum+1);
		//画文本
		pDC->TextOut(left_top.x+20,left_top.y-8+ProNum*15,str);
		ProNum++;
	}
	
	// TODO: 在此处为本机数据添加绘制代码
}
void CZP_EXAM2_3View::DrawPro(CZP_EXAM2_3Doc* pDoc,CDC * pDC)
{
	
}

// CZP_EXAM2_3View 打印

BOOL CZP_EXAM2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZP_EXAM2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZP_EXAM2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZP_EXAM2_3View 诊断

#ifdef _DEBUG
void CZP_EXAM2_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_EXAM2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_EXAM2_3Doc* CZP_EXAM2_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_EXAM2_3Doc)));
	return (CZP_EXAM2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZP_EXAM2_3View 消息处理程序


void CZP_EXAM2_3View::OnAddobj()
{
	// TODO: 在此添加命令处理程序代码
	CObjAdd v_ObjAdd;
	v_ObjAdd.DoModal();
	CZP_EXAM2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDoc->UpdateAllViews(NULL);
	CString str;
	str.Format(TEXT("一共有%d个对象！"),pDoc->m_vecPro.size());
	MessageBox(str);
	
}


void CZP_EXAM2_3View::OnMngobj()
{
	// TODO: 在此添加命令处理程序代码
	CString str;
	str.Format(TEXT("请双击颜色线条对对象进行管理！"));
	MessageBox(str);
}


void CZP_EXAM2_3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pdc = GetDC();
	//获取点击像素点
	COLORREF color = pdc->GetPixel(point);
	//获取颜色值
	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);


	CZP_EXAM2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//产品
	vector<CProduct>::iterator v;
	v = pDoc->m_vecPro.begin();
	//遍历产品
	CLine line;
	for (;v!=pDoc->m_vecPro.end(); v++)
	{
		//根据颜色判断选择哪个产品
		if (v->m_r==r&&v->m_g==g&&v->m_b==b)
		{
			CObjMng v_ObjMng;
			//显示数据到对话框
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
			//显示对话框
			v_ObjMng.DoModal();
			break;
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}
