/*
027 ��������ĸ���

��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/
/*
����������*random����ͳ��������ʱ�䷢�Ӷ�ΪO(n2)����������map<�ɽ���ַ���½���ַ>
		��ά��ӳ����Կռ任ʱ�䡣
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
			return nullptr;

		RandomListNode* curNode = pHead;
		RandomListNode* newListHead = nullptr,*curNewNode = nullptr,*preNewNode = nullptr;
		//����map���ռ任ʱ�䡣
		unordered_map<RandomListNode*, RandomListNode*> nodeMap;

		//��һ�α�����ֻ��������next��������random
		while(curNode)
		{
			curNewNode = new RandomListNode(curNode->label);
			nodeMap[curNode] = curNewNode;
			curNode = curNode->next;
			if(!preNewNode)
			{
				newListHead = curNewNode;
			}
			else
			{
				preNewNode->next = curNewNode;
			}
			preNewNode = curNewNode;
		}

		curNewNode = newListHead;
		curNode = pHead;

		//����RandomListNode*
		while(curNode && curNewNode)
		{
			curNewNode->random = nodeMap[curNode->random];
			curNode = curNode->next;
			curNewNode = curNewNode->next;
		}
		return newListHead;
    }
};