//题目：为CMyString添加赋值运算符函数
// 考虑异常安全性原则，当赋值运算符=函数内部抛出异常时，原对象应保持应有状态
//因此要先分配内存，在分配内容成功后再释放内存

#ifndef _CMYSTRING_H
#define _CMYSTRING_H
#include <string>
#include <iostream>
#include <exception>
using namespace std;

class CMyString
{
public:
	CMyString(char * pData = NULL);
	CMyString(const CMyString & str);
	~CMyString();

	//为CMyString添加赋值运算符函数，注赋值运算符要返回引用！！
	CMyString& operator =(const CMyString & str);  
private:
	char* m_pData;
};

CMyString::CMyString(char * pData)
{
	if (pData)
	{
		delete[] m_pData;
		int len = strlen(pData);     //strlen()是计算字符串的长度，不包括字符串末尾的“\0”!!!
		try
		{
			m_pData = new char[len + 1]; //申请内存时，应包含'\0',
		}
		catch (bad_alloc e)
		{
			cout << "Out of memory!!!" << endl;
			exit(1);
		}
		strcpy(m_pData, pData);
	}
	else
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
		m_pData = NULL;
	}
}

CMyString::CMyString(const CMyString & str)
{
	if (str.m_pData)
	{
		delete[] m_pData;
		int len = strlen(str.m_pData);     //strlen()是计算字符串的长度，不包括字符串末尾的“\0”!!!
		try
		{
			m_pData = new char[len + 1]; //申请内存时，应包含'\0',
		}
		catch (bad_alloc e)
		{
			cout << "Out of memory!!!" << endl;
			exit(1);
		}
		strcpy(m_pData, str.m_pData);
	}
	else
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
		m_pData = NULL;
	}
}

//常规解法
// CMyString& CMyString::operator=(const CMyString &str)
// {
// 	if (this != &str)  //检查是否等于自身
// 	{
// 		if (str.m_pData)  // str.m_pData 不为空
// 		{
// 			delete[] m_pData;
// 			int len = strlen(str.m_pData);
// 			m_pData = new char[len + 1];
// 			strcpy(m_pData, str.m_pData);
// 		}
// 		else
// 		{
// 			m_pData = new char[1];
//          m_pData[0] = '\0';
// 			m_pData = NULL;
// 		}
//  }
// 	return (*this);
// }

//高级解法
CMyString& CMyString::operator=(const CMyString &str)
{
	if (this != &str)  //检查是否等于自身，'证同测试'
	{
		//采用copy and swap 技术
		CMyString strTemp(str); 

		char * pTemp = strTemp.m_pData; //交换对象
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	//括号外会自动释放strTemp
	return *this;
}

CMyString::~CMyString()
{
	if (m_pData)
	{
		delete[] m_pData;
	}
	m_pData = NULL;

}

#endif