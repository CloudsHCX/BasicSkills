/*
8. String to Integer (atoi)

*/
#include <string>
#include <iostream>
#include <sstream>
#include <limits> 
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int flag = 1;//����λ,Ĭ��Ϊ1��������-1����
		long ans = 0;//���ֲ���
		int i = 0, len = str.size();

		while (i < len && str[i] == ' ')
			i++;

		//����λ����
		if (str[i] == '-' || str[i] == '+')
		{
			flag = str[i] == '-' ? -1 : 1;
			i++;
		}


		//���ֲ��ִ���
		while (i < len && str[i] >= '0' && str[i] <= '9')
		{
			ans = ans * 10 + str[i] - '0';
			//��������Խ��
			if (flag == 1 && ans > numeric_limits<int>::max())
			{
				return numeric_limits<int>::max();
			}
			//��������Խ��
			if (flag == -1 && (-1 * ans) < numeric_limits<int>::min())
			{
				return numeric_limits<int>::min();
			}
			i++;
		}
		return flag * ans;
	}
};