// InfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "card1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"


// InfoDlg 对话框

IMPLEMENT_DYNAMIC(InfoDlg, CDialogEx)

InfoDlg::InfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InfoDlg, pParent)
	, m_name(_T(""))
	, m_type(_T(""))
	, m_effect(_T(""))
	, m_Issue_time(_T(""))
	, m_number(0)
{

}

InfoDlg::~InfoDlg()
{
}

void InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_type);
	DDX_Text(pDX, IDC_EDIT4, m_effect);
	DDX_Text(pDX, IDC_EDIT3, m_Issue_time);
	DDX_Text(pDX, IDC_EDIT5, m_number);
}


BEGIN_MESSAGE_MAP(InfoDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &InfoDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDOK, &InfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InfoDlg 消息处理程序


void InfoDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void InfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (m_name == TEXT(""))
	{
		MessageBox(TEXT("卡名不得为空"), TEXT("提示"));
		return;

	}

	if (m_number < 0) {
		MessageBox(TEXT("编号不得为负数"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}
