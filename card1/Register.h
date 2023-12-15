#pragma once
#define SQL_MAX 256
#include "afxdialogex.h"


// Register 对话框

class Register : public CDialogEx
{
	DECLARE_DYNAMIC(Register)

public:
	Register(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Register();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString r_ID;
	CString r_password;
	CString r_password_c;
	afx_msg void OnBnClickedOk2();
	char user[SQL_MAX];//存放用户SQL
	char user1[SQL_MAX];
	char user0[SQL_MAX];
	int flag = 0;
};
