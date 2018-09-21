/*
015 ��������˳��ʹ����λ��ż��ǰ��

��Ŀ����
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
*/

/*
����������������������֤�ȶ��ԣ����������ż�����飬����֮���ٻָ���ԭ�����С�
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
		if(array.empty()) return;

		vector<int> oddArr,evenArr;
		int len = array.size();
		for(int i = 0; i < len; i++)
		{
			if(array[i] & 1 == 1)
				oddArr.push_back(array[i]);
			else
				evenArr.push_back(array[i]);
		}
		int index = 0, lenOdd = oddArr.size(), lenEven = evenArr.size();
		for(int i = 0; index < len && i < lenOdd; i++,index++)
			array[index] = oddArr[i];
		for(int i = 0; index < len && i < lenEven; i++,index++)
			array[index] = evenArr[i];
    }
};