/*
066 �������ڵ����ֵ

��Ŀ����
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6����
{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}��
{2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		//�����������ֵ���� pair<ֵ,�±�>
		priority_queue<pair<int, int>> maxQue;//Ĭ�ϴ�ֵ��ǰ

		//�������
		if (num.empty() || size <=0 )
		{
			return res;
		}

		//��size-1���뵽���ȶ�����
		for (int i = 0; i < size - 1; i++)
		{
			maxQue.push(pair<int, int>(num[i], i));
		}

		int len = num.size();
		for (int i = size - 1; i < len; i++)
		{
			maxQue.push(pair<int, int>(num[i], i));
			pair<int, int> tmp = maxQue.top();

			//������ֵ�Ѿ����ڻ��������ڣ����µ���������ȶ���
			while (tmp.second < i - (size - 1))
			{
				maxQue.pop();
				tmp = maxQue.top();
			}
			res.push_back(tmp.first);
		}
		return res;
	}
};