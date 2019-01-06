/*
008 ��ת�������С����

��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//O(logn)
	int minNumberInRotateArray(vector<int> rotateArray) {

		int len = rotateArray.size();

		//�����鷵��0
		if (len == 0)
			return 0;

		int left = 0, right = len - 1, mid;

		while (rotateArray[left] >= rotateArray[right])
		{
			//  ���ǰһ��Ԫ�����һ��Ԫ�ز�һλ,˵���ҵ��������С��Ԫ��
			if (right - left == 1)
			{
				mid = right;
				break;
			}

			mid = (right + left) / 2;

			//  ������м�Ԫ��λ��ǰ��ĵ��������飬��ô��Ӧ�ô��ڻ��ߵ��ڵ�һ��ָ��ָ���Ԫ��
			if (rotateArray[mid] >= rotateArray[left])
			{
				left = mid;         
			}
			// ����м�Ԫ��λ�ں���ĵ��������飬��ô��Ӧ��С�ڻ��ߵ��ڵڶ���ָ��ָ ���Ԫ��
			else if (rotateArray[mid] <= rotateArray[right])
			{
				right = mid;        
			}
		}
		return rotateArray[mid];
	}


	/*
	//O(n)ʱ�临�Ӷ�
    int minNumberInRotateArray(vector<int> rotateArray) {
     
		int len = rotateArray.size();

		//�����鷵��0
		if (len == 0)
			return 0;

		int flag = rotateArray[0];

		for (int i = 1; i < len; i++)
		{
			if (rotateArray[i] < flag)
				return rotateArray[i];
		}

		return flag;
    }
	*/
};