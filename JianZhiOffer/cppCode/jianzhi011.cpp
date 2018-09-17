/*
011 ��̬��̨��
��Ŀ����

һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*/

/*
��������������ö�̬�滮��⡣
	  ��n��̨�׾��ߣ� dp[n] = dp[n-1]+dp[n-2]+...+dp[0];

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
		vector<int> dp(number+1, 0);
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
			dp[1] = 1;
			dp[2] = 2; 
			for(int i = 3; i <= number; i++)
			{
				int j = 1;
				while(j <= i)
				{
					dp[i] += dp[i-j];
					j++;
				}
			}
			return dp[number];
		}
    }
};