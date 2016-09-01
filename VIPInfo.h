#pragma once
#include "string"
#include "iostream"
#include <iomanip>
using namespace std;

class CVIPInfo
{
public:
	CVIPInfo(void);
	virtual ~CVIPInfo(void);
public:
	friend ostream& operator<< (ostream& ostr,const CVIPInfo& vi);
	string m_strUserName;
	string m_strPassWord;
	string m_strUpdateData;
};

