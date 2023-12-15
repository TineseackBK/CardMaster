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
    // 读取 login.txt 的前五行内容
    std::ifstream file("db_login.txt");
    if (file.is_open()) {
        std::string IP_t, USERNAME_t, PASSWD_t, DBNAME_t;

        // 逐行读取
        if (std::getline(file, IP_t) &&
            std::getline(file, USERNAME_t) &&
            std::getline(file, PASSWD_t) &&
            std::getline(file, DBNAME_t) &&
            file >> PORT) {
            
            // 使用 strcpy 将字符串复制到类的静态成员中
            strncpy_s(DBConnect::IP, IP_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // 确保以 null 结尾
            strncpy_s(DBConnect::USERNAME, USERNAME_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // 确保以 null 结尾
            strncpy_s(DBConnect::PASSWD, PASSWD_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // 确保以 null 结尾
            strncpy_s(DBConnect::DBNAME, DBNAME_t.c_str(), SQL_MAX - 1);
            DBConnect::IP[SQL_MAX - 1] = '\0'; // 确保以 null 结尾
        }
        else {
            // 处理未能成功读取五行的情况
        }

        file.close(); // 关闭文件
    }
    else {
        // 处理文件打开失败的情况
    }
}
