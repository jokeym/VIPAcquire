#pragma once
#include "VIPInfo.h"
#include "vector"
#include "string"
#include "CodeConvert.h"
#include "regex"
#include "CURLLib.h"
#include "memory"
#include "common.h"
using namespace std;

class CVIP
{
public:
	CVIP(const string& strTag);
	CVIP(void);
	virtual ~CVIP(void);
public:
	const string& RipURL(const string& strData);
	void SetTag(const string& strURL);
	const string& GetTag() const;
	friend ostream& operator<< (ostream& ostr,CVIP& vipInfo);
protected:
	vector<CVIPInfo> m_vecVipInfos;
	string m_strTag;
	string m_strURL;
};

