/*
042 ������ֻ����һ�ε�����

��Ŀ����
һ�����������������������֮�⣬���������ֶ�������ż���Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		unordered_map<int, int> hash;
		unordered_map<int, int>::iterator it;
		int len = data.size();
		for(int i = 0; i < len; i++)
		{
			hash[data[i]]++;
		}
		for(it = hash.begin();it != hash.end(); it++)
		{
			if(it->second == 1)
			{
				if(*num1 == 0)
				{
					*num1 = it->first;
					continue;
				}
				if(*num2 == 0)
				{
					*num2 = it->first;
					continue;
				}
			}
		}
    }
};