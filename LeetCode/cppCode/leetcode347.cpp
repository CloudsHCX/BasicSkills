/*
347. Top K Frequent Elements
*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;
class Solution {
public:
	struct cmp
	{
		bool operator()(const pair<int, int> &a, const pair<int, int> &b)
		{
			return a.first > b.first;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> hash;

		//ͳ��ÿ�������ĸ���
		for (int i = 0; i < nums.size(); i++)
		{
			hash[nums[i]]++;
		}

		//��ȡ����K��������С����
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;

		for (auto it = hash.begin(); it != hash.end(); ++it)
		{
			if (min_heap.size() == k)
			{
				if (it->second > min_heap.top().first)
				{
					min_heap.pop();
					min_heap.push(make_pair(it->second, it->first));
				}
			}
			else
			{
				min_heap.push(make_pair(it->second, it->first));
			}
		}

		//��min_heap���Ƶ�vector����Ƶ�����->���
		vector<int> ret_vec(k);
		int size = min_heap.size();
		for (int i = 0; i < size; i++)
		{
			ret_vec[size - i - 1] = min_heap.top().second;
			min_heap.pop();
		}
		return ret_vec;

	}
};