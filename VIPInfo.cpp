#include "VIPInfo.h"


CVIPInfo::CVIPInfo(void)
{
}


CVIPInfo::~CVIPInfo(void)
{
}

ostream& operator<< (ostream& ostr,const CVIPInfo& vi)
{
	ostr<<left<<setw(30)<<vi.m_strUserName<<setw(30)<<vi.m_strPassWord;
	return ostr;
}