/*
215. Kth Largest Element in an Array
*/
/*
����С���Ѵ���Ҳ����ʹ��priority_queueʵ��
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//�쳣�����k�������鳤��
		if (k > nums.size())
		{
			return -1;
		}
		
		arr = new int[k + 1];
		count = 0;
		capacity = k;
		
		for (int i = 0; i < nums.size(); i++)
		{
			insert_data(nums[i]);
		}
		return arr[1];
	}

	void insert_data(int data)
	{
		//��δ��ʱ����������
		if (count < capacity)
		{
			++count;
			arr[count] = data;
			int i = count;
			//���϶ѻ�
			while (i/2 > 0 && arr[i] < arr[i / 2])
			{
				swap(arr[i], arr[i / 2]);
				i = i / 2;
			}
			return;
		}

		//����ʱ����Ѷ�Ԫ����ȣ������ڶѶ�Ԫ�أ����滻�Ѷ������¶ѻ�
		if (data > arr[1])
		{
			swap(data, arr[1]);
			heapify(1);
		}
		
	}

	//���¶ѻ�
	void heapify(int i)
	{
		int min_pos = i;
		while (true)
		{
			min_pos = i;
			if (2 * i <= capacity && arr[i] > arr[2 * i])
			{
				min_pos = 2 * i;
			}
			if ((2 * i + 1) <= capacity && arr[min_pos] > arr[2 * i + 1])
			{
				min_pos = 2 * i + 1;
			}
			if (min_pos == i)
			{
				break;
			}
			swap(arr[min_pos], arr[i]);
			i = min_pos;
		}
	}

private:
	int* arr;
	int count;
	int capacity;
};