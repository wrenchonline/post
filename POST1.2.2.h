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
string ҳ���ַ;

char* ҳ���ַS;
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
vector<int> ȡ�ֽڼ����(vector<int> ��ȡ�ֽڼ�, size_t s)
{
	vector<int> ��������;
	memcpy(&��������, &��ȡ�ֽڼ�, s);
	return ��������;
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
INT ��ԭ��ַ(string �ı���ַ)
{
	int ת����ַ = 0;
	char ��ʱ����[256] = { 0 };
	strcpy_s(��ʱ����, �ı���ַ.c_str());
	sscanf_s(��ʱ����, "%x", &ת����ַ);
	return ת����ַ;
}
string ȡ�ı��ұ�(CString ��ȡ�䲿�ֵ��ı�, int ��ȡ���ַ���Ŀ)
{
	CString str = ��ȡ�䲿�ֵ��ı�.Right(��ȡ���ַ���Ŀ);
	CStringA stra(str.GetBuffer(0));
	str.ReleaseBuffer();
	string strb = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return strb;
}
string CSringToString(CString ��ת���ı�)
{
	CStringA stra(��ת���ı�.GetBuffer(0));
	��ת���ı�.ReleaseBuffer();
	std::string stdStr = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return stdStr;
}
int Ѱ���ı�(string Ѱ���ı�, string Ѱ������, ...)
{
	va_list arguments;
	int ��ʼλ�� = 1;
	va_start(arguments, Ѱ������);
	��ʼλ�� = va_arg(arguments, int);

	string st(Ѱ���ı�);
	size_t  position;

	position = st.find(Ѱ������, ��ʼλ��);
	while (position != string::npos)
	{
		position = st.find(Ѱ������, position);

	}
	va_end(arguments);
	return position;
}
string strim(string &str)

{

	str.erase(str.find_last_of(' ') + 1, string::npos);    //ȥ���ַ���ĩβ�ո�  
	str.erase(0, str.find_first_of(' '));    //ȥ���ַ����׿ո�  
	return str;
}
string ȡ�ı��м�(CString ��ȡ�䲿�ֵ��ı�, int ��ʼȡ��λ��, int ��ȡ���ַ���Ŀ)
{
	CString str = ��ȡ�䲿�ֵ��ı�.Mid(��ʼȡ��λ��, ��ȡ���ַ���Ŀ);
	CStringA stra(str.GetBuffer(0));
	str.ReleaseBuffer();
	string strb = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return strb;
}
string �ı�_ȡ���м��ı�(string ��ȡ���ı�, string ǰ����ı�, string ������ı�)
{
	CString strMfc;
	string ǰ���ı�, �����ı�,���ı�;
	int ǰ���ı�λ��, �����ı�λ��;

	ǰ���ı�λ�� = Ѱ���ı�(��ȡ���ı�, ǰ����ı�, 1);
	�����ı�λ�� = Ѱ���ı�(��ȡ���ı�, ������ı�, 1);
	strMfc = ��ȡ���ı�.c_str();
	if (ǰ���ı�λ�� != -1)
	{
		ǰ���ı�λ�� = ǰ���ı�λ�� + sizeof(ǰ���ı�);
	}
	�����ı�λ�� = Ѱ���ı�(��ȡ���ı�, �����ı�, ǰ���ı�λ��);
	if (ǰ���ı�λ�� == string::npos || �����ı�λ�� == string::npos)
	{
		return ���ı�;
	}
	return(ȡ�ı��м�(strMfc, ǰ���ı�λ��, �����ı�λ�� - ǰ���ı�λ��));
}
string �ڲ�_Э��ͷȡֵ(string Э��ͷ)
{
	int λ��;
	CString strMfc;
	strMfc = Э��ͷ.c_str();
	string ���;
	λ�� = Ѱ���ı�(Э��ͷ, ":");
	if (λ�� != string::npos)
	{
		��� = ȡ�ı��ұ�(strMfc, sizeof(Э��ͷ) - λ��);
	}
	return strim(���);
}
string ȡ�ı����(CString ��ȡ�䲿�ֵ��ı�, int ��ȡ���ַ���Ŀ)
{
	CString str = ��ȡ�䲿�ֵ��ı�.Left(��ȡ���ַ���Ŀ);
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
vector<int> ���ֽڼ�(int a)
{
	string s = _Int2Hex(a, 8);
	int ���� = s.length();
	if (���� % 2 != 0)
	{
		���� = ���� + 1;
	}
	vector<int> ���(���� / 2, 0);
	for (int i = 0; i < ���� / 2; i++)
	{
		���[i] = ��ԭ��ַ(s.substr(i * 2, 2));
	}
	return ���;
}
vector<int> VectorToAdd(vector<int> a, vector<int> b)
{
	vector<int> �ϲ�����;
	for (int i = 0; i<sizeof(a); i++)
	{
		�ϲ�����.push_back(a[i]);
	}
	for (int i = 0; i<sizeof(b); i++)
	{
		�ϲ�����.push_back(b[i]);
	}
	return �ϲ�����;
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
char*  ��ҳ_ȡҳ���ַ(string ��ַ, const char* SAFFA) {
	int ����λ��;
	string ����aaa=SAFFA;
	����λ�� = ����aaa.size() + 7;
	if (����λ��>0)
	{
		ҳ���ַ = ȡ�ı��ұ�((CString)��ַ.c_str(), ��ַ.size() - ����λ��);
	}
	else
	{
		ҳ���ַ = "/";
	}
	ҳ���ַS = (char*)ҳ���ַ.data();
	return(ҳ���ַS);
}
int �ڲ�_�����Ա�Ƿ����_�ı�(string SDR, string Ҫ�жϵ�ֵ)
{
	int s;
	s=SDR.find(Ҫ�жϵ�ֵ);
	return s;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CString  �ı�_ȥ�ظ��ı�(CString ԭ�ı�, string �ָ���)
{
	vector<string> CStr;
	vector<string> CStrone;
	string str;
	CStr=split(CSringToString(ԭ�ı�),�ָ���);
	size_t S = CStr.size();
	for (size_t i = 0; i < S; i++)
	{
		if (�ڲ�_�����Ա�Ƿ����_�ı�(VecToString(CStrone), �ָ���) == string::npos)
		{
			CStrone.push_back(CStr[i]);
			str += CStr[i];
			str += �ָ���;
		}
	}
	str = ȡ�ı��ұ�((CString)str.c_str(), str.size() - sizeof(�ָ���)).c_str();

	return (CString)str.c_str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string �ڲ�_Cookieȡ��(string Cookie)
{
	int λ��;
	string ���;
	λ�� = Ѱ���ı�(Cookie, "=");
	if (λ�� != string::npos)
	{
		��� = ȡ�ı����((CString)Cookie.c_str(), λ�� - 1);
	}
	else
	{
		��� = Cookie;
	}
	return strim(���);
}
BOOL �ڲ�_�����Ա�Ƿ����1(string ����[], string Ҫ�ж�ֵ)
{
	for (int ��_�ƴ� = 0; sizeof(����); ��_�ƴ�++)
	{
		if (�ڲ�_Cookieȡ��(����[��_�ƴ�]) == Ҫ�ж�ֵ)
		{
			return TRUE;
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ��ҳ_Cookie�ϲ�����(string ��Cookie, string ��Cookie)
{
	vector<string>��_��Cookie��, ��_��Cookie��;
	size_t ��_�ƴ�;
	��Cookie=replace_all(��Cookie, " ", "");
	��Cookie=replace_all(��Cookie, " ", "");
	��_��Cookie�� = split(��Cookie, ";");
	��_��Cookie�� = split(��Cookie, ";");

	for (��_�ƴ�=0; ��_�ƴ� < sizeof(��Cookie); ��_�ƴ�++)
	{
		if (�ڲ�_�����Ա�Ƿ����1(&VecToString(��_��Cookie��), �ڲ�_Cookieȡ��(��_��Cookie��[��_�ƴ�]))==0)
		{
			��_��Cookie��.push_back(��_��Cookie��[��_�ƴ�]);
		}
	}
	��Cookie.clear();
	size_t S = ��_��Cookie��.size();
	for (��_�ƴ�=0; ��_�ƴ�<S; ��_�ƴ�++)
	{
		if (ȡ�ı��ұ�((CString)��_��Cookie��[��_�ƴ�].c_str(), 8) != "=deleted")
		{
			��Cookie += ��_��Cookie��[��_�ƴ�] ;
			��Cookie += "; ";
		}
	}
	��Cookie = ȡ�ı����((CString)��Cookie.c_str(), sizeof(��Cookie) - 2).c_str();
	��Cookie = CSringToString(�ı�_ȥ�ظ��ı�((CString)��Cookie.c_str(), "; "));
	return ��Cookie;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string* �ֽڼ���ASCII�ı�(vector<int>��ת������) {
	size_t S=��ת������.size();
	char File;
	string FileS[1024];
	for (size_t i=0; i < S; i++)
	{
		File = ��ת������[i];
		FileS [i]= File;
	}
	return FileS;
}
const char* ��ҳhttp_ȡ����(std::string ��ַ)
{
	CString WEB;
	size_t Pos;
	
	
	��ַ.replace(��ַ.find("http://"), 7, "");
	WEB = ��ַ.c_str();
	Pos = WEB.Find('/');
	WEB = WEB.Left(Pos);
	ret = CSringToString(WEB);
	XUGQ = ret.c_str();
	return (XUGQ);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t ��ҳ_ȡ�˿�(char* ��ַ)
{
	CString �˿�, ��ת;
	string �˿�_T;
	size_t λ��, ����;

	�˿� = ��ҳhttp_ȡ����(��ַ);
	��ת = �˿�.MakeReverse();
	λ�� = ��ת.Find(':');
	���� = �˿�.GetLength();
	�˿�_T = ȡ�ı��ұ�(�˿�, ���� - λ��);

	if (λ�� != -1)
	{
		return(atoi(�˿�_T.c_str()));
	}
	else
	{
		if (ȡ�ı����(�˿�, 5) == "https")
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
char* ��ҳ_����(
	char* ��ַ,
	char* ���ʷ�ʽ = "POST",
	char* �ύ��Ϣ = "\0",
	CString �ύCookies = _T(""), 
	vector<string> ����Cookies = {""},
	CString ����Э��ͷ = (CString)"", 
	string ����Э��ͷ = "",
	bool ��ֹ�ض��� = 1, 
	LPCSTR send = "http=",
	CString �����ַ = (CString)"",
	vector<int>�ֽڼ��ύ = { 0 })
{
	BOOL aaa, bbb;
	size_t ��_�ƴ�;
	int ��_������;
	vector<string> CB;
	HINTERNET ��_Internet���, ��_Internet���Ӿ��, ��_HTTP������;
	DWORD  ��_�ֽڼ�=1024*1024;
	char*��_���ʷ�ʽ;
	LPCSTR ��_User_Agent=0;
	char ����Э��ͷ[5000] = {0};
	string strStl, woca;
	strStl = CSringToString(����Э��ͷ);
	CString* ��_����Cookies;
	��_����Cookies = new CString[5000];
	��_���ʷ�ʽ = "POST";
	LPCSTR AAA = 0;
	DWORD len= sizeof(����Э��ͷ);
	string *zzz;
	auto_ptr<char> szBuf(new char[��_�ֽڼ�]);
	memset(szBuf.get(), 0, ��_�ֽڼ�);
	const char*  ����aa;
	INTERNET_PORT �˿�;
	����aa = ��ҳhttp_ȡ����(��ַ);
    ��ҳ_ȡҳ���ַ(��ַ, ����aa);
	����aa = ��ҳhttp_ȡ����(��ַ);
	�˿� = ��ҳ_ȡ�˿�(��ַ);
	����aa = ��ҳhttp_ȡ����(��ַ);
	if (Ѱ���ı�(strStl, "User-Agent:", 1) == string::npos)
	{
		��_User_Agent = strim(�ı�_ȡ���м��ı�(strStl, "User-Agent:", "\n")).c_str();
	}
	if (��_User_Agent == AAA)
	{
		��_User_Agent = �ڲ�_Э��ͷȡֵ(strStl).c_str();
	}
	else
	{
		��_User_Agent = "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; 125LA; .NET CLR 2.0.50727; .NET CLR 3.0.04506.648; .NET CLR 3.5.21022)";
	}

	if (�����ַ.IsEmpty())
	{
		��_Internet��� = InternetOpenA(��_User_Agent, 1, 0, 0, 0);
	}
	
	else
	{
		��_Internet��� = InternetOpenA(��_User_Agent, 3, (LPCSTR)CSringToString((CString)send+�����ַ).c_str() , AAA, 0);
	}
	if (��_Internet��� == NULL)
	{
		InternetCloseHandle(��_Internet���);
		return{};
	}
	��_Internet���Ӿ�� = InternetConnectA(��_Internet���, ����aa, �˿�, AAA, AAA, 3, 0, 0);
	if (��_Internet���Ӿ�� == 0)
	{
		InternetCloseHandle(��_Internet���Ӿ��);
		InternetCloseHandle(��_Internet���);
		return{};
	}
	��_������ = INTERNET_FLAG_RELOAD | INTERNET_COOKIE_THIRD_PARTY;

	if (!�ύCookies.IsEmpty())
	{
		��_������ = ��_������ | INTERNET_FLAG_NO_COOKIES;

	}
	if (!��ֹ�ض���)
	{

		��_������ = ��_������ | INTERNET_FLAG_NO_AUTO_REDIRECT;
	}
	if (ȡ�ı����((CString)��ַ, 5) == "https")
	{
		��_������ = ��_������ | INTERNET_FLAG_SECURE;
	}
	else
	{
		��_������ = ��_������ | INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS;
	}
	��_HTTP������ = HttpOpenRequestA(��_Internet���Ӿ��, "POST", ҳ���ַS, "HTTP/1.1", 0, 0, ��_������, 0);
	if (��_HTTP������ == 0)
	{
		InternetCloseHandle(��_HTTP������);
		InternetCloseHandle(��_Internet���Ӿ��);
		InternetCloseHandle(��_Internet���);

		return{};
	}
	if (Ѱ���ı�(strStl, "Referer:") == string::npos)
	{
		if (strStl.empty())
		{
			strStl = strStl + "Referer:" + ��ַ;
		}
		else
		{
			strStl = strStl + '\r' + '\n' + "Referer:" + ��ַ;
		}
	}*/
	//Ϊ���ϴ��ɹ� /**/ ��Ϊ//
	
	//if (Ѱ���ı�(strStl, "Accept:") == string::npos)
	//{
		//strStl = strStl + '\r' + '\n' + "Accept: */*";
	//}
	/*if (Ѱ���ı�(strStl, "Accept-Language:") == string::npos)
	{
		strStl = strStl + '\r' + '\n' + "Accept-Language: zh-cn";
	}
	if (Ѱ���ı�(strStl, "Content-Type:") == string::npos)
	{
		strStl = strStl + '\r' + '\n' + "Content-Type: application/x-www-form-urlencoded";
	}
	if (�ύCookies != "")
	{
		strStl = strStl + '\r' + '\n' + "Cookie: " + CSringToString(�ύCookies);
	}
	if (���ʷ�ʽ != "POST")
	{
		HttpSendRequestA(��_HTTP������, strStl.c_str(), sizeof(strStl), "", 0);
	}
	else
	{
		if (!�ֽڼ��ύ.empty())
		{
			�ֽڼ��ύ.push_back(atoi(�ύ��Ϣ));
		}
		bbb=HttpSendRequestA(��_HTTP������, strStl.c_str(), strStl.size(), &�ֽڼ��ύ, �ֽڼ��ύ.size());
	}
	��_�ƴ� = 0;
	DWORD ki;
	while (true)
	{
	
		aaa = InternetReadFile(��_HTTP������, szBuf.get(),��_�ֽڼ�,&ki);

		if (aaa == FALSE)
		{
			AfxMessageBox(L"��ȡ����ʧ��!");
		}
		if (ki == 0)
		{
			break;
		}
		else
		{

		}
	}
	HttpQueryInfoA(��_HTTP������, 22, ����Э��ͷ, &len, 0);
	InternetCloseHandle(��_HTTP������);
	InternetCloseHandle(��_Internet���Ӿ��);
	InternetCloseHandle(��_Internet���);
	����Cookies = split(����Э��ͷ, "\r\n");
	size_t i = ����Cookies.size();
	string TS;
	for (��_�ƴ�; ��_�ƴ�<i;��_�ƴ�++)
	{
		TS = ����Cookies[��_�ƴ�];
		if (Ѱ���ı�((����Cookies[��_�ƴ�]), "Location:") != string::npos)
		{
			����Э��ͷ = �ڲ�_Э��ͷȡֵ((����Cookies[��_�ƴ�]));
		}
		if (Ѱ���ı�((����Cookies[��_�ƴ�]), "Set-Cookie") != string::npos)
		{
			����Cookies.push_back(strim(�ı�_ȡ���м��ı�((����Cookies[��_�ƴ�]), "Set-Cookie:", ":")));
		}
	}
	
	if (!�ύCookies.IsEmpty())
	{
		��ҳ_Cookie�ϲ�����(CSringToString(�ύCookies),VecToString(����Cookies).c_str());
	}
	if (����Э��ͷ == "")///////////������������
	{

		����Э��ͷ=����Э��ͷ;
	}


	return szBuf.get();  //////////////////////////vector<int>{123,34,115,117,99,99,101,115,115,34,58,48,44,34,77,115,103,34,58,34,77,115,103,46,85,115,101,114,78,97,109,101,78,117,108,108,34,125}
	

}
*/
///////////////////////////////////////////////////////////////////////
//����Cookies����Ϊ  {��HTTP/1.1 200 OK��,��Server: Tengine/2.1.2��,��Date: Wed, 16 Nov 2016 07:05:07 GMT��,��Content-Type: text/html; charset=gb2312��,��Content-Length: 38��,��Connection: keep-alive��,��Cache-Control: private��,��X-AspNetMvc-Version: 4.0��,��X-AspNet-Version: 4.0.30319��,��X-Powered-By: ASP.NET��,��x-ip: 7��,����}