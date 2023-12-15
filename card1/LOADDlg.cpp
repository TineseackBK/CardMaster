// LOADDlg.cpp: 实现文件
//

#include "pch.h"
#include "card1.h"
#include "LOADDlg.h"
#include "afxdialogex.h"
#include"card1Dlg.h"
#include"SQLInterface.h"
#include "user.h"
#include "DBConnect.h"

// LOADDlg 对话框

IMPLEMENT_DYNAMIC(LOADDlg, CDialogEx)

LOADDlg::LOADDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOADDlg, pParent)
	, m_ID(_T(""))
	, m_password(_T(""))
{

}

LOADDlg::~LOADDlg()
{
}

void LOADDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}


BEGIN_MESSAGE_MAP(LOADDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &LOADDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// LOADDlg 消息处理程序


void LOADDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_ID); //获得输入的用户名
	GetDlgItem(IDC_EDIT2)->GetWindowText(m_password); //获得输入的密码

	if(m_ID.IsEmpty() || m_password.IsEmpty())
	{
		MessageBox(_T("用户名或密码不能为空!"), _T("用户登录信息"));
		return;
	}

	DBConnect::DBConnectInit();

	MYSQL_RES* res1;
	MYSQL_ROW row1;
	MYSQL mysqlCon1;
	mysql_init(&mysqlCon1);
	//mysqlCon 数据库结构 localhost 主机名 root 用户名 "" 密码为空 mytest 数据库 3306 端口
	if (!mysql_real_connect(&mysqlCon1, DBConnect::IP, DBConnect::USERNAME, DBConnect::PASSWD, DBConnect::DBNAME, DBConnect::PORT, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		// AfxMessageBox(_T("成功连接数据库!"));
		// 设置字符集， 使程序支持中文。
		mysql_query(&mysqlCon1, "SET NAMES 'GB2312'");//解决从数据库中读取数据后汉字乱码显示的问题 

	}

	//c语言字符串
	snprintf(user, SQL_MAX, "SELECT * FROM userinfo1 where ID ='%s'",m_ID);
	//查询数据
	int ret = mysql_real_query(&mysqlCon1, user, (unsigned long)strlen(user));
	if (ret) { AfxMessageBox(_T("登录失败！"));	 }
	res1 = mysql_store_result(&mysqlCon1);
	if (mysql_num_rows(res1) == 0) {
		AfxMessageBox(_T("用户不存在"));
	}
	else {
		row1= mysql_fetch_row(res1);
		if (row1[1] == m_password) {
			mysql_free_result(res1);
			MessageBox(_T("登录成功!"));

			// 设置当前用户名
			SQLInterface::username = m_ID;

			// 已登录
			flag = 1;

			mysql_close(&mysqlCon1);
			OnCancel();

			// 初始化类静态变量 表名
			SQLInterface::table = "info1";
		}
		else { MessageBox(_T("密码错误!")); }
	}
	mysql_close(&mysqlCon1);
	CDialogEx::OnOK();
}

