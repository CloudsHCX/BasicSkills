/*
012 ���θ���
��Ŀ����

���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
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