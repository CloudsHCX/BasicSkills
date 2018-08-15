/*
198. House Robber

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.

����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�
Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ��
����������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

/*
����:��������ö�̬�滮��⣬ӵ�������ӽṹ����n-1�����Ƶ���n�����޺�Ч�ԡ�
     ��iλ�������־��ߣ�
	 1������i�����ݣ�����߽�� = ����i-2����߽�� + ��ǰ������� dp[i] = dp[i-2] + nums[i]
	 2��������i�����ݣ�����߽�� = ����i-1����߽��� dp[i] = dp[i-1]

	 ����״̬ת�Ʒ��̣�			
			dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
	
	dp[i]��ʾ����i�������ܹ���õ���߽��

����  2 7  9  3  1
   dp 2 7 11 11 12
*/


#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        
		switch(nums.size())
		{
		case 0:
			return 0;
		case 1:
			return nums[0];
		case 2:
			return max(nums[0],nums[1]);
		default:
			return getMaxMonoey(nums);
		}
    }

	int getMaxMonoey(const vector<int> &nums)
	{
		int len = nums.size();
		//��Ȼ���붼�Ǵ���2�ģ����������ı��ϰ����Ҫ�ӱ���
		if(len < 3)
			return 0;

		vector<int> dp(len);

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
			
		//����״̬ת�Ʒ��̣���䶯̬�滮���顣
		for(int i=2; i<len; ++i)
		{
			dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
		}
		return dp[len-1];
	}
	
};