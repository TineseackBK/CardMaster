#pragma once


// InfoDlg 对话框

class InfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InfoDlg)

public:
	InfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_InfoDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	CString m_name;
	CString m_type;
	CString m_effect;
	CString m_Issue_time;
	int m_number;
	afx_msg void OnBnClickedOk();
};
