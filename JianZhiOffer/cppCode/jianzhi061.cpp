/*
061 ��֮����˳���ӡ������

��Ŀ����
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
����һ��ջ�������ΰ����ҽ����룬ż���ΰ����������
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {

		vector<vector<int> > res;
		stack<TreeNode* > stOdd,stEven;

		if (!pRoot)
		{
			return res;
		}

		stOdd.push(pRoot);
		TreeNode* tmpNode;
		vector<int> line;

		while (!stOdd.empty() || !stEven.empty())//�������λ�ż����ջ��Ϊ��
		{
			while (!stOdd.empty()) //����ջ�����ҽ�����ż��ջ
			{
				tmpNode = stOdd.top();
				line.push_back(tmpNode->val);
				stOdd.pop();
				if (tmpNode->left)
				{
					stEven.push(tmpNode->left);
				}
				if (tmpNode->right)
				{
					stEven.push(tmpNode->right);
				}
			}

			if (!line.empty())
			{
				res.push_back(line);
				line.clear();
			}

			while (!stEven.empty()) //ż��ջ�����������ż��ջ
			{
				tmpNode = stEven.top();
				line.push_back(tmpNode->val);
				stEven.pop();
				if (tmpNode->right)
				{
					stOdd.push(tmpNode->right);
				}
				if (tmpNode->left)
				{
					stOdd.push(tmpNode->left);
				}
			}

			if (!line.empty())
			{
				res.push_back(line);
				line.clear();
			}
		}
		return res;
	}
};