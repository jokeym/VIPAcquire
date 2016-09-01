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
const array<const char*,5> tag_array={"爱奇艺","迅雷","乐视","优酷土豆","好莱坞"};

int main()
{
	CCURLLib::InitCURLLib();
	std::locale loc("");
	std::wcout.imbue(loc);
	cout<<"VIP获取工具，抓取其它网站的信息"<<endl;
	wcout<<L"当前系统时间："<<GetLocalData()<<endl;

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
		cout<<"文件创建失败"<<endl;
	}
	ofstr.close();

	for (int i=0;i<url_array.size();i++)
	{
		delete vecpCurlLib[i];
		delete vecpVIP[i];
		vecpVIP[i]=nullptr;
		vecpCurlLib[i]=nullptr;
	}

	cout<<"获取完毕，文件保存至文件目录"<<FILENAME<<endl;
	cout<<"按任意键退出"<<"....."<<endl;
	CCURLLib::DestoryCURLLib();
	getchar();
	return 0;
}