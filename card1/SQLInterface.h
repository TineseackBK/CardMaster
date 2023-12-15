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
	char sql[SQL_MAX];//SQL���
	

	bool Connect_MySQL();//�������ݿ�
	vector<Cardinfo> Get_All_Info(); //��ȡȫ����Ϣ
	vector<GroupInfo> Get_All_Group(); //��ȡȫ������
	bool Add_Info(Cardinfo Info); //��ӿ�Ƭ��Ϣ
	bool Del_Info(Cardinfo Info);//ɾ��ѧ����Ϣ
	bool Update_Info(Cardinfo old_Info, Cardinfo new_Info); //�޸�ѧ����Ϣ
	vector<Cardinfo> Search_info(CString content, CString type);//����ѧ����Ϣ

	bool Del_Group(CString group_id); //ɾ������

	// ���ݿ�ı�Ĭ��Ϊ info1���ܱ�
	static CString table;

	// ��ǰ�û���
	static CString username;

};

