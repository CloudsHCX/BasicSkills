/*
33. Search in Rotated Sorted Array
*/
/*
���ֲ��ҵı��壬����[low,mid],[mid,high]����Ȼ��һ���������ö��ֲ��Ҷ�
nums[mid]�Ƚϣ�ѡ������ʱ��Ҫ����������������֣���low��high�������д���
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		int mid = 0;

		while (low <= high)
		{
			mid = low + ((high - low) >> 1);
			//��target == nums[mid]���򷵻��±�
			if (target == nums[mid])
			{
				return mid;
			}
			//target < nums[mid]ʱ�������ֲ�ͬ����Ĵ���
			else if (target < nums[mid])
			{
				//��������Ϊ[low,mid]
				if (nums[low] <= nums[mid])
				{
					if (target >= nums[low])
					{
						high = mid - 1;
					}
					else
					{
						low = mid + 1;
					}
				}
				//��������Ϊ[mid,high]
				else
				{
					high = mid - 1;
				}
			}
			//target > nums[mid]ʱ�������ֲ�ͬ����Ĵ���
			else
			{
				//��������Ϊ[low,mid]
				if (nums[low] <= nums[mid])
				{
					low = mid + 1;
				}
				//��������Ϊ[mid,high]
				else
				{
					if (target >= nums[low])
					{
						high = mid - 1;
					}
					else
					{
						low = mid + 1;
					}
				}
			}
		}

		return -1;
	}
};