/*
029 �ַ���������

��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,
���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/

/*
����������һ���������õݹ飬ÿһ�ζ�������ǰֵ�ͺ�һ��ֵ���γɵľ�����һ������
	  ����������������STL�ṩ��next_permutation()�������ȫ���С�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
		vector<string> res;
		if(str.empty())
			return res;

		sort(str.begin(), str.end());

		do
		{
			res.push_back(str);
		}
		while(next_permutation(str.begin(), str.end()));

		return res;
    }
};