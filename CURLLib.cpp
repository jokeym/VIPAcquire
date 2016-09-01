#include "CURLLib.h"


CCURLLib::CCURLLib(void)
	:m_curl(NULL)
	,m_chunk(NULL)
{
	m_curl = curl_easy_init();
	if (m_curl)
	{
		curl_easy_setopt(m_curl,CURLOPT_WRITEFUNCTION,write_callback);
		curl_easy_setopt(m_curl,CURLOPT_WRITEDATA,reinterpret_cast<void*>(this)); 
	}
}

CCURLLib::CCURLLib(const string& str)
	:m_curl(NULL)
	,m_chunk(NULL)
{
	m_curl = curl_easy_init();
	if (m_curl)
	{
		curl_easy_setopt(m_curl,CURLOPT_WRITEFUNCTION,write_callback);
		curl_easy_setopt(m_curl,CURLOPT_WRITEDATA,reinterpret_cast<void*>(this)); 
		setURL(str);
	}
}

CCURLLib::CCURLLib(const string& strURL,const string& strHeader)
	:m_curl(NULL)
	,m_chunk(NULL)
{
	m_curl = curl_easy_init();
	if (m_curl)
	{
		curl_easy_setopt(m_curl,CURLOPT_WRITEFUNCTION,write_callback);
		curl_easy_setopt(m_curl,CURLOPT_WRITEDATA,reinterpret_cast<void*>(this)); 
		setURL(strURL);
		setCustomHeader(strHeader);
	}
}

CCURLLib::~CCURLLib(void)
{
	if (m_chunk)
	{
		curl_slist_free_all(m_chunk);
	}
	if (m_curl)
	{
		curl_easy_cleanup(m_curl);
	}
}

void CCURLLib::InitCURLLib()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

void CCURLLib::DestoryCURLLib()
{
	curl_global_cleanup();
}

bool CCURLLib::setCustomHeader(const string& str)
{
	m_chunk=curl_slist_append(m_chunk, str.c_str());
	return curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, m_chunk)==CURLE_OK;
}

bool CCURLLib::setURL(const string& str)
{
	return curl_easy_setopt(m_curl, CURLOPT_URL, str.c_str())==CURLE_OK;
}

size_t CCURLLib::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	CCURLLib* pThis=reinterpret_cast<CCURLLib*>(userdata);
	if (pThis!=nullptr)
	{
		pThis->m_strData.append(ptr,size*nmemb);
	}
	return size*nmemb;
}

string CCURLLib::perfromGetResult()
{
	m_strData.clear();
	if (m_curl)
	{
		curl_easy_perform(m_curl);
	}
	return m_strData;
}