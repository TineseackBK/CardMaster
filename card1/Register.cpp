// Register.cpp: 实现文件
//

#include "pch.h"
#include "card1.h"
#include "afxdialogex.h"
#include "Register.h"
#include "user.h"
#include "card1Dlg.h"
#include "SQLInterface.h"
#include "DBConnect.h"


// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REGISTER, pParent)
	, r_ID(_T(""))
	, r_password(_T(""))
{

}

Register::~Register()
{
}

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
	ON_BN_CLICKED(IDOK2, &Register::OnBnClickedOk2)
END_MESSAGE_MAP()


// Register 消息处理程序


void Register::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->GetWindowText(r_ID); //获得输入的用户名
	GetDlgItem(IDC_EDIT2)->GetWindowText(r_password); //获得输入的密码
	GetDlgItem(IDC_EDIT3)->GetWindowText(r_password_c); //获得输入的确认密码

	if (r_ID.IsEmpty() || r_password.IsEmpty())
	{
		MessageBox(_T("用户名或密码不能为空!"), _T("用户注册信息"));
		return;
	}

	if (r_password != r_password_c)
	{
		MessageBox(_T("密码和确认密码不匹配，请重新输入！"), _T("用户注册信息"));
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

	//首先查询ID，看是否已经有这个用户了
	snprintf(user0, SQL_MAX, "SELECT * FROM userinfo1 where ID ='%s'", r_ID);
	int ret0 = mysql_real_query(&mysqlCon1, user0, (unsigned long)strlen(user0));
	res1 = mysql_store_result(&mysqlCon1);

	if (mysql_num_rows(res1) == 0) {
		//插入用户名和密码
		snprintf(user, SQL_MAX, "INSERT INTO userinfo1 (ID, password) VALUES ('%s', '%s')", r_ID, r_password);

		int ret = mysql_query(&mysqlCon1, user);

		if (ret != 0) {
			AfxMessageBox(_T("注册失败！"));
		}
		else {
			MessageBox(_T("注册并登录成功!"));

			// 设置当前用户名
			SQLInterface::username = r_ID;

			int ret1 = mysql_query(&mysqlCon1, user1);

			// 已登录
			flag = 1;

			mysql_close(&mysqlCon1);
			OnCancel();
		}
	}
	else {
		AfxMessageBox(_T("用户已存在！"));
	}

	mysql_close(&mysqlCon1);
	CDialogEx::OnOK();
}
