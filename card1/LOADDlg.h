#pragma once
#define SQL_MAX 256

// LOADDlg 对话框

class LOADDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LOADDlg)

public:
	LOADDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LOADDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOADDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_ID;
	CString m_password;
	afx_msg void OnBnClickedOk();
	char user[SQL_MAX];//存放用户SQL
	int flag = 0;
};
