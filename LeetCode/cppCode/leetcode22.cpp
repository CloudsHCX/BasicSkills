/*
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
/*
����˼·�����ݷ�
���ƴ����string cur�� �������� left < n���������� right < left�����л���
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string cur = "";
		backtrace(res, cur, 0, 0, n);
		return res;
	}
	/*
	In params:
				res:����������������������
				cur:��ǰ����ʱ����������
				left:��ǰ�����Ÿ���
				right:��ǰ�����Ÿ���
				max:�ܵ����ŶԸ���
	*/
	void backtrace(vector<string>& res, string cur, int left, int right, int max)
	{
		//�ҵ�������������������
		if (cur.size() == (max << 1))
		{
			res.push_back(cur);
			return;
		}
		//�����Ÿ���С�������Ÿ��������������
		if (left < max)
		{
			backtrace(res, cur+"(", left + 1, right, max);
		}
		//�����Ÿ���С�������Ÿ���ʱ�����������
		if (right < left)
		{
			backtrace(res, cur+")", left, right + 1, max);
		}
	}
};