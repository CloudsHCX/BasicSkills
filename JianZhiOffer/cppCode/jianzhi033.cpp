/*
033 ������1���ֵĴ�������1��n������1���ֵĴ�����

��Ŀ����
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,
���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������
*/

/*
����������һ����ÿһ�������м���1�ĸ�����ͳ��
	  ���������ҹ��ɣ�1�Ĵ�������ʮ��ǧλ�������йء�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		int count = 0;
		for(int i = 1; i <= n; i++)
		{
			count += countOne(i);
		}

		return count;
    }

private:
	int countOne(int n)
	{
		int count = 0;
		while(n)
		{
			if(n % 10 == 1)
				count++;
			n /= 10;
		}
		return count;
	}
};