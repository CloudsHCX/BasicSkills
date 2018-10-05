/*
026 �������к�Ϊĳһֵ��·��

��Ŀ����
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
*/

/*
�����������õݹ�ķ�����ʵ�֣�ÿ�δ���ôε�·���뵱ǰֵ�������ʵ��ļ�֦�����Ż���
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
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if(root == nullptr)
        {
            return res;
        }
		vector<int> path;
		recurFindPath(root, expectNumber, 0, path);
		return res;
    }

	bool recurFindPath(TreeNode* root,int expectNumber, int curVal, vector<int> path)
	{
		curVal += root->val;
		path.push_back(root->val);

		if((curVal == expectNumber) 
			&& ((root->left == nullptr) && (root->right == nullptr)) )
		{
			res.push_back(path);
			return true;
		}
		else if(curVal > expectNumber)
		{
			return false;
		}
		else
		{
			if(root->left)
				recurFindPath(root->left, expectNumber, curVal, path);
			if(root->right)
				recurFindPath(root->right, expectNumber, curVal, path);
			return true;
		}

	}
private:
	vector<vector<int> > res;
};