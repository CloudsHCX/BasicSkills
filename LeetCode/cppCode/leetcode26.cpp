/*
26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
/*
����˼·��˫�±����
�������Ϊ�������֣�һ������Ϊ���������飬��һ������Ϊ�Ѵ������飬���ϵĽ���������������Ѵ������鼴��
*/

#include <vector>

using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1)
		{
			return nums.size();
		}
		//�����������±꣬�Ѵ��������±�
		int pendingIndex = 1, processedIndex = 0;
		while (pendingIndex < nums.size())
		{
			//nums[pendingIndex] �� nums[processedIndex]��ͬ����pendingIndex+1����ʾ�������Ѽ���
			if (nums[pendingIndex] == nums[processedIndex])
			{
				pendingIndex++;
			}
			//�������ּ����Ѵ�������ĩβ
			else
			{
				processedIndex++;
				nums[processedIndex] = nums[pendingIndex];
				pendingIndex++;
			}
		}
		return processedIndex + 1;
	}
};