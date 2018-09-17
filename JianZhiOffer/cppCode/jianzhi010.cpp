/*
010 ��̨��
��Ŀ����

һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/

/*
��������������ö�̬�滮˼����������n�׵ľ��ߣ�
		��n��̨�׵����� = ��n-1��̨�׵�����+��n-2��̨�׵�������
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
		vector<int> dp(number);
		switch (number)
		{
		case 0: 
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			dp[0] = 1;
			dp[1] = 2;
			for(int i = 2; i < number; i++)
				dp[i] = dp[i-1] + dp[i-2];
			return dp[number-1];
		}

    }
};