/*
032 ���������������

��Ŀ����
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:
�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
*/

/*
���������Ե��ɶ�̬�滮����⡣dp[i]�����־���
				1.dp[i-1] < 0, dp[i] = arr[i]
				2. dp[i-1] >=0, dp[i] = dp[i-1] + arr[i]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> arr) {
    
		int len = arr.size();
		if(arr.empty())
			return 0;
		
		vector<int> dp(len);
		dp[0] = arr[0];

		for(int i = 1; i < len; i++)
		{
			if(dp[i-1] > 0)
				dp[i] = dp[i-1] + arr[i];
			else
				dp[i] = arr[i];
		}
		vector<int>::iterator big = max_element(dp.begin(), dp.end());
		return *big;
    }
};