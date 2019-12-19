#pragma once
class CProduct
{
public:
	CProduct(void);
	~CProduct(void);
	void SetData(int grapg,int output[],int r,int g,int b);
public:
	//图标
	int m_Graph;
	//销量
	int m_Output[5];
	//颜色
	//COLORREF m_Color;

	int m_r;
	int m_g;
	int m_b;
	//五个月，坐标点
	POINT m_position[5];
	//种类
	int m_type;
};

