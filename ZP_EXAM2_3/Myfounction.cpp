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
//����������ת��Ϊ�����ַ�
CString number2char(int number)
{
	switch (number)
	{
	case 0:
		return _T("��");
	case 1:
		return _T("һ");

	case 2:
		return _T("��");
	case 3:
		return _T("��");
	case 4:
		return _T("��");
	case 5:
		return _T("��");
	case 6:
		return _T("��");
	case 7:
		return _T("��");
	case 8:
		return _T("��");
	case 9:
		return _T("��");
	case 10:
		return _T("ʮ");
	case 11:
		return _T("ʮһ");
	case 12:
		return _T("ʮ��");
	default:
		break;
	}
	return _T("NULL");
}
//����ת��ΪY������
int Product2point(int products,int spaceY,int spaceProductY)
{
	return products*spaceY/spaceProductY;
}

//����ICOͼ��
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