/*
046 ��ת����˳����
��Ŀ����
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У�
���ܰ�����ô��
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
             
		vector<string> strs(split(str, ' '));
		int len = strs.size();
		string res;
		for(int i = len - 1; i >= 0; i--)
		{
			res += strs[i];
			if(i != 0)
				res += " ";
		}
		return res;
    }

	const vector<string> split(string& str, char c)//split �����������и��ַ���
	{
		string buff;
		vector<string> res;
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			if(str[i] == c && buff != "")
			{
				res.push_back(buff);
				buff.clear();
			}
			else 
			{
				buff += str[i];
			}
		}
        res.push_back(buff);
		return res;
    }
};