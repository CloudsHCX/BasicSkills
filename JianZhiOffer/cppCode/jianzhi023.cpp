/*
023 ջ��ѹ�롢��������
��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ
���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/

/*
������ͨ��һ��ջ��ģ��ջ��ѹ�뵯����
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		
		if(pushV.empty())
			return true;

		int len = popV.size();
		stack<int> st;
		st.push(pushV[0]);
		//i����pushV��j����popV
		for(int i=1,j=0; j < len; )
		{
			//��st��ջ���ͳ�ջԪ�ز�ͬ��������ջ/����len����ʧ��
			if(st.top() != popV[j])
			{
				if( i< len)
				{
					st.push(pushV[i]);
					i++;
					continue;
				}
				else
					return false;
			}
			//����ͬ�����ջ/ջ�շ���ʧ��	
			else
			{
				if(st.empty())
					return false;
				else
				{
					cout<< st.top() << " ";
					st.pop();
					j++;
				}
			}
		}
		return true;
    }

};