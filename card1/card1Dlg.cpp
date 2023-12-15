
// card1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "card1.h"
#include "card1Dlg.h"
#include "afxdialogex.h"
#include"InfoDlg.h"
#include"SearchDlg.h"
#include"LOADDlg.h"
#include"SQLInterface.h"
#include "Register.h"
#include "DBConnect.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ccard1Dlg 对话框



Ccard1Dlg::Ccard1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CARD1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccard1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}

BEGIN_MESSAGE_MAP(Ccard1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &Ccard1Dlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &Ccard1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Ccard1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Ccard1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ccard1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Ccard1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Ccard1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON12, &Ccard1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &Ccard1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &Ccard1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON10, &Ccard1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON7, &Ccard1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &Ccard1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON8, &Ccard1Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// Ccard1Dlg 消息处理程序

BOOL Ccard1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
//  执行此操作
SetIcon(m_hIcon, TRUE);			// 设置大图标
SetIcon(m_hIcon, FALSE);		// 设置小图标

// TODO: 在此添加额外的初始化代码
m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
m_list.InsertColumn(0, _T("卡名"), LVCFMT_LEFT, 110);	// 插入第2列的列名
m_list.InsertColumn(1, _T("类型"), LVCFMT_LEFT, 110);	// 插入第3列的列名
m_list.InsertColumn(2, _T("效果"), LVCFMT_LEFT, 160);	// 插入第4列的列名
m_list.InsertColumn(3, _T("发行时间"), LVCFMT_LEFT, 100);	// 插入第5列的列名
m_list.InsertColumn(4, _T("编号"), LVCFMT_LEFT, 100);	// 插入第6列的列名

return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ccard1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
	CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ccard1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ccard1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccard1Dlg::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Ccard1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 0) {
		MessageBox(TEXT("请先登录"), TEXT("提示"));
	}
	if (flag == 1) {
		if (SQL.Connect_MySQL()) {
			list_type = "normal";

			m_list.DeleteColumn(0);
			m_list.DeleteColumn(1);
			m_list.DeleteColumn(2);
			m_list.DeleteColumn(3);
			m_list.DeleteColumn(4);
			m_list.InsertColumn(0, _T("卡名"), LVCFMT_LEFT, 110);	// 插入第2列的列名
			m_list.InsertColumn(1, _T("类型"), LVCFMT_LEFT, 110);	// 插入第3列的列名
			m_list.InsertColumn(2, _T("效果"), LVCFMT_LEFT, 160);	// 插入第4列的列名
			m_list.InsertColumn(3, _T("发行时间"), LVCFMT_LEFT, 100);	// 插入第5列的列名
			m_list.InsertColumn(4, _T("编号"), LVCFMT_LEFT, 100);	// 插入第6列的列名

			Info = SQL.Get_All_Info();
			Updatelist();
		}
		else { return; }
	}
	
}


void Ccard1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	InfoDlg dlg;
	//将数据导入
	if (dlg.DoModal() == IDOK) {
		if (SQL.Add_Info(Cardinfo(dlg.m_name.GetBuffer(), dlg.m_type.GetBuffer(),
			dlg.m_effect.GetBuffer(), dlg.m_Issue_time.GetBuffer(), dlg.m_number))) {
			MessageBox(TEXT("添加成功"), TEXT("提示"));
			Info.push_back(Cardinfo(dlg.m_name.GetBuffer(), dlg.m_type.GetBuffer(),
				dlg.m_effect.GetBuffer(), dlg.m_Issue_time.GetBuffer(), dlg.m_number));
			Updatelist();
		}
	}
}

void Ccard1Dlg::Updatelist()
{
	m_list.DeleteAllItems();
	CString str;
	if (list_type == "normal") {
		for (int i = 0; i < Info.size(); i++) {
			m_list.InsertItem(i, Info[i].m_name.c_str());

			m_list.SetItemText(i, 1, Info[i].m_type.c_str());				// 设置列(类型)
			m_list.SetItemText(i, 2, Info[i].m_effect.c_str());				// 设置列(效果)
			m_list.SetItemText(i, 3, Info[i].m_lssue_time.c_str());			// 设置列(发行时间)
			str.Format(TEXT("%d"), Info[i].m_number);
			m_list.SetItemText(i, 4, str);				// 设置列(编号)
		}
	}
	if (list_type == "group") {
		for (int i = 0; i < InfoG.size(); i++) {
			str.Format(TEXT("%d"), InfoG[i].group_id);
			m_list.InsertItem(i, str);
			m_list.SetItemText(i, 1, InfoG[i].group_name.c_str());
		}
	}
}


void Ccard1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();   //获取选中行的行号
	if(nIndex == -1){
	MessageBox(TEXT("请先选择要删除的卡片"),TEXT("提示"));
	return;
}
	else {
		UINT i;
		i = MessageBox(_T("确定要删除该卡片吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			if(SQL.Del_Info(Info[nIndex])){
				MessageBox(TEXT("删除成功"), TEXT("提示"));
				Info.erase(Info.begin()+nIndex);
				Updatelist();
			}
		}
	}
}


void Ccard1Dlg::OnBnClickedButton4()
{
	int nIndex = m_list.GetSelectionMark();   //获取选中行的行号
	if (nIndex == -1) {
		MessageBox(TEXT("请先选择要修改的卡片"), TEXT("提示"));
		return;
	}
	else {
		InfoDlg dlg;
		dlg.m_name = Info[nIndex].m_name.c_str();
		dlg.m_type = Info[nIndex].m_type.c_str();
		dlg.m_effect = Info[nIndex].m_effect.c_str();
		dlg.m_Issue_time = Info[nIndex].m_lssue_time.c_str();
		dlg.m_number = Info[nIndex].m_number;
		if (dlg.DoModal() == IDOK) {
			if (SQL.Update_Info(Info[nIndex], Cardinfo(dlg.m_name.GetBuffer(), dlg.m_type.GetBuffer(),
				dlg.m_effect.GetBuffer(), dlg.m_Issue_time.GetBuffer(), dlg.m_number))) {
				MessageBox(TEXT("修改成功"), TEXT("提示"));
				Info[nIndex] = Cardinfo(dlg.m_name.GetBuffer(), dlg.m_type.GetBuffer(),
					dlg.m_effect.GetBuffer(), dlg.m_Issue_time.GetBuffer(), dlg.m_number);
				Updatelist();
			}
		}
	}
}


void Ccard1Dlg::OnBnClickedButton5()
{
	SearchDlg dlg;
	if (dlg.DoModal() == IDOK) {
		vector<Cardinfo> result = SQL.Search_info(dlg.m_name, dlg.q_type);
		if (result.empty()) {
			MessageBox(TEXT("没有该卡片信息"), TEXT("提示"));
			return;
		}

		m_list.DeleteAllItems();
		CString str;
		for (int i = 0; i < result.size(); i++) {
			m_list.InsertItem(i, result[i].m_name.c_str());
			m_list.SetItemText(i, 1, result[i].m_type.c_str());				// 设置列(类型)
			m_list.SetItemText(i, 2, result[i].m_effect.c_str());				// 设置列(效果)
			m_list.SetItemText(i, 3, result[i].m_lssue_time.c_str());			// 设置列(发行时间)
			str.Format(TEXT("%d"), result[i].m_number);
			m_list.SetItemText(i, 4, str);				// 设置列(编号)
		}
	}
}


void Ccard1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定退出程序吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES){
	OnCancel(); // 关闭窗口
	EndDialog(IDCANCEL); // 结束对话框
	}

}


void Ccard1Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	LOADDlg dlg;
	if (dlg.DoModal() == IDOK){
		flag = dlg.flag;
		username = dlg.m_ID;
		
	}
}


void Ccard1Dlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	Register dlg;
	if (dlg.DoModal() == IDOK) {
		flag = dlg.flag;
		username = dlg.r_ID;

	}
}


void Ccard1Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	Updatelist();
}

// 创建新卡组
void Ccard1Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 0) {
		MessageBox(TEXT("请先登录"), TEXT("提示"));
	}
	if (flag == 1) {
		
		GetDlgItem(IDC_EDIT5)->GetWindowText(g_name); //获得输入的卡组名称

		if (g_name.IsEmpty())
		{
			MessageBox(_T("卡组名称不能为空!"), _T("卡组编辑信息"));
			return;
		}

		MYSQL_RES* res1;
		MYSQL_RES* res2;
		MYSQL mysqlCon1;
		mysql_init(&mysqlCon1);
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

		//首先查询名字，看是否已经有这个卡组了
		snprintf(group0, SQL_MAX, "SHOW TABLES LIKE 'group_%s_%s'", SQLInterface::username, g_name);
		int ret0 = mysql_real_query(&mysqlCon1, group0, (unsigned long)strlen(group0));
		res1 = mysql_store_result(&mysqlCon1);

		if (mysql_num_rows(res1) == 0) {
			
			// 把卡组的名字放入用户对应表里
			m_ID = SQLInterface::username;

			snprintf(group_attach, SQL_MAX,
				R"(
				INSERT INTO `user_group` (`group_name`, `username`)
				VALUES ("%s", "%s")
			)",
				g_name, m_ID);

			int ret = mysql_query(&mysqlCon1, group_attach);

			// 创建新表
			snprintf(group_name, SQL_MAX,
				R"(
				CREATE TABLE `group_%s_%s` (
				  `name` VARCHAR(255) NOT NULL,
				  `type` VARCHAR(255),
				  `effect` VARCHAR(255),
				  `issue_time` VARCHAR(255),
				  `number` VARCHAR(255),
				  PRIMARY KEY (`name`));
			)",
				SQLInterface::username, g_name);
			
			int ret1 = mysql_query(&mysqlCon1, group_name);

			if (ret != 0 || ret1 != 0) {
				AfxMessageBox(_T("卡组创建失败！"));
			}
			else {
				MessageBox(_T("卡组创建成功!"));

				// 更改表名
				SQLInterface::table = "group_" + SQLInterface::username + "_" + g_name;

				mysql_close(&mysqlCon1);
			}
		}
		else {
			AfxMessageBox(_T("卡组已存在！"));
		}

		mysql_close(&mysqlCon1);
	}
}

// 查询卡组
void Ccard1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 0) {
		MessageBox(TEXT("请先登录"), TEXT("提示"));
	}
	if (flag == 1) {
		GetDlgItem(IDC_EDIT5)->GetWindowText(g_name); //获得输入的卡组名称

		if (g_name.IsEmpty())
		{
			MessageBox(_T("卡组名称不能为空!"), _T("卡组编辑信息"));
			return;
		}

		if (SQL.Connect_MySQL()) {
			// 检测表名是否存在
			MYSQL_RES* res2;
			MYSQL mysqlCon1;
			mysql_init(&mysqlCon1);
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
			snprintf(group0, SQL_MAX, "SHOW TABLES LIKE 'group_%s_%s'", SQLInterface::username, g_name);
			int ret2 = mysql_real_query(&mysqlCon1, group0, (unsigned long)strlen(group0));
			res2 = mysql_store_result(&mysqlCon1);

			if (mysql_num_rows(res2) == 0) {
				AfxMessageBox(_T("卡组不存在！"));
			}
			else {
				// 更改表名
				SQLInterface::table = "group_" + SQLInterface::username + "_" + g_name;

				list_type = "normal";

				m_list.DeleteColumn(0);
				m_list.DeleteColumn(1);
				m_list.DeleteColumn(2);
				m_list.DeleteColumn(3);
				m_list.DeleteColumn(4);
				m_list.InsertColumn(0, _T("卡名"), LVCFMT_LEFT, 110);	// 插入第2列的列名
				m_list.InsertColumn(1, _T("类型"), LVCFMT_LEFT, 110);	// 插入第3列的列名
				m_list.InsertColumn(2, _T("效果"), LVCFMT_LEFT, 160);	// 插入第4列的列名
				m_list.InsertColumn(3, _T("发行时间"), LVCFMT_LEFT, 100);	// 插入第5列的列名
				m_list.InsertColumn(4, _T("编号"), LVCFMT_LEFT, 100);	// 插入第6列的列名

				Info = SQL.Get_All_Info();
				Updatelist();
			}
			mysql_close(&mysqlCon1);
		}
		else { return; }
	}
}


void Ccard1Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT5)->GetWindowText(g_name); //获得输入的卡组名称
	if (g_name == -1) {
		MessageBox(TEXT("请先选择要删除的卡组"), TEXT("提示"));
		return;
	}
	else {
		UINT i;
		i = MessageBox(_T("确定要删除该卡组吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			if (SQL.Del_Group(g_name)) {
				MessageBox(TEXT("删除成功"), TEXT("提示"));
				// 更改表名为总表
				SQLInterface::table = "info1";
				Info = SQL.Get_All_Info();
				Updatelist();
			}
		}
	}
}


void Ccard1Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 0) {
		MessageBox(TEXT("请先登录"), TEXT("提示"));
	}
	if (flag == 1) {
		if (SQL.Connect_MySQL()) {
			// 更改表名为绑定表
			SQLInterface::table = "user_group";
			InfoG = SQL.Get_All_Group();
			list_type = "group";

			m_list.DeleteColumn(0);
			m_list.DeleteColumn(1);
			m_list.DeleteColumn(2);
			m_list.DeleteColumn(3);
			m_list.DeleteColumn(4);
			m_list.InsertColumn(0, _T("卡组编号"), LVCFMT_LEFT, 100);
			m_list.InsertColumn(1, _T("卡组名称"), LVCFMT_LEFT, 500);

			Updatelist();
		}
		else { return; }
	}
}
