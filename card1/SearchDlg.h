#pragma once


// SearchDlg 对话框

class SearchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDlg)

public:
	SearchDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SearchDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SearchDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_name;
	CString q_type;
	CComboBox m_combo;
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	BOOL SearchDlg::OnInitDialog();
};
