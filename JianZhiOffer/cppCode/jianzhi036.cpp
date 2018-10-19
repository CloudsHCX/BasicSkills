/*
036 ��һ��ֻ����һ�ε��ַ�

��Ŀ����
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        
		unordered_map<char, int> store;
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			store[str[i]]++;
		}
		for(int i = 0; i < len; i++)
		{
			if(store[str[i]] == 1)
				return i;
		}
		return -1;

    }
};