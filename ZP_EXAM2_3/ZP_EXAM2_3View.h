
// ZP_EXAM2_3View.h : CZP_EXAM2_3View ��Ľӿ�
//

#pragma once
#include "Chart.h"
#include "Product.h"

class CZP_EXAM2_3View : public CView
{
protected: // �������л�����
	CZP_EXAM2_3View();
	DECLARE_DYNCREATE(CZP_EXAM2_3View)

// ����
public:
	CZP_EXAM2_3Doc* GetDocument() const;

// ����
public:
	void DrawPro(CZP_EXAM2_3Doc* pDoc,CDC * pDC);

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CZP_EXAM2_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddobj();
	afx_msg void OnMngobj();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ZP_EXAM2_3View.cpp �еĵ��԰汾
inline CZP_EXAM2_3Doc* CZP_EXAM2_3View::GetDocument() const
   { return reinterpret_cast<CZP_EXAM2_3Doc*>(m_pDocument); }
#endif

