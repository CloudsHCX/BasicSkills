/*
55 ��ʾ��ֵ���ַ���

��Ŀ����
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isNumeric(char* str)
	{
		//�ַ���Ϊ�շ���false
		if (str == NULL)
			return false;

		//������ʼ��'+','-'
		if (*str == '+' || *str == '-')
			str++;

		//������������ֵ����
		skipNumber(str);

		//����Ϊ����
		if (*str == '\0')
			return true;
		else if (*str == '.')
		{
			++str;
			skipNumber(str);
			if (*str == '\0')
				return true;
			else
			{
				return isExp(str);
			}
		}
		else if (*str == 'e' || *str == 'E')
		{
			return isExp(str);
		}
		else
			return false;

	}

	//�ж�e��E����֮���Ƿ�Ϊָ��ʽ
	bool isExp(char* & str)
	{
		if (*str != 'e' && *str != 'E')
		{
			return false;
		}

		++str;

		//����e��E֮���+��-����
		if (*str == '+' || *str == '-')
		{
			++str;
		}

		//+��-֮��û����ֵ������false
		if (*str == '\0')
		{
			return false;
		}
		
		skipNumber(str);

		return (*str == '\0') ? true : false;
	}

	//�������ֲ���
	void skipNumber(char* & str)
	{
		while (*str != '\0' && *str >= '0' && *str <= '9')
		{
			str++;
		}
	}
};