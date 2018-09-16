/*
007 ������ջʵ�ֶ���

������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/

/*
��������һ��ջ������ֵ�����ڴ���������ݣ���ģ�³��ӵ�ʱ�����õڶ�������һ��ջ���ã�
	  ��ʱ��ջ��Ԫ�ؾ��ǳ��ӵ�ֵ������֮��ָ�ջһ��ջ��״̬�����Ը���ջ���������Ż�
	  �㷨�����磺�����Ϊ���Ķӣ������Գ���Ϊ���Ķԡ�

˼·2��ʼ��ά��s1��Ϊ����ջ����s2��Ϊ���ջ

1.���ʱ����Ԫ��ѹ��s1��

2.����ʱ���ж�s2�Ƿ�Ϊ�գ��粻Ϊ�գ���ֱ�ӵ�����Ԫ�أ�
��Ϊ�գ���s1��Ԫ����������롱s2�������һ��Ԫ�ص��������ӡ�
���˼·�������˷���������ջ��������Ҫʱ�š�����һ�Ρ�
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
		stack1.push(node);        
    }

    int pop() {
		if(stack1.empty())
			return -1;
		//��һ��ջ�����洢���ݣ�ת�浽�ڶ���ջ�У�ջ������Ҫ��ջ��ֵ
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int ret = stack2.top();
		stack2.pop();
		//�ָ�����һ��ջ
		while(!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};