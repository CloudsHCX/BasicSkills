/*
15. 3Sum
*/

/*
a+b+c = 0 <=> a+b=-c������ֻ��Ҫ��ԭ����������С���󣬶Բ�����0�Ĳ�����ѡΪc��
���Ž�c֮���������Ϊa+b=-c������ͨ��left��right�������жϡ�
ע�⣺��Ҫȥ���ظ�����
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//����������
		sort(nums.begin(), nums.end());

		//����index
		int left, right;
		vector<vector<int>> res;

		if (nums.size() < 3)
			return res;

		//��������0�Ĳ�����Ϊ�������͵��෴�� a + b = -c (cС��0)
		for (int i = 0; i < (nums.size() - 2) && nums[i] <= 0; i++)
		{
			left = i + 1;
			right = nums.size() - 1;
			//�ƶ�����index
			while (left < right)
			{
				//����������֮�ͽ����ж�
				if (-nums[i] == nums[left] + nums[right])
				{
					res.push_back(vector<int> {nums[i], nums[left], nums[right]});
					//ȥ�ظ�
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (right > i && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
				else if (-nums[i] < nums[left] + nums[right])
					right--;
				else
					left++;
			}
			//ȥ�ظ�
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
		return res;
	}
};