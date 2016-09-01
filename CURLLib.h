#pragma once
#include "string"
#include "curl/curl.h"
#pragma comment(lib,"libcurl.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Wldap32.lib")
using namespace std;

class CCURLLib
{
public:
	CCURLLib(void);
	CCURLLib(const string& str);
	CCURLLib(const string& strURL,const string& strHeader);
	virtual ~CCURLLib(void);
	static void InitCURLLib();
	static void DestoryCURLLib();
	static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
public:
	bool setCustomHeader(const string& str);
	bool setURL(const string& str);
	string perfromGetResult();
protected:
	CURL* m_curl;
	curl_slist* m_chunk;
	string m_strData;
};

