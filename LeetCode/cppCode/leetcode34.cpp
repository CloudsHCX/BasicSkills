/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
/*
���ö��ַ��ҵ�����a[i] == target���±�i�������ݸ��±��������ұ���ֱ��������a[left] != target��a[right] != target
�õ��±�ֵ
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res = { -1,-1 };
		//���в��֣�����Ϊ�գ�target>���ֵ target < ��Сֵ��ֱ�ӷ���[-1,-1]
		if (nums.empty() || target > nums[nums.size()-1] || target < nums[0])
		{
			return res;
		}
		
		int len = nums.size();
		int low = 0, high = len - 1;
		int mid = 0;
		//���ֲ��Ҳ��ҵ�targetֵ���±꣬�ٸ��ݸ��±��������ұ����ҵ������±�
		while (low <= high)
		{
			mid = low + ((high - low) >> 1);
			if (nums[mid] == target)
			{
				int left = mid, right = mid;
				while (left >= 1 && (nums[left - 1] == target))
				{
					left--;
				}
				while (right <= (len -2) && (nums[right + 1] == target))
				{
					right++;
				}
				res[0] = left;
				res[1] = right;
				return res;
			}
			else if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		return res;
	}
};