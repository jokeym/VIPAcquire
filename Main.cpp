#include "iostream"
#include "CodeConvert.h"
#include "CURLLib.h"
#include "vector"
#include "regex"
#include "array"
#include "common.h"
#include "VIP.h"
#include <iomanip>
#include "fstream"
using namespace std;

const array<const char*,5> url_array={URL_AIQIYI,URL_XUNLEI,URL_LESHI,
										URL_YOUKU,URL_HAOLAIWU};
const array<const char*,5> tag_array={"������","Ѹ��","����","�ſ�����","������"};

int main()
{
	CCURLLib::InitCURLLib();
	std::locale loc("");
	std::wcout.imbue(loc);
	cout<<"VIP��ȡ���ߣ�ץȡ������վ����Ϣ"<<endl;
	wcout<<L"��ǰϵͳʱ�䣺"<<GetLocalData()<<endl;

	vector<CCURLLib*> vecpCurlLib;
	vector<CVIP*> vecpVIP;
	for (int i=0;i<url_array.size();i++)
	{
		vecpCurlLib.push_back(new CCURLLib(url_array[i],FIRFOXHEADER));
		string strData=vecpCurlLib[i]->perfromGetResult();
		vecpVIP.push_back(new CVIP(tag_array[i]));
		cout<<vecpVIP[i]->GetTag()<<endl;
		vecpVIP[i]->RipURL(strData);
		cout<<*(vecpVIP[i])<<endl;
	}

	ofstream ofstr(FILENAME);
	if (ofstr)
	{
		for (int i=0;i<url_array.size();i++)
		{
			ofstr<<vecpVIP[i]->GetTag()<<endl;
			ofstr<<*(vecpVIP[i])<<endl;
		}
	}
	else
	{
		cout<<"�ļ�����ʧ��"<<endl;
	}
	ofstr.close();

	for (int i=0;i<url_array.size();i++)
	{
		delete vecpCurlLib[i];
		delete vecpVIP[i];
		vecpVIP[i]=nullptr;
		vecpCurlLib[i]=nullptr;
	}

	cout<<"��ȡ��ϣ��ļ��������ļ�Ŀ¼"<<FILENAME<<endl;
	cout<<"��������˳�"<<"....."<<endl;
	CCURLLib::DestoryCURLLib();
	getchar();
	return 0;
}