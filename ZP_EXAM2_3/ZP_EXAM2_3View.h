
// ZP_EXAM2_3View.h : CZP_EXAM2_3View 类的接口
//

#pragma once
#include "Chart.h"
#include "Product.h"

class CZP_EXAM2_3View : public CView
{
protected: // 仅从序列化创建
	CZP_EXAM2_3View();
	DECLARE_DYNCREATE(CZP_EXAM2_3View)

// 特性
public:
	CZP_EXAM2_3Doc* GetDocument() const;

// 操作
public:
	void DrawPro(CZP_EXAM2_3Doc* pDoc,CDC * pDC);

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CZP_EXAM2_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddobj();
	afx_msg void OnMngobj();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ZP_EXAM2_3View.cpp 中的调试版本
inline CZP_EXAM2_3Doc* CZP_EXAM2_3View::GetDocument() const
   { return reinterpret_cast<CZP_EXAM2_3Doc*>(m_pDocument); }
#endif

