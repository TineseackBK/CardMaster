#pragma once
class GroupInfo
{
public:
	int group_id;
	string group_name;
	string username;

	GroupInfo();
	GroupInfo(int group_id, string group_name, string username);
};

