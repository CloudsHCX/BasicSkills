/*
050 ���üӼ��˳����ӷ�

��Ŀ����
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*/

#include <iostream>
class Solution {
public:
	int Add(int num1, int num2)
	{
		int flag = 1, carry = 0;
		int res = 0;
		while (flag)
		{
			res |= (carry ^ (num1 & flag) ^ (num2 & flag))>>1;
		}
	}
};