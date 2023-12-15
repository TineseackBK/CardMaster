#pragma once
#define SQL_MAX 256
#include "Cardinfo.h" 
#include "GroupInfo.h"
#include "user.h"
#include "LOADDlg.h"
class SQLInterface
{  
public:
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;//connect
	char sql[SQL_MAX];//SQL语句
	

	bool Connect_MySQL();//连接数据库
	vector<Cardinfo> Get_All_Info(); //获取全部信息
	vector<GroupInfo> Get_All_Group(); //获取全部卡组
	bool Add_Info(Cardinfo Info); //添加卡片信息
	bool Del_Info(Cardinfo Info);//删除学生信息
	bool Update_Info(Cardinfo old_Info, Cardinfo new_Info); //修改学生信息
	vector<Cardinfo> Search_info(CString content, CString type);//查找学生信息

	bool Del_Group(CString group_id); //删除卡组

	// 数据库的表，默认为 info1（总表）
	static CString table;

	// 当前用户名
	static CString username;

};

