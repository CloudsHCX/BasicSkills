/*
045 ����ת�ַ���

��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
���������ַ���ģ�����ָ���������������һ���������ַ�����S��
�������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,
Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/

/*
����������ֱ����insert�����õ���������string
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length() == 0 )
			return "";
		int ROL = n % str.size();
		string res;
		res.insert(res.begin(), str.begin()+ROL, str.end());
		res.insert(res.end(), str.begin(), str.begin()+ROL);
		return res;
    }
};