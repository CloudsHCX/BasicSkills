/*
034 �������ų���С����

��Ŀ����
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		string sTmp,sMin;
		sort(numbers.begin(), numbers.end());

		for(int i = 0; i < len; i++)
			sTmp.push_back(numbers[i]);
		sMin = sTmp;
		next_permutation(numbers.begin(), numbers.end());
		do
		{
			sTmp.clear();
			for(int i = 0; i < len; i++)
				sTmp.push_back(numbers[i]);
			if(sTmp < sMin)
				sMin = sTmp;
		}
		while(next_permutation(numbers.begin(), numbers.end()));
		return sMin;

    }

private:
	int lenInt(int n)
	{
		int len = 0;
		while(n)
		{
			len++;
			n /= 10;
		}
		return n;
	}
};