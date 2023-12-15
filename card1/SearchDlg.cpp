// SearchDlg.cpp: 实现文件
//

#include "pch.h"
#include "card1.h"
#include "SearchDlg.h"
#include "afxdialogex.h"


// SearchDlg 对话框

IMPLEMENT_DYNAMIC(SearchDlg, CDialogEx)

SearchDlg::SearchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SearchDlg, pParent)
	, m_name(_T(""))
{

}

SearchDlg::~SearchDlg()
{
}

BOOL SearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_combo.SubclassDlgItem(IDC_COMBO1, this);

	return TRUE;
}

void SearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name);
}


BEGIN_MESSAGE_MAP(SearchDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &SearchDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &SearchDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &SearchDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// SearchDlg 消息处理程序


void SearchDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void SearchDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (m_name == TEXT("")) {
		MessageBox(TEXT("输入不能为空"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}


void SearchDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int selectedIndex = m_combo.GetCurSel();
	if (selectedIndex != CB_ERR) {
		m_combo.GetLBText(selectedIndex, q_type);
	}
}
