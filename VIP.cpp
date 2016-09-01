#include "VIP.h"


CVIP::CVIP(void)
	:m_strTag("N/A")
{
}

CVIP::CVIP(const string& strTag)
	:m_strTag(strTag)
{

}

CVIP::~CVIP(void)
{
}

const string& CVIP::RipURL(const string& strData)
{
	wstring wstrData;
	UTF82UCS2(strData,wstrData);
	wregex wrgx(GetExtraRegex().c_str());
	wsregex_iterator edx;
	for (wsregex_iterator it(wstrData.begin(),wstrData.end(),wrgx);it!=edx;it++)
	{
		WS2S((*it)[1].str(),m_strURL);
		break;
	}
	return m_strURL;
}

void CVIP::SetTag(const string& strURL)
{
	m_strURL=strURL;
}

const string& CVIP::GetTag() const
{
	return m_strTag;
}

ostream& operator<< (ostream& ostr,CVIP& vipInfo)
{
	if (vipInfo.m_strURL.size())
	{
		shared_ptr<CCURLLib> pCurLib(new CCURLLib (vipInfo.m_strURL,FIRFOXHEADER));
		if (pCurLib!=nullptr)
		{
			string strData=pCurLib->perfromGetResult();
			wstring wstrData;
			UTF82UCS2(strData,wstrData);
			if (wstrData.size()>0)
			{
				wregex wrgx(VIPREGXW);
				wsregex_iterator edx;
				for (wsregex_iterator it(wstrData.begin(),wstrData.end(),wrgx);it!=edx;it++)
				{
					string strx;
					WS2S((*it)[1].str(),strx);
					CVIPInfo vip;
					vip.m_strUserName=strx;
					WS2S((*it)[2].str(),strx);
					vip.m_strPassWord=strx;
					vipInfo.m_vecVipInfos.push_back(vip);
					ostr<<vip<<endl;
				}
			}
			else
			{
				ostr<<"数据未获取"<<endl;
			}
		}
	}
	else
	{
		ostr<<"数据未获取"<<endl;
	}
	return ostr;
}