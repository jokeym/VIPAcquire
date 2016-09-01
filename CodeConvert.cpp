#include "CodeConvert.h"

void UTF82UCS2(const string& str,wstring& wstr)
{
	wstring_convert<codecvt_utf8<wchar_t>> cvt;
	try{
		wstr=cvt.from_bytes(str);
	}catch(...){

	}
}
void WS2S(const wstring& wstr,string& str)
{
	wstring_convert<codecvt_byname<wchar_t, char, mbstate_t>> cv1(new codecvt_byname<wchar_t, char, mbstate_t>(".936")); 
	try{
		str= cv1.to_bytes(wstr);
	}catch(...){

	}
}

void S2WS(const string& str,wstring& wstr)
{
	wstring_convert<codecvt_byname<wchar_t, char, mbstate_t>> cv1(new codecvt_byname<wchar_t, char, mbstate_t>(".936")); 
	try{
		wstr= cv1.from_bytes(str);
	}catch(...){

	}
}

wstring GetLocalData()
{
	time_t t = time(0);
	tm* ptm=localtime(&t);
	wchar_t szBuf[50]={0};
	wsprintf(szBuf,L"%dÄê%dÔÂ%dÈÕ",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);
	return wstring(szBuf);
}

wstring GetExtraRegex()
{
	wchar_t szBuf[100]={0};
	wsprintf(szBuf,REGXW,GetLocalData().c_str());
	return szBuf;
}

/*bool ExtraVipURL(wstring& wstr,CVIPInfo& vipInfo)
{
	wregex wrgx(GetExtraRegex().c_str());
	wsregex_iterator edx;
	for (wsregex_iterator it(wstr.begin(),wstr.end(),wrgx);it!=edx;it++)
	{
		WS2S((*it)[1].str(),vipInfo.m_strURL);
		return true;
	}
	return false;
}*/