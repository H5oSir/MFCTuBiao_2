#include "stdafx.h"
#include "Product.h"
//#include "Myfounction.h"

CProduct::CProduct(void)
{
	
}


CProduct::~CProduct(void)
{
}
//int Product2point(int products,int spaceY,int spaceProductY);
void CProduct::SetData(int grapg,int output[],int r,int g,int b)
{
	m_Graph=grapg;
	for (int i = 0; i < 5; i++)
	{
		m_Output[i]=output[i];
	}
	m_r=r;
	m_b=b;
	m_g=g;
	//Product2point();
}