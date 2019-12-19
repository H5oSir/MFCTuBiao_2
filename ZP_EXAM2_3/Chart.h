#pragma once
#include "Product.h"
class CChart
{
public:
	CChart(void);
	~CChart(void);

	//��x���·�
	void DrawMonthX(CDC *pDC);
	//��Y������
	void DrawY(CDC *pDC);

	//����
	void DrawLine(CDC *pDC);
	//������
	void DrawTitle(CDC *pDC);
	void SetBottomLeft(int x,int y);
	void SetSpace(int x,int y);
private:
	//����
	CPen m_Pen;
	//������½�����
	int m_BottomLeftX;
	int m_BottomLeftY;
	//X����
	int m_SpaceX;
	//y����
	int m_SpaceY;
	//������Ʒ����
	//CProduct *m_product[3];
};

