#pragma once


// CObjAdd �Ի���

class CObjAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CObjAdd)

public:
	CObjAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CObjAdd();

// �Ի�������
	enum { IDD = IDD_DLG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	afx_msg void OnBnClickedAplly();
	void GetData();
	afx_msg void OnBnClickedCancel();
};
