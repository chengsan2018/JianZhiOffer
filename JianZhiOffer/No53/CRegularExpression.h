#ifndef _CREGULAREXPRESSION_H
#define _CREGULAREXPRESSION_H

#include <iostream>

using namespace std;

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
	{
		return false;
	}
	matchCore(str, pattern);

}

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
	{
		return true;
	}

	if (*str != '\0' && *pattern == '\0') // ģʽ����
	{
		return false;
	}

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0')) // ���a = a*
		{
			return matchCore(str + 1, pattern + 2) //* = 1 : ab  and  a*b
				|| matchCore(str + 1, pattern)     //* = ���� : aa  and  a*b
				|| matchCore(str, pattern + 2);    //* = 0 : a and a*a
		}
		else                                       //���a��= a*  
			return matchCore(str, pattern + 2);    //a and b*a ---- ignore* �� * = 0;
	}

	// pattern + 1 != '*'
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))  // ab and ab /.b
	{
		return matchCore(str + 1, pattern + 1);
	}
}

#endif
