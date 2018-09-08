/*
*Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

/*
��̬�滮�ĵ����⣺����С����������ͨ�������ӽṹn-1���Ƶ�n�����

״̬ת�Ʒ��̣�
    dp��ά���飬��������word1 ��0...i���ַ��仯��word2 ��0...j���ַ�����С����
    һ�������ֲ��ԣ�ɾ�����ġ�
	1���� word1[i] == word2[j] �����ý��в���dp[i+1][j+1] = dp[i][j]
	2) �� word1[i] != word2[j] , �����ͨ�����ֲ��ԣ�ɾ�����ĵ�ǰ��ĸ��
	ʹword1[0...i]->word2[0...j]�ַ��������ֲ��Զ�Ӧ���£�
		ɾ��dp[i+1][j+1] = dp[i][j+1] + 1
		��dp[i+1][j+1] = dp[i+1][j] + 1
		�ģ�dp[i+1][j+1] = dp[i][j] +1

		ȡ����С���µ�dp[i+1][j+1]����״̬ת�Ʒ��̣���dp[i+1][j+1] = min(dp[i+1][j],min(dp[i][j],dp[i][j+1]))+1;

��:
  word1="horse" word2="ros"
  dp[][]   ""r o s
        "" 0 1 2 3
		h  1 1 2 3 
		o  2 2 1 2
		r  3 2 2 2
		s  4 3 3 2
		e  5 4 4 3

ע�����ڱ���dp����ֻ��Ҫ��¼��ǰ���Լ���һ�У�i��i-1�У�����������������Ҫ������ͨ��3�еĹ����������洢��
	�������Ϳռ临�Ӷȡ�
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
		int len1 = word1.size();
		int len2 = word2.size();

		//��Ϊ�գ������⴦��
		if(!len1) return len2; 
		if(!len2) return len1;

		//����dp��ά���飬��������word1 ��0...i���ַ��仯��word2 ��0...j���ַ�����С����
		vector<vector<int>> dp(len1+1,vector<int>(len2+1));
		for(int i=0; i <= len2; ++i)
			dp[0][i] = i;
		for(int i=0; i <= len1; ++i)
			dp[i][0] = i;
		
		//����״̬ת�Ʒ��̣��������
		for(int i=0; i<len1; ++i)
		{
			for(int j=0; j<len2; ++j)
			{
				if( word1[i] == word2[j])
					dp[i+1][j+1] = dp[i][j];
				else
				{
					dp[i+1][j+1] = min(dp[i+1][j],min(dp[i][j],dp[i][j+1]))+1;
				}
			}
		}
		return dp[len1][len2];
    }
};