#ifndef _CREPLACESPACE_H
#define _CREPLACESPACE_H

#include <string>

using namespace std;
void ReplaceSpace(char* &str) //����ָ�������
{
	int oldLen = strlen(str);  //ԭ�ַ����ĳ���
	//ͳ��ԭ�ַ����пո������
	int spaceNum = 0;
	for (int i = 0; i < oldLen;i++)
	{
		if (str[i] == ' ')
			spaceNum++;
	}
	char *newStr = NULL;
	if (spaceNum)
	{
		newStr = new char[oldLen + 2*spaceNum + 1];
		newStr[oldLen + 2 * spaceNum] = '\0';
		for (int i = oldLen - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				newStr[i + 2 * spaceNum] = str[i];
			}
			else
			{
				newStr[i + 2 * spaceNum] = '0';
				newStr[i + 2 * spaceNum - 1] = '2';
				newStr[i + 2 * spaceNum - 2] = '%';
				spaceNum--;
			}
		}
		char * temp = newStr;
		newStr = str;
		str = temp;
		//delete[] newStr;
	}
}

#endif