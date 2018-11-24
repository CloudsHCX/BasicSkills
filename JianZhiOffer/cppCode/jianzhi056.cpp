/*
056 �ַ����е�һ�����ظ����ַ�
��Ŀ����
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ��
��һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
*/

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
	unordered_map<char, int> store;
	vector<char> once_vec;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{		
		if ((++store[ch]) == 1)
		{
			once_vec.push_back(ch);
		}
		else
		{
			for (auto it = once_vec.begin(); it != once_vec.end(); ++it)
			{
				if (*it == ch)
				{
					once_vec.erase(it);
					break;
				}
			}
		}

	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		if (once_vec.empty())
			return '#';
		else
		{
			return once_vec[0];
		}
	}


};