#include "pch.h"
#include "DBConnect.h"
#include <fstream>
#include <string>

char DBConnect::IP[SQL_MAX];
char DBConnect::USERNAME[SQL_MAX];
char DBConnect::PASSWD[SQL_MAX];
char DBConnect::DBNAME[SQL_MAX];
int DBConnect::PORT;

void DBConnect::DBConnectInit()
{
    // ��ȡ login.txt ��ǰ��������
    std::ifstream file("db_login.txt");
    if (file.is_open()) {
        std::string IP_t, USERNAME_t, PASSWD_t, DBNAME_t;

        // ���ж�ȡ
        if (std::getline(file, IP_t) &&
            std::getline(file, USERNAME_t) &&
            std::getline(file, PASSWD_t) &&
            std::getline(file, DBNAME_t) &&
            file >> PORT) {
            
            // ʹ�� strcpy ���ַ������Ƶ���ľ�̬��Ա��
            strncpy_s(DBConnect::IP, IP_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // ȷ���� null ��β
            strncpy_s(DBConnect::USERNAME, USERNAME_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // ȷ���� null ��β
            strncpy_s(DBConnect::PASSWD, PASSWD_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // ȷ���� null ��β
            strncpy_s(DBConnect::DBNAME, DBNAME_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // ȷ���� null ��β
        }
        else {
            // ����δ�ܳɹ���ȡ���е����
        }

        file.close(); // �ر��ļ�
    }
    else {
        // �����ļ���ʧ�ܵ����
    }
}
