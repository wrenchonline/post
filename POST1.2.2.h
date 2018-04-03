#include <string>
#include <vector>
#include <algorithm>
#include <afx.h>
#include<windows.h> 
#include"string.h"
#include<iostream>
#include "stdafx.h"
#include <stdarg.h>
#include<Wininet.h>
#include"targetver.h"
#include "boost/regex.hpp"
using namespace std;
#pragma warning(disable:4996)
/*
const char* XUGQ;
string ret;
string 页面地址;

char* 页面地址S;
string   replace_all(string  str, string  old_value,  string   new_value)
{
	while (true) {
		string::size_type   pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}

vector<string> split(string str, string s)
{
	boost::regex reg(s.c_str());
	vector<string> vec;
	boost::sregex_token_iterator it(str.begin(), str.end(), reg, -1);
	boost::sregex_token_iterator end;
	while (it != end)
	{
		vec.push_back(*it++);
	}
	return vec;
}
vector<int> 取字节集左边(vector<int> 欲取字节集, size_t s)
{
	vector<int> 保存内容;
	memcpy(&保存内容, &欲取字节集, s);
	return 保存内容;
}
void StrSplit(char *str, char *delims, vector <string> &v)
{
	string s;
	char *result = NULL;
	result = strtok(str, delims);
	while (result != NULL)
	{
		s.assign(result);
		v.push_back(s);
		result = strtok(str, delims);
	}
}
INT 还原地址(string 文本地址)
{
	int 转换地址 = 0;
	char 临时数组[256] = { 0 };
	strcpy_s(临时数组, 文本地址.c_str());
	sscanf_s(临时数组, "%x", &转换地址);
	return 转换地址;
}
string 取文本右边(CString 欲取其部分的文本, int 欲取出字符数目)
{
	CString str = 欲取其部分的文本.Right(欲取出字符数目);
	CStringA stra(str.GetBuffer(0));
	str.ReleaseBuffer();
	string strb = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return strb;
}
string CSringToString(CString 待转换文本)
{
	CStringA stra(待转换文本.GetBuffer(0));
	待转换文本.ReleaseBuffer();
	std::string stdStr = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return stdStr;
}
int 寻找文本(string 寻找文本, string 寻找内容, ...)
{
	va_list arguments;
	int 起始位置 = 1;
	va_start(arguments, 寻找内容);
	起始位置 = va_arg(arguments, int);

	string st(寻找文本);
	size_t  position;

	position = st.find(寻找内容, 起始位置);
	while (position != string::npos)
	{
		position = st.find(寻找内容, position);

	}
	va_end(arguments);
	return position;
}
string strim(string &str)

{

	str.erase(str.find_last_of(' ') + 1, string::npos);    //去掉字符串末尾空格  
	str.erase(0, str.find_first_of(' '));    //去掉字符串首空格  
	return str;
}
string 取文本中间(CString 欲取其部分的文本, int 起始取出位置, int 欲取出字符数目)
{
	CString str = 欲取其部分的文本.Mid(起始取出位置, 欲取出字符数目);
	CStringA stra(str.GetBuffer(0));
	str.ReleaseBuffer();
	string strb = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return strb;
}
string 文本_取出中间文本(string 欲取的文本, string 前面的文本, string 后面的文本)
{
	CString strMfc;
	string 前面文本, 后面文本,空文本;
	int 前面文本位置, 后面文本位置;

	前面文本位置 = 寻找文本(欲取的文本, 前面的文本, 1);
	后面文本位置 = 寻找文本(欲取的文本, 后面的文本, 1);
	strMfc = 欲取的文本.c_str();
	if (前面文本位置 != -1)
	{
		前面文本位置 = 前面文本位置 + sizeof(前面文本);
	}
	后面文本位置 = 寻找文本(欲取的文本, 后面文本, 前面文本位置);
	if (前面文本位置 == string::npos || 后面文本位置 == string::npos)
	{
		return 空文本;
	}
	return(取文本中间(strMfc, 前面文本位置, 后面文本位置 - 前面文本位置));
}
string 内部_协议头取值(string 协议头)
{
	int 位置;
	CString strMfc;
	strMfc = 协议头.c_str();
	string 结果;
	位置 = 寻找文本(协议头, ":");
	if (位置 != string::npos)
	{
		结果 = 取文本右边(strMfc, sizeof(协议头) - 位置);
	}
	return strim(结果);
}
string 取文本左边(CString 欲取其部分的文本, int 欲取出字符数目)
{
	CString str = 欲取其部分的文本.Left(欲取出字符数目);
	CStringA stra(str.GetBuffer(0));
	str.ReleaseBuffer();
	string strb = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return strb;
}
string _Int2Hex(int Value, int n)
{
	CString str;
	str.Format(_T("0000000%x"), Value);
	string tmp1 = CSringToString(str);
	tmp1 = tmp1.substr(tmp1.length() - n, n);
	string tmp2;
	for (unsigned int i = 0; i < tmp1.length() / 2; i++)
	{
		tmp2 = tmp2 + tmp1.substr(tmp1.length() - 2 - 2 * i, 2);
	}
	return tmp2;
}
vector<int> 到字节集(int a)
{
	string s = _Int2Hex(a, 8);
	int 长度 = s.length();
	if (长度 % 2 != 0)
	{
		长度 = 长度 + 1;
	}
	vector<int> 结果(长度 / 2, 0);
	for (int i = 0; i < 长度 / 2; i++)
	{
		结果[i] = 还原地址(s.substr(i * 2, 2));
	}
	return 结果;
}
vector<int> VectorToAdd(vector<int> a, vector<int> b)
{
	vector<int> 合并内容;
	for (int i = 0; i<sizeof(a); i++)
	{
		合并内容.push_back(a[i]);
	}
	for (int i = 0; i<sizeof(b); i++)
	{
		合并内容.push_back(b[i]);
	}
	return 合并内容;
}
string VecToString(vector<string>CVec){
	int size = CVec.size();
	string str;
	for (int i = 0; i<size; i++)
	{
		str += CVec[i];
	}
	return str;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char*  网页_取页面地址(string 网址, const char* SAFFA) {
	int 符号位置;
	string 域名aaa=SAFFA;
	符号位置 = 域名aaa.size() + 7;
	if (符号位置>0)
	{
		页面地址 = 取文本右边((CString)网址.c_str(), 网址.size() - 符号位置);
	}
	else
	{
		页面地址 = "/";
	}
	页面地址S = (char*)页面地址.data();
	return(页面地址S);
}
int 内部_数组成员是否存在_文本(string SDR, string 要判断的值)
{
	int s;
	s=SDR.find(要判断的值);
	return s;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CString  文本_去重复文本(CString 原文本, string 分隔符)
{
	vector<string> CStr;
	vector<string> CStrone;
	string str;
	CStr=split(CSringToString(原文本),分隔符);
	size_t S = CStr.size();
	for (size_t i = 0; i < S; i++)
	{
		if (内部_数组成员是否存在_文本(VecToString(CStrone), 分隔符) == string::npos)
		{
			CStrone.push_back(CStr[i]);
			str += CStr[i];
			str += 分隔符;
		}
	}
	str = 取文本右边((CString)str.c_str(), str.size() - sizeof(分隔符)).c_str();

	return (CString)str.c_str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string 内部_Cookie取名(string Cookie)
{
	int 位置;
	string 结果;
	位置 = 寻找文本(Cookie, "=");
	if (位置 != string::npos)
	{
		结果 = 取文本左边((CString)Cookie.c_str(), 位置 - 1);
	}
	else
	{
		结果 = Cookie;
	}
	return strim(结果);
}
BOOL 内部_数组成员是否存在1(string 数组[], string 要判断值)
{
	for (int 局_计次 = 0; sizeof(数组); 局_计次++)
	{
		if (内部_Cookie取名(数组[局_计次]) == 要判断值)
		{
			return TRUE;
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string 网页_Cookie合并更新(string 旧Cookie, string 新Cookie)
{
	vector<string>局_旧Cookie组, 局_新Cookie组;
	size_t 局_计次;
	旧Cookie=replace_all(旧Cookie, " ", "");
	新Cookie=replace_all(新Cookie, " ", "");
	局_旧Cookie组 = split(旧Cookie, ";");
	局_新Cookie组 = split(新Cookie, ";");

	for (局_计次=0; 局_计次 < sizeof(旧Cookie); 局_计次++)
	{
		if (内部_数组成员是否存在1(&VecToString(局_新Cookie组), 内部_Cookie取名(局_旧Cookie组[局_计次]))==0)
		{
			局_新Cookie组.push_back(局_旧Cookie组[局_计次]);
		}
	}
	旧Cookie.clear();
	size_t S = 局_新Cookie组.size();
	for (局_计次=0; 局_计次<S; 局_计次++)
	{
		if (取文本右边((CString)局_新Cookie组[局_计次].c_str(), 8) != "=deleted")
		{
			旧Cookie += 局_新Cookie组[局_计次] ;
			旧Cookie += "; ";
		}
	}
	旧Cookie = 取文本左边((CString)旧Cookie.c_str(), sizeof(旧Cookie) - 2).c_str();
	旧Cookie = CSringToString(文本_去重复文本((CString)旧Cookie.c_str(), "; "));
	return 旧Cookie;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string* 字节集到ASCII文本(vector<int>待转换数据) {
	size_t S=待转换数据.size();
	char File;
	string FileS[1024];
	for (size_t i=0; i < S; i++)
	{
		File = 待转换数据[i];
		FileS [i]= File;
	}
	return FileS;
}
const char* 网页http_取域名(std::string 网址)
{
	CString WEB;
	size_t Pos;
	
	
	网址.replace(网址.find("http://"), 7, "");
	WEB = 网址.c_str();
	Pos = WEB.Find('/');
	WEB = WEB.Left(Pos);
	ret = CSringToString(WEB);
	XUGQ = ret.c_str();
	return (XUGQ);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t 网页_取端口(char* 网址)
{
	CString 端口, 中转;
	string 端口_T;
	size_t 位置, 长度;

	端口 = 网页http_取域名(网址);
	中转 = 端口.MakeReverse();
	位置 = 中转.Find(':');
	长度 = 端口.GetLength();
	端口_T = 取文本右边(端口, 长度 - 位置);

	if (位置 != -1)
	{
		return(atoi(端口_T.c_str()));
	}
	else
	{
		if (取文本左边(端口, 5) == "https")
		{
			return 443;
		}
		else
		{
			return 80;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* 网页_访问(
	char* 网址,
	char* 访问方式 = "POST",
	char* 提交信息 = "\0",
	CString 提交Cookies = _T(""), 
	vector<string> 返回Cookies = {""},
	CString 附加协议头 = (CString)"", 
	string 返回协议头 = "",
	bool 禁止重定向 = 1, 
	LPCSTR send = "http=",
	CString 代理地址 = (CString)"",
	vector<int>字节集提交 = { 0 })
{
	BOOL aaa, bbb;
	size_t 局_计次;
	int 局_请求标记;
	vector<string> CB;
	HINTERNET 局_Internet句柄, 局_Internet连接句柄, 局_HTTP请求句柄;
	DWORD  局_字节集=1024*1024;
	char*局_访问方式;
	LPCSTR 局_User_Agent=0;
	char 完整协议头[5000] = {0};
	string strStl, woca;
	strStl = CSringToString(附加协议头);
	CString* 局_返回Cookies;
	局_返回Cookies = new CString[5000];
	局_访问方式 = "POST";
	LPCSTR AAA = 0;
	DWORD len= sizeof(完整协议头);
	string *zzz;
	auto_ptr<char> szBuf(new char[局_字节集]);
	memset(szBuf.get(), 0, 局_字节集);
	const char*  域名aa;
	INTERNET_PORT 端口;
	域名aa = 网页http_取域名(网址);
    网页_取页面地址(网址, 域名aa);
	域名aa = 网页http_取域名(网址);
	端口 = 网页_取端口(网址);
	域名aa = 网页http_取域名(网址);
	if (寻找文本(strStl, "User-Agent:", 1) == string::npos)
	{
		局_User_Agent = strim(文本_取出中间文本(strStl, "User-Agent:", "\n")).c_str();
	}
	if (局_User_Agent == AAA)
	{
		局_User_Agent = 内部_协议头取值(strStl).c_str();
	}
	else
	{
		局_User_Agent = "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; 125LA; .NET CLR 2.0.50727; .NET CLR 3.0.04506.648; .NET CLR 3.5.21022)";
	}

	if (代理地址.IsEmpty())
	{
		局_Internet句柄 = InternetOpenA(局_User_Agent, 1, 0, 0, 0);
	}
	
	else
	{
		局_Internet句柄 = InternetOpenA(局_User_Agent, 3, (LPCSTR)CSringToString((CString)send+代理地址).c_str() , AAA, 0);
	}
	if (局_Internet句柄 == NULL)
	{
		InternetCloseHandle(局_Internet句柄);
		return{};
	}
	局_Internet连接句柄 = InternetConnectA(局_Internet句柄, 域名aa, 端口, AAA, AAA, 3, 0, 0);
	if (局_Internet连接句柄 == 0)
	{
		InternetCloseHandle(局_Internet连接句柄);
		InternetCloseHandle(局_Internet句柄);
		return{};
	}
	局_请求标记 = INTERNET_FLAG_RELOAD | INTERNET_COOKIE_THIRD_PARTY;

	if (!提交Cookies.IsEmpty())
	{
		局_请求标记 = 局_请求标记 | INTERNET_FLAG_NO_COOKIES;

	}
	if (!禁止重定向)
	{

		局_请求标记 = 局_请求标记 | INTERNET_FLAG_NO_AUTO_REDIRECT;
	}
	if (取文本左边((CString)网址, 5) == "https")
	{
		局_请求标记 = 局_请求标记 | INTERNET_FLAG_SECURE;
	}
	else
	{
		局_请求标记 = 局_请求标记 | INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS;
	}
	局_HTTP请求句柄 = HttpOpenRequestA(局_Internet连接句柄, "POST", 页面地址S, "HTTP/1.1", 0, 0, 局_请求标记, 0);
	if (局_HTTP请求句柄 == 0)
	{
		InternetCloseHandle(局_HTTP请求句柄);
		InternetCloseHandle(局_Internet连接句柄);
		InternetCloseHandle(局_Internet句柄);

		return{};
	}
	if (寻找文本(strStl, "Referer:") == string::npos)
	{
		if (strStl.empty())
		{
			strStl = strStl + "Referer:" + 网址;
		}
		else
		{
			strStl = strStl + '\r' + '\n' + "Referer:" + 网址;
		}
	}*/
	//为了上传成功 /**/ 改为//
	
	//if (寻找文本(strStl, "Accept:") == string::npos)
	//{
		//strStl = strStl + '\r' + '\n' + "Accept: */*";
	//}
	/*if (寻找文本(strStl, "Accept-Language:") == string::npos)
	{
		strStl = strStl + '\r' + '\n' + "Accept-Language: zh-cn";
	}
	if (寻找文本(strStl, "Content-Type:") == string::npos)
	{
		strStl = strStl + '\r' + '\n' + "Content-Type: application/x-www-form-urlencoded";
	}
	if (提交Cookies != "")
	{
		strStl = strStl + '\r' + '\n' + "Cookie: " + CSringToString(提交Cookies);
	}
	if (访问方式 != "POST")
	{
		HttpSendRequestA(局_HTTP请求句柄, strStl.c_str(), sizeof(strStl), "", 0);
	}
	else
	{
		if (!字节集提交.empty())
		{
			字节集提交.push_back(atoi(提交信息));
		}
		bbb=HttpSendRequestA(局_HTTP请求句柄, strStl.c_str(), strStl.size(), &字节集提交, 字节集提交.size());
	}
	局_计次 = 0;
	DWORD ki;
	while (true)
	{
	
		aaa = InternetReadFile(局_HTTP请求句柄, szBuf.get(),局_字节集,&ki);

		if (aaa == FALSE)
		{
			AfxMessageBox(L"获取数据失败!");
		}
		if (ki == 0)
		{
			break;
		}
		else
		{

		}
	}
	HttpQueryInfoA(局_HTTP请求句柄, 22, 完整协议头, &len, 0);
	InternetCloseHandle(局_HTTP请求句柄);
	InternetCloseHandle(局_Internet连接句柄);
	InternetCloseHandle(局_Internet句柄);
	返回Cookies = split(完整协议头, "\r\n");
	size_t i = 返回Cookies.size();
	string TS;
	for (局_计次; 局_计次<i;局_计次++)
	{
		TS = 返回Cookies[局_计次];
		if (寻找文本((返回Cookies[局_计次]), "Location:") != string::npos)
		{
			返回协议头 = 内部_协议头取值((返回Cookies[局_计次]));
		}
		if (寻找文本((返回Cookies[局_计次]), "Set-Cookie") != string::npos)
		{
			返回Cookies.push_back(strim(文本_取出中间文本((返回Cookies[局_计次]), "Set-Cookie:", ":")));
		}
	}
	
	if (!提交Cookies.IsEmpty())
	{
		网页_Cookie合并更新(CSringToString(提交Cookies),VecToString(返回Cookies).c_str());
	}
	if (返回协议头 == "")///////////这里是跳过的
	{

		返回协议头=完整协议头;
	}


	return szBuf.get();  //////////////////////////vector<int>{123,34,115,117,99,99,101,115,115,34,58,48,44,34,77,115,103,34,58,34,77,115,103,46,85,115,101,114,78,97,109,101,78,117,108,108,34,125}
	

}
*/
///////////////////////////////////////////////////////////////////////
//返回Cookies数组为  {“HTTP/1.1 200 OK”,“Server: Tengine/2.1.2”,“Date: Wed, 16 Nov 2016 07:05:07 GMT”,“Content-Type: text/html; charset=gb2312”,“Content-Length: 38”,“Connection: keep-alive”,“Cache-Control: private”,“X-AspNetMvc-Version: 4.0”,“X-AspNet-Version: 4.0.30319”,“X-Powered-By: ASP.NET”,“x-ip: 7”,“”}