/*
044 ��ΪS����������
��Ŀ����
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�

�������:
��Ӧÿ�����԰����������������С���������
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> arr,int sum) {
        
		vector<int> res;
		int len = arr.size();
		if(len < 2)
			return res;

		int begin = 0, end = len - 1, curSum;
		int min = numeric_limits<int>::max();
		while(begin != end)
		{
			curSum = arr[begin] + arr[end];
			if(curSum == sum)
			{
				if(min > arr[begin] * arr[end])
				{
					min = arr[begin] * arr[end];
					res.clear();
					res.push_back(arr[begin]);
					res.push_back(arr[end]);
				}
				begin++;
			}
			else if(curSum > sum)
			{
				end--;
			}
			else
			{
				begin++;
			}
		}
		return res;
    }
};