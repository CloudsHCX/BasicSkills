/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�

ʾ��:

����: 3
���: 5
����:
���� n = 3, һ���� 5 �ֲ�ͬ�ṹ�Ķ���������:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
��������������ö�̬�滮����⣬����F(i,n)������iΪroot����n������BST����1<=i<=n��
	  G(n)������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֡�
	  ��G(n)=F(1,n)+F(2,n)+...+F(n,n)
	      ��F(i,n) = G��i-1��*G��n-i��
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        
		if(n == 0)
			return 0;

		vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 1;

		//��̬�滮��G(i) i��1->n;
		for(int i=2; i <= n; ++i)
		{
			int count = 0;
			//G(i)�ۼ���ֵ,��F(1,i)+...+F(i,i)
			for(int j=1;j <= i; ++j)
			{
				count += dp[j-1] * dp[i-j]; 
			}
			dp[i] = count;
		}
		return dp[n];
    }
};