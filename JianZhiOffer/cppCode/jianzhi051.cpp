/*
052 ���ַ���ת��������
��Ŀ����
��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��
Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
��������:
����һ���ַ���,����������ĸ����,����Ϊ��
�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
*/

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {

		int len = str.size();
		if (len == 0)
			return 0;

		bool flag = true;
		string cal_str;
		if (str[0] == '+' || str[0] == '-')
		{
			flag = str[0] == '+' ? true : false;
			cal_str = str.substr(1, len);
		}
		else
			cal_str = str;

		//ȡȥ������λ�Ĳ��֣�ת��Ϊint
		int length = cal_str.size();
		int res = 0;
		for(int i = 0; i < length; i++)
		{
			if (cal_str[i] >= '0' && cal_str[i] <= '9')
			{
				res = (cal_str[i] - '0') + res * 10;
			}
			else
				return 0;
		}
		return flag ? res : -res;
	}
};