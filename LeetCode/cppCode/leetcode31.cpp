/*
31. Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/

/*
��һ�������ص㣺i��������Ϊ�ݼ����У���ʱi+1������a[i+1] > a[i]���ٴ��ҵ��������ҵ�a[j]������a[j] > a[i]
ʹ�ý�����i��������Ϊ�ݼ����У���i+1��size-1��Ϊ�ݼ����У����з�ת����Ϊ��һ�����С�
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		int i = nums.size() - 2;
		while (i >= 0 && nums[i + 1] <= nums[i])
		{
			i--;
		}
		if (i >= 0)
		{
			int j = nums.size() - 1;
			while (j >= 0 && nums[j] <= nums[i])
			{
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};