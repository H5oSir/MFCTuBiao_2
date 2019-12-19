#pragma once
#include "Product.h"
class CChart
{
public:
	CChart(void);
	~CChart(void);

	//画x轴月份
	void DrawMonthX(CDC *pDC);
	//画Y轴数字
	void DrawY(CDC *pDC);

	//画线
	void DrawLine(CDC *pDC);
	//画标题
	void DrawTitle(CDC *pDC);
	void SetBottomLeft(int x,int y);
	void SetSpace(int x,int y);
private:
	//画笔
	CPen m_Pen;
	//表格左下角坐标
	int m_BottomLeftX;
	int m_BottomLeftY;
	//X轴间隔
	int m_SpaceX;
	//y轴间隔
	int m_SpaceY;
	//三个产品对象
	//CProduct *m_product[3];
};

