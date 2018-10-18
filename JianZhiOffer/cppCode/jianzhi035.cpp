/*
035 ����

��Ŀ����
��ֻ����������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ�
��Ϊ������������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		//�쳣�������
		if(index <= 0)
			return 0;

		vector<int> arr(index);
		arr[0] = 1;

		int index2 = 0, index3 = 0, index5 = 0;
		int cur = 1;
		int minVal;
		//����һ����С�ĳ�����
		while(cur < index)
		{
			minVal = minOfThree(arr[index2] * 2, arr[index3] * 3, arr[index5] * 5);
			if(minVal == arr[index2] * 2)
			{
				index2++;
			}
			if(minVal == arr[index3] * 3)
			{
				index3++;
			}
			if(minVal == arr[index5] * 5)
			{
				index5++;
			}
			arr[cur++] = minVal;
		}
		return arr[index - 1];
    }

private:
	int minOfThree(int a, int b, int c)
	{
		int tmp = (a < b ? a:b);
		return (tmp < c ? tmp : c);
	}
};