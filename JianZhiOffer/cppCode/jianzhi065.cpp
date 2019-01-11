/*
065 �������е���λ��

��Ŀ����
��εõ�һ���������е���λ����������������ж�����������ֵ��
��ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

private:
	vector<int> big_heap; //����ѣ��������ִ�
	vector<int> small_heap; //С���ѣ� ż�����ִ�

public:
	void Insert(int num)
	{
		//�����ڵ�nΪż��������뵽����ѣ���С�ڶѶ�Ԫ�أ��򽫶Ѷ�Ԫ�ص�����С������
		//��ʱ��λ��Ϊ����ѵĶѶ�Ԫ��
		if ( ((big_heap.size() + small_heap.size()) & 1) == 0)
		{
			if ( big_heap.size() > 0 && num < big_heap[0])
			{
				big_heap.push_back(num);
				push_heap(big_heap.begin(), big_heap.end(), less<int>());
				num = big_heap[0];
				pop_heap(big_heap.begin(), big_heap.end(), less<int>());
				big_heap.pop_back();
			}
			//���Ѷ�Ԫ�ص�����С������
			small_heap.push_back(num);
			push_heap(small_heap.begin(), small_heap.end(), greater<int>());
		}
		//�����ڵ�nΪ����������뵽С���ѣ������ڶѶ�Ԫ�أ��򽫶Ѷ�Ԫ�ص������������
		//��ʱ��λ��ΪС���ѵĶѶ�Ԫ�� �����ѵĶѶ�Ԫ�ص�ƽ��ֵ
		else
		{
			if ( small_heap.size() > 0 && num > small_heap[0])
			{
				small_heap.push_back(num);
				push_heap(small_heap.begin(), small_heap.end(), greater<int>());
				num = small_heap[0];
				pop_heap(small_heap.begin(), small_heap.end(), greater<int>());
				small_heap.pop_back();
			}
			//���Ѷ�Ԫ�ش浽�������
			big_heap.push_back(num);
			push_heap(big_heap.begin(), big_heap.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = big_heap.size() + small_heap.size();
		//����ż��
		if (size == 0)
		{
			return -1;
		}
		else if ((size & 1) == 0)
		{
			return (big_heap[0] + small_heap[0]) / 2.0;
		}
		else
		{
			return small_heap[0];
		}
	}

};