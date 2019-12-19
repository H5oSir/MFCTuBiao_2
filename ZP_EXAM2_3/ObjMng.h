#pragma once
#include <vector>
#include "Product.h"
using namespace std;

// CObjMng 对话框

class CObjMng : public CDialogEx
{
	DECLARE_DYNAMIC(CObjMng)

public:
	CObjMng(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CObjMng();

// 对话框数据
	enum { IDD = IDD_DLG_MNG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_M1;
	int m_M2;
	int m_M3;
	int m_M4;
	int m_M5;
	int m_R;
	int m_G;
	int m_B;
	int m_Type;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedAplly();
	vector<CProduct>::iterator v;
	void GetData();
};
