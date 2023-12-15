
// card1Dlg.h: 头文件
//
#include"SQLInterface.h"
#include"LOADDlg.h"
#include "user.h"
#pragma once


// Ccard1Dlg 对话框
class Ccard1Dlg : public CDialogEx
{
// 构造
public:
	Ccard1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CARD1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	SQLInterface SQL;
	afx_msg void OnBnClickedButton2();
	vector<Cardinfo> Info;
	vector<GroupInfo> InfoG;
	CString list_type = "normal";
	string username;
	int flag = 0;
	CListCtrl m_list;
	CString g_name;
	CString m_ID;
	char group_name[SQL_MAX];
	char group0[SQL_MAX];
	char group_id_query[SQL_MAX];
	char group_attach[SQL_MAX];
	afx_msg void OnBnClickedButton1();
	void Updatelist();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton8();
};
