#pragma once

#define FILENAME "VIP信息.txt"
#define FIRFOXHEADER "User-Agent: 	Mozilla / 4.0 (compatible; MSIE 7.0; Windows NT 5.1; Trident / 4.0; SE 2.X MetaSr 1.0; SE 2.X MetaSr 1.0; .NET CLR 2.0.50727; SE 2.X MetaSr 1.0)"
//<a href="http://www.vipdaquan.com/iqiyi/11002.html" rel="bookmark" title="详细阅读 2016年6月19日 爱奇艺vip分享 爱奇艺免费账号 每天更新">
#define REGXW L"<a href=\"([a-zA-z]+://[^\\s]*)\" rel=\"bookmark\" title=\"[\\u4e00-\\u9fa5]+ %s "
#define VIPREGXW L"[\\u4e00-\\u9fa5|\\u0030-\\u007a]+：([\\u0030-\\u007a|@|\\.]+)[\\u4e00-\\u9fa5]+：(\\w+)</p>"
//  [\\u4e00-\\u9fa5
#define URL_AIQIYI "http://www.vipdaquan.com/iqiyi"
#define URL_XUNLEI "http://www.vipdaquan.com/xunlei"
#define URL_LESHI "http://www.vipdaquan.com/letv"
#define URL_YOUKU "http://www.vipdaquan.com/youku"
#define URL_HAOLAIWU "http://www.vipdaquan.com/haolaiwu"

enum ENUM_URLS {AIQIYI,XUNLEI,LESHI,YOUKU,HAOLAIWU};