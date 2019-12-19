#include "stdafx.h"
#include "Line.h"


CLine::CLine(void)
{
}


CLine::~CLine(void)
{
}
void CLine::DrawLine(CDC *pDC,int x1,int y1,int x2,int y2,int size ,int r,int g,int b)
{
	POINT v_Start={x1,y1};
	POINT v_Stop={x2,y2};
	COLORREF v_Color=RGB(r,g,b);
	CPen v_Pen;
	v_Pen.CreatePen(PS_SOLID,size,RGB(r,g,b));
	pDC->SelectObject(v_Pen);
	pDC->MoveTo(x1,y1);
	pDC->LineTo(x2,y2);
}