#pragma once
class CProduct
{
public:
	CProduct(void);
	~CProduct(void);
	void SetData(int grapg,int output[],int r,int g,int b);
public:
	//ͼ��
	int m_Graph;
	//����
	int m_Output[5];
	//��ɫ
	//COLORREF m_Color;

	int m_r;
	int m_g;
	int m_b;
	//����£������
	POINT m_position[5];
	//����
	int m_type;
};

