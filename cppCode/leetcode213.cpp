/*
213. House Robber II

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this 
place are arranged in a circle. That means the first house is the neighbor 
of the last one. Meanwhile, adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were 
broken into on the same night.

Given a list of non-negative integers representing the amount of money of 
each house, determine the maximum amount of money you can rob tonight without 
alerting the police.

����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�
����ط����еķ��ݶ�Χ��һȦ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�
Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.


*/

/*
������ ������198��һ����չ��
	ֻ��Ҫ������n������һ�����У��Ϳ��Խ����1�����ѡ��n��������ӦΪ 1...n
											   2�������ѡ��n��������ӦΪ 0...n-1
	�ֱ���д���ȡ��������󼴿ɡ�

����
      1 2 3 1
1��dp   2 3 3   1...n����
2��dp 1 2 4     0...n-1����

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
			return max(getMaxMoney(nums,0, nums.size()-2), getMaxMoney(nums, 1, nums.size()-1));
		}
    }

	//start������ʵλ�ã�Ϊ0��1��endΪ�յ㣬��Ӧn-1��n
	int getMaxMoney(const vector<int> &nums, int start, int end)
	{
		int len = nums.size();
		//��Ȼ���붼�Ǵ���2�ģ����������ı��ϰ����Ҫ�ӱ���
		if(len < 3)
			return 0;

		vector<int> dp(end-start+1);

		dp[0] = nums[start];
		dp[1] = max(nums[start+1], nums[start]);

		//����״̬ת�Ʒ��̣���䶯̬�滮���飬Ҫ����start������ƫ�ơ�
		for(int i=2; i<end-start+1; ++i)	
		{
			dp[i] = max(dp[i-1],dp[i-2]+nums[i+start]);
		}
		return dp[end-start];
	}
	
};