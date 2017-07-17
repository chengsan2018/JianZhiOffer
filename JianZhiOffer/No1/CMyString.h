//��Ŀ��ΪCMyString��Ӹ�ֵ���������
// �����쳣��ȫ��ԭ�򣬵���ֵ�����=�����ڲ��׳��쳣ʱ��ԭ����Ӧ����Ӧ��״̬
//���Ҫ�ȷ����ڴ棬�ڷ������ݳɹ������ͷ��ڴ�

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

	//ΪCMyString��Ӹ�ֵ�����������ע��ֵ�����Ҫ�������ã���
	CMyString& operator =(const CMyString & str);  
private:
	char* m_pData;
};

CMyString::CMyString(char * pData)
{
	if (pData)
	{
		delete[] m_pData;
		int len = strlen(pData);     //strlen()�Ǽ����ַ����ĳ��ȣ��������ַ���ĩβ�ġ�\0��!!!
		try
		{
			m_pData = new char[len + 1]; //�����ڴ�ʱ��Ӧ����'\0',
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
		int len = strlen(str.m_pData);     //strlen()�Ǽ����ַ����ĳ��ȣ��������ַ���ĩβ�ġ�\0��!!!
		try
		{
			m_pData = new char[len + 1]; //�����ڴ�ʱ��Ӧ����'\0',
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

//����ⷨ
// CMyString& CMyString::operator=(const CMyString &str)
// {
// 	if (this != &str)  //����Ƿ��������
// 	{
// 		if (str.m_pData)  // str.m_pData ��Ϊ��
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

//�߼��ⷨ
CMyString& CMyString::operator=(const CMyString &str)
{
	if (this != &str)  //����Ƿ��������'֤ͬ����'
	{
		//����copy and swap ����
		CMyString strTemp(str); 

		char * pTemp = strTemp.m_pData; //��������
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	//��������Զ��ͷ�strTemp
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