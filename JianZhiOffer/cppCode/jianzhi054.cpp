/*
054 ������ʽƥ��

��Ŀ����
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		int sLen, pLen;
		sLen = strlen(str);
		pLen = strlen(pattern);

		//DP���飬�б�ʾp���б�ʾs�� dp[i][j] ��ʾ s[0..i-1] �� p[0..j-1]��ƥ�����
		vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));

		//��ʼ�����֣�����dp[0][0]Ϊ1��dp[0][j]Ҫ����p[j-1]��״̬������
		//���Բο�һ��s=""��p=".*"�����г�ʼ����ֵ
		dp[0][0] = true;

		for (int j = 1; j <= pLen; j++)
			dp[0][j] = (j > 1 && '*' == pattern[j - 1] && dp[0][j - 2]);

		for (int i = 1; i <= sLen; i++)
			for (int j = 1; j <= pLen; j++)
				if (pattern[j - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || '.' == pattern[j - 1]);
				else//��Ϊ*������Ҫ����dp[][j-2]���Լ���ǰֵ�Ƿ�ƥ�䣬Ҫ�ж�dp[i-1][j]�Ƿ�ƥ��
					dp[i][j] = dp[i][j - 2] || (str[i - 1] == pattern[j - 2] || '.' == pattern[j - 2]) && dp[i - 1][j];

		return dp[sLen][pLen];
	}
};