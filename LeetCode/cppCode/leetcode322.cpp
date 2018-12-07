
/*
������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ����� -1��

ʾ�� 1:

����: coins = [1, 2, 5], amount = 11
���: 3 
����: 11 = 5 + 5 + 1
ʾ�� 2:

����: coins = [2], amount = 3
���: -1
˵��:
�������Ϊÿ��Ӳ�ҵ����������޵ġ�
*/
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
			if(amount < 0 )
				return -1;

			vector<int> dp(amount);
			return search(coins, amount,dp);
		}

		int search(vector<int>& coins, int rem, vector<int>& dp )
		{
		//���ʣ�µ�ǮС��0������-1
			if(rem < 0)
				return -1;
		//ʣ�µ�Ǯ�պ�Ϊ0��,˵���ոպÿ������ꡣ
			if(rem == 0)
				return 0;

			//����¼���洢
			if(dp[rem-1] != 0 )
				return dp[rem-1];

		//�����ֵ���棬��ʾ��С���ų�����-1��������ֵ����
			int min = numeric_limits<int> :: max();
			for(int i=0; i< coins.size(); ++i)
			{
				int res = search(coins, rem-coins[i],dp);
				if(res >=0 && res <min)
					min = 1+res;


			}
			return dp[rem-1] =(min == numeric_limits<int> :: max() ? -1: min);
	}
};

