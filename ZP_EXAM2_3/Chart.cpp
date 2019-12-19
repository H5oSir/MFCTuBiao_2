#include "stdafx.h"
#include "Chart.h"


CChart::CChart(void)
{
	m_BottomLeftX=200;
	m_BottomLeftY=300;
	m_SpaceX=50;
	m_SpaceY=20;
	m_Pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	/*for (int i = 0; i < 3; i++)
	{
		m_product[i]=new CProduct(i,m_xspace,m_yspace,m_LeftBottomPoint);
	}*/
	
}


CChart::~CChart(void)
{
	//释放内存
	/*for (int i = 0; i < 3; i++)
	{
		delete m_product[i];
	}*/
}

//画Y轴数字
void CChart::DrawY(CDC *pDC)
{
	pDC->SelectObject(m_Pen);
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(L"%d",i*5);
		if (i<2)
		{
			pDC->TextOutW(m_BottomLeftX-10-8,m_BottomLeftY-i*m_SpaceY-7,str);
		}
		else
		{
			pDC->TextOutW(m_BottomLeftX-10-15,m_BottomLeftY-i*m_SpaceY-7,str);
		}
		
	}
}

//画图表表线
void CChart::DrawLine(CDC *pDC)
{
	//画横线
	pDC->SelectObject(m_Pen);
	for (int i = 0; i < 10; i++)
	{
		pDC->MoveTo(m_BottomLeftX,m_BottomLeftY-i*m_SpaceY);
		pDC->LineTo(m_BottomLeftX+300,m_BottomLeftY-i*m_SpaceY);
	}
	//画竖线
	pDC->MoveTo(m_BottomLeftX,m_BottomLeftY);
	pDC->LineTo(m_BottomLeftX,m_BottomLeftY-200);
}

//画X轴月份
void CChart::DrawMonthX(CDC *pDC)
{
	//用法（x,y,文本）
	CString m_Month;
	m_Month="一月";
	pDC->TextOutW(m_BottomLeftX+m_SpaceX/2-10,m_BottomLeftY+m_SpaceY,m_Month);
	m_Month="二月";
	pDC->TextOutW(m_BottomLeftX+m_SpaceX/2-10+m_SpaceX,m_BottomLeftY+m_SpaceY,m_Month);
	m_Month="三月";
	pDC->TextOutW(m_BottomLeftX+m_SpaceX/2-10+m_SpaceX*2,m_BottomLeftY+m_SpaceY,m_Month);
	m_Month="四月";
	pDC->TextOutW(m_BottomLeftX+m_SpaceX/2-10+m_SpaceX*3,m_BottomLeftY+m_SpaceY,m_Month);
	m_Month="五月";
	pDC->TextOutW(m_BottomLeftX+m_SpaceX/2-10+m_SpaceX*4,m_BottomLeftY+m_SpaceY,m_Month);

}

void CChart::DrawTitle(CDC *pDC)
{
	
	
	
	//画图标标题
	CString title;
	title="车床生产数据图";
	pDC->TextOutW(m_BottomLeftX+110,m_BottomLeftY-m_SpaceY*11,title);
	/*//画产品信息（三个产品）
	for (int i = 0; i < 3; i++)
	{
		//画右侧文字信息
		m_product[i]->DrawRight(pDC,m_LeftBottomPoint.x+300+30,150+i*20);
		//画产品的折线连接
		m_product[i]->DrawSelf(pDC);
	}*/
	
}


void CChart::SetBottomLeft(int x,int y)
{
	m_BottomLeftX=x;
	m_BottomLeftY=y;
}

void CChart::SetSpace(int x,int y)
{
	m_SpaceX=x;
	m_SpaceY=y;
}