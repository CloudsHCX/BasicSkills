/*
031 ��С��K����

��Ŀ����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4
*/

/*
����������һ�����ø������򣬴�С�����������ǰK����
	  ��������ά��topN�Ĵ���ѣ������Сֵ��
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
		vector<int> res;

		if(input.size() == 0 || input.size() < k)
            return res;

		sort(input.begin(), input.end());

		for(int i=0; i < k; i++)
		{
			res.push_back(input[i]);
		}

		return res;
		//
		//vector<int> m_res;

		//if(input.size() == 0 || input.size() < k)
  //          return m_res;

		////ʹ�ô���ѵķ�ʽ�����������Сֵ��
		//vector<int> maxHeap(k);
		//int index = 0,i = 0;
		//int len = input.size();

		//for(; index < k; index++, i++)
		//{
		//	maxHeap[index] = input[i];
		//}

		//sort(maxHeap.begin(), maxHeap.end(), cmp);

		//for(;i < len; i++)
		//{
		//	if(input[i] < maxHeap[0])
		//	{
		//		//���´����
		//		maxHeap[0] = input[i];
		//		sort(maxHeap.begin(), maxHeap.end(), cmp);
		//	}
		//}

		//vector<int> res(maxHeap.begin(), maxHeap.end());
		//return res;
		
    }

private:
	static bool cmp(int a, int b)
	{
		return (a < b ? false : true);
	}
};