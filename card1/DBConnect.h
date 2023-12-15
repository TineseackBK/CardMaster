#pragma once
#define SQL_MAX 256
class DBConnect
{
public:
	static char IP[SQL_MAX];
	static char USERNAME[SQL_MAX];
	static char PASSWD[SQL_MAX];
	static char DBNAME[SQL_MAX];
	static int PORT;

	static void DBConnectInit();
};

