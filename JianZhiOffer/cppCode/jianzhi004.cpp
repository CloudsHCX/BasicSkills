/*
004 �滻�ո�
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

/*
������ʹ��һ��buffer_string �������ַ������������ո������%20����֮����ԭ����
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(!str) return;
		string s;
		for(int i = 0; i < length; i++)
		{
			if(str[i] == ' ')
			{
				s.insert(s.end(), '%');
				s.insert(s.end(), '2');
				s.insert(s.end(), '0');

			}
			else
				s.insert(s.end(), str[i]);

		}
		strcpy(str, s.data());
		cout<< s;
	}
};