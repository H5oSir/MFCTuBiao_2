#pragma once
class CLine
{
public:
	CLine(void);
	~CLine(void);
	void DrawLine(CDC *pDC,int x1,int y1,int x2,int y2,int size ,int r,int g,int b);
};

