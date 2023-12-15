#include "pch.h"
#include "SQLInterface.h"
#include "DBConnect.h"

CString SQLInterface::table;
CString SQLInterface::username;

bool SQLInterface::Connect_MySQL()
{   
	DBConnect::DBConnectInit();

	mysql_init(&mysqlCon);
	//mysqlCon ���ݿ�ṹ localhost ������ root �û��� "" ����Ϊ�� mytest ���ݿ� 3306 �˿�
	if (!mysql_real_connect(&mysqlCon, DBConnect::IP, DBConnect::USERNAME, DBConnect::PASSWD, DBConnect::DBNAME, DBConnect::PORT, NULL, 0))
	{
		AfxMessageBox(_T("�������ݿ�ʧ��!"));
		return FALSE;
	}
	else
	{
		// AfxMessageBox(_T("�ɹ��������ݿ�!"));
		// �����ַ����� ʹ����֧�����ġ�
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'");//��������ݿ��ж�ȡ���ݺ���������ʾ������ 

	}
	return TRUE;
}

vector<Cardinfo> SQLInterface::Get_All_Info()
{  
	DBConnect::DBConnectInit();

	vector<Cardinfo> info;
	//c�����ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM `%s`", table);
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret) {
		AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return info;
	}
	//��ȡ����
	res = mysql_store_result(&mysqlCon);
	//�ж��Ƿ�Ϊ�գ���Ϊ�����ӡ
	while (row = mysql_fetch_row(res)) {
		Cardinfo cardinfo = Cardinfo(row[0], row[1], row[2], row[3], atoi(row[4]));
		info.push_back(cardinfo);		
	 }


	mysql_free_result(res);
	return info;

}

vector<GroupInfo> SQLInterface::Get_All_Group()
{
	vector<GroupInfo> info_g;
	//c�����ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM `%s` WHERE `username` = '%s'", table, SQLInterface::username);
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret) {
		AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return info_g;
	}
	//��ȡ����
	res = mysql_store_result(&mysqlCon);
	//�ж��Ƿ�Ϊ�գ���Ϊ�����ӡ
	while (row = mysql_fetch_row(res)) {
		GroupInfo groupinfo = GroupInfo(atoi(row[0]), row[1], row[2]);
		info_g.push_back(groupinfo);
	}


	mysql_free_result(res);
	return info_g;

}

bool SQLInterface::Add_Info(Cardinfo Info)
{   //c�����ַ���
	snprintf(sql, SQL_MAX, "INSERT INTO `%s` VALUES('%s','%s','%s','%s',%d);"
		, table, Info.m_name.c_str(), Info.m_type.c_str(), Info.m_effect.c_str(),Info.m_lssue_time.c_str(),Info.m_number);
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϽ��
	if (ret) {	AfxMessageBox(_T("���ʧ�ܣ�"));	return false;}
	return true;
}

bool SQLInterface::Del_Info(Cardinfo Info)
{
	snprintf(sql, SQL_MAX, "DELETE FROM `%s` WHERE name = '%s';", table, Info.m_name.c_str());
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϽ��
	if (ret) { AfxMessageBox(_T("ɾ��ʧ�ܣ�"));	return false; }
	return true;
}

bool SQLInterface::Del_Group(CString group_name)
{
	snprintf(sql, SQL_MAX, "DROP TABLE `group_%s_%s`;", SQLInterface::username, group_name);
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϽ��
	if (ret) { AfxMessageBox(_T("ɾ��ʧ�ܣ�"));	return false; }

	snprintf(sql, SQL_MAX, "DELETE FROM `user_group` WHERE group_name = '%s';", group_name);
	int ret1 = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϽ��
	if (ret1) { AfxMessageBox(_T("ɾ��ʧ�ܣ�"));	return false; }

	return true;
}

bool SQLInterface::Update_Info(Cardinfo old_Info, Cardinfo new_Info)
{
	snprintf(sql, SQL_MAX, "UPDATE `%s` SET name = '%s',type = '%s',effect = '%s',Issue_time='%s',number=%d WHERE name = '%s';"
		, table, new_Info.m_name.c_str(), new_Info.m_type.c_str(),new_Info.m_effect.c_str(), new_Info.m_lssue_time.c_str(), new_Info.m_number,old_Info.m_name.c_str());
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϽ��
	if (ret) { AfxMessageBox(_T("�޸�ʧ�ܣ�"));	return false; }
	return true;
}

vector<Cardinfo> SQLInterface::Search_info(CString content, CString type)
{  
	vector<Cardinfo> result;
	
	// ģ����ѯ
	if (type == "����") {
		snprintf(sql, SQL_MAX, "SELECT * FROM `%s` where name LIKE '%%%s%%';", table, content);
	}
	else if (type == "����") {
		snprintf(sql, SQL_MAX, "SELECT * FROM `%s` where type LIKE '%%%s%%';", table, content);
	}
	else if (type == "Ч��") {
		snprintf(sql, SQL_MAX, "SELECT * FROM `%s` where effect LIKE '%%%s%%';", table, content);
	}
	else if (type == "����ʱ��") {
		snprintf(sql, SQL_MAX, "SELECT * FROM `%s` where issue_time LIKE '%%%s%%';", table, content);
	}
	else if (type == "���") {
		snprintf(sql, SQL_MAX, "SELECT * FROM `%s` where number LIKE '%%%s%%';", table, content);
	}
	else {
		snprintf(sql, SQL_MAX, "SELECT * FROM `%s` where name LIKE '%%%s%%';", table, content);
	}

	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϽ��
	if (ret) { AfxMessageBox(_T("��ѯʧ�ܣ�"));	return result; }
	res = mysql_store_result(&mysqlCon);
	//�ж��Ƿ�Ϊ�գ���Ϊ�����ӡ
	while (row = mysql_fetch_row(res)) {
		Cardinfo cardinfo = Cardinfo(row[0], row[1], row[2], row[3], atoi(row[4]));
		result.push_back(cardinfo);
	}


	mysql_free_result(res);
	return result;
}