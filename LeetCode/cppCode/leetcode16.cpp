/*
16. 3Sum Closest
*/

/*
��15�����ƣ��ؼ����ж�diff��������ӽ���Ԫ��
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//����������
		sort(nums.begin(), nums.end());

		//����index
		int left, right;

		if (nums.size() < 3)
			return 0;
		//diff�洢�����ӽ�Ԫ�أ�lastDiff���洢֮ǰ������ӽ�Ԫ��
		int diff = nums[0] + nums[1] + nums[nums.size() - 1] - target;
		int lastDiff = diff;

		for (int i = 0; i < (nums.size() - 2); i++)
		{
			left = i + 1;
			right = nums.size() - 1;
			//�ƶ�����index
			while (left < right)
			{
				diff = nums[i] + nums[left] + nums[right] - target;
				//������С��diff������lastDiff
				if (abs(diff) < abs(lastDiff))
					lastDiff = diff;

				//����������֮��-target�����ж�
				if (diff == 0)
					break;
				else if (diff > 0)
					right--;
				else
					left++;
			}

		}
		return lastDiff + target;
	}
};