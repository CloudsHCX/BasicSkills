/*
030 �����г��ִ�������һ�������

��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��
*/

/*
����������map�����ÿ�����ֵĳ���Ƶ�ʣ�����map�����ش������鳤��һ���ֵ���ɡ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		
		unordered_map<int, int> fMap;
		int len = numbers.size();

		for(int i = 0; i < len; i++)
		{
			fMap[ numbers[i] ]++;
		}

		int half = len / 2;
		for(unordered_map<int, int>::iterator it = fMap.begin(); it != fMap.end(); it++)
		{
			if(it->second > half)
				return it->first;
		}
		return 0;
    }
};