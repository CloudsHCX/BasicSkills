/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
*/

/*
�����������ö�̬�滮��˼����������ǰnλ�ܹ��ж��ٱ��뷽ʽ��ȡ����n-1λ���ж����֡�
	��iλ����2�־��ߣ�
	1����i-1λ��iλ��ɵ�������[1,26],���iλ��������=��i-1λ��������+��i-2Ϊ��������
	2����i-1λ��iλ��ɵ���>26,���iλ��������=��i-1λ��������

	����д����Ӧ��״̬ת�Ʒ��̡�
		1<=s[i-1]s[i]<=26:dp[i] = dp[i-1] + dp[i-2]
		s[i-1]s[i]>26:dp[i] = dp[i-1] 
����  1 2 1 2 1 2
   dp 1 2 3 5 8 13

ע����Ҫ����ΪiλΪ0���������Ȼ��Ŀ��û����ȷ��ʾ�����ǲ�����������0�������
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    
		int len = s.size();

		//�����������
		if(!len || s[0] == '0')
			return 0;

		vector<int> dp(len);

		dp[0]=1;
		for(int i=1; i < len; ++i)
		{
			//���s[i]=='0'�����������1��s[i-1]Ϊ1��2����dp[i] = dp[i-2] (Ҫ����i-2<0)
			//                           2) s[i-2]!= 1��2,��˴ν�����Ч�� 
			if (s[i] == '0')
			{
				if (s[i-1] == '1' || s[i-1] == '2')
					dp[i] = i-1 > 0 ? dp[i-2]:dp[i-1];
				else
					return 0;
			}
			//���s[i]!='0'�����������  1��s[i-1]s[i]����[1,26],��dp[i] = dp[i-1] + dp[i-2]
			//                           2) s[i-1]s[i]>26,��dp[i] = dp[i-1] 
			else
			{
				if(s[i-1] == '1' && s[i] != '0')
					dp[i] = dp[i-1]+(i-1 > 0 ? dp[i-2]:1);
				else if (s[i-1] == '2' && ((s[i]-'0'>0) && (s[i]-'0')<7))
					dp[i] = dp[i-1]+(i-1 > 0 ? dp[i-2]:1);
				else 
					dp[i] = dp[i-1];
			}
		}
		return dp[len-1];
	}
};