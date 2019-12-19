
// ZP_EXAM2_3Doc.h : CZP_EXAM2_3Doc 类的接口
//


#pragma once
#include <vector>
#include "Product.h"
using namespace std;

class CZP_EXAM2_3Doc : public CDocument
{
protected: // 仅从序列化创建
	CZP_EXAM2_3Doc();
	DECLARE_DYNCREATE(CZP_EXAM2_3Doc)

// 特性
public:
	
// 操作
public:
	vector<CProduct> m_vecPro;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CZP_EXAM2_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void AddPro(int grapg,int output[],int r,int g,int b);
public:
	//表格左下角坐标
	int m_BottomLeftX;
	int m_BottomLeftY;
	//X轴间隔
	int m_SpaceX;
	//y轴间隔
	int m_SpaceY;
	int m_MouthCounts;
};
