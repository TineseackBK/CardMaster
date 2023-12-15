#include "pch.h"
#include "Cardinfo.h"

Cardinfo::Cardinfo()
{
}

Cardinfo::Cardinfo(string name, string type, string effect, string lssue_time, int number)
{
	m_name = name;
	m_type = type;
	 m_effect = effect;
	 m_lssue_time = lssue_time;
	 m_number = number;

}
