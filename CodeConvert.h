#pragma once
#include "iostream"
#include "codecvt"
#include "time.h"
#include "string"
#include "stdio.h"
#include "windows.h"
#include "common.h"
#include "VIPInfo.h"
#include "regex"
using namespace std;

void UTF82UCS2(const string& str,wstring& wstr);
void WS2S(const wstring& wstr,string& str);
void S2WS(const string& str,wstring& wstr);
wstring GetLocalData();
wstring GetExtraRegex();
//bool ExtraVipURL(const wstring& wstr,CVIPInfo& vipInfo);