
// ZP_EXAM2_3Doc.h : CZP_EXAM2_3Doc ��Ľӿ�
//


#pragma once
#include <vector>
#include "Product.h"
using namespace std;

class CZP_EXAM2_3Doc : public CDocument
{
protected: // �������л�����
	CZP_EXAM2_3Doc();
	DECLARE_DYNCREATE(CZP_EXAM2_3Doc)

// ����
public:
	
// ����
public:
	vector<CProduct> m_vecPro;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CZP_EXAM2_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void AddPro(int grapg,int output[],int r,int g,int b);
public:
	//������½�����
	int m_BottomLeftX;
	int m_BottomLeftY;
	//X����
	int m_SpaceX;
	//y����
	int m_SpaceY;
	int m_MouthCounts;
};
