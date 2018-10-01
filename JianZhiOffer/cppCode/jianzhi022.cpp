/*
022 ����min������ջ

��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min����
��ʱ�临�Ӷ�ӦΪO��1������
*/

/*
������ ����һ������ͨ��һ����Сֵջ��һ������ջ������ʵ�֡�
	   ��������ͨ����Сֵ����ջһ��vector��������ݣ����ַ����洢�ռ��С��
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {

		store.push_back(value);
		if(stMin.empty())
			stMin.push(0);
		else
		{
			if(value < store[stMin.top()])
				stMin.push(store.size() - 1);
		}
    }
    void pop() {
		//������Ԫ������Ϊ��Сֵջ�������������Сֵջ��������
		if((store.size() - 1) == stMin.top())
			stMin.pop();

		store.pop_back();
    }
    int top() {
		return *(store.end() - 1);
    }
    int min() {
		return store[stMin.top()];
    }

private:
	//�����Сֵջ����
	stack<int> stMin;
	//ԭʼջ
	vector<int> store;
};