/*
052  �������ظ�������

��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�
����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int, int> hash;

		for (int i = 0; i < length; i++)
		{
			if (hash.find(numbers[i]) == hash.end())
				hash[numbers[i]] = 1;
			else
			{
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};