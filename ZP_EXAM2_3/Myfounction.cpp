#include "stdafx.h"
#include "MyFounction.h"

/*
MyFounction::MyFounction(void)
{
}


MyFounction::~MyFounction(void)
{
}
*/
//阿拉伯数字转化为中文字符
CString number2char(int number)
{
	switch (number)
	{
	case 0:
		return _T("零");
	case 1:
		return _T("一");

	case 2:
		return _T("二");
	case 3:
		return _T("三");
	case 4:
		return _T("四");
	case 5:
		return _T("五");
	case 6:
		return _T("六");
	case 7:
		return _T("七");
	case 8:
		return _T("八");
	case 9:
		return _T("九");
	case 10:
		return _T("十");
	case 11:
		return _T("十一");
	case 12:
		return _T("十二");
	default:
		break;
	}
	return _T("NULL");
}
//产量转化为Y轴坐标
int Product2point(int products,int spaceY,int spaceProductY)
{
	return products*spaceY/spaceProductY;
}

//绘制ICO图案
void DrawIco(CDC *pDC,int x,int y,int type,int r,int g,int b)
{
	COLORREF color=RGB(r,g,b);
	CBrush brush(color);
	brush.CreateObject();
	pDC->SelectObject(brush);
	int space=5;
	if (type == 0)
	{
		pDC->Rectangle(x-space,y-space,x+space,y+space);
	}
	else if (type == 1)
	{
		pDC->Ellipse(x-space,y-space,x+space,y+space);
	}
	else if (type == 2)
	{
		CPoint pt[3]={CPoint(x,y-5),CPoint(x-5,y+5),CPoint(x+5,y+5)};
		pDC->Polygon(pt,3);
		//pDC->Ellipse(x-space,y-space,x+space,y+space);
		//pDC->AngleArc(x,);
	}
}