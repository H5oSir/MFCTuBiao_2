// ObjAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_EXAM2_3.h"
#include "ObjAdd.h"
#include "afxdialogex.h"
#include "ZP_EXAM2_3Doc.h"
#include "Product.h"

// CObjAdd 对话框

IMPLEMENT_DYNAMIC(CObjAdd, CDialogEx)

CObjAdd::CObjAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CObjAdd::IDD, pParent)
	, m_M1(0)
	, m_M2(0)
	, m_M3(0)
	, m_M4(0)
	, m_M5(0)
	, m_R(0)
	, m_G(0)
	, m_B(0)
	, m_Type(0)
{

}

CObjAdd::~CObjAdd()
{
}

void CObjAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_M1, m_M1);
	DDX_Text(pDX, IDC_EDT_M2, m_M2);
	DDX_Text(pDX, IDC_EDT_M3, m_M3);
	DDX_Text(pDX, IDC_EDT_M4, m_M4);
	DDX_Text(pDX, IDC_EDT_M5, m_M5);
	DDX_Text(pDX, IDC_EDT_R, m_R);
	DDV_MinMaxInt(pDX, m_R, 0, 255);
	DDX_Text(pDX, IDC_EDT_G, m_G);
	DDV_MinMaxInt(pDX, m_G, 0, 255);
	DDX_Text(pDX, IDC_EDT_B, m_B);
	DDV_MinMaxInt(pDX, m_B, 0, 255);
	DDX_Text(pDX, IDC_EDT_TYPE, m_Type);
}


BEGIN_MESSAGE_MAP(CObjAdd, CDialogEx)
	ON_BN_CLICKED(IDOK, &CObjAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDAPLLY, &CObjAdd::OnBnClickedAplly)
	ON_BN_CLICKED(IDCANCEL, &CObjAdd::OnBnClickedCancel)
END_MESSAGE_MAP()


// CObjAdd 消息处理程序

void CObjAdd::GetData()
{
	CZP_EXAM2_3Doc *pDoc= (CZP_EXAM2_3Doc *)GetParentFrame()->GetActiveDocument();
	//获取数据
	UpdateData(TRUE);
	int out[5];
	out[0]=m_M1;
	out[1]=m_M2;
	out[2]=m_M3;
	out[3]=m_M4;
	out[4]=m_M5;
	//添加产品数据到文档
	pDoc->AddPro(m_Type,out,m_R,m_G,m_B);
	//更新所有视图
	pDoc->UpdateAllViews(NULL);
}
void CObjAdd::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetParentFrame()->GetActiveView()->GetDocument();
	GetData();
	CDialogEx::OnOK();
}


void CObjAdd::OnBnClickedAplly()
{
	// TODO: 在此添加控件通知处理程序代码
	GetData();
}


void CObjAdd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
