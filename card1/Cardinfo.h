#pragma once
class Cardinfo
{
public:
	string m_name;
	string m_type;
	string m_effect;
	string m_lssue_time;
	int m_number;

	Cardinfo();
	Cardinfo(string name, string type, string effect, string lssue_time, int number);
};

