/*
025 �����������ĺ����������

��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*/

/*
������sequence�������ұߵ�����Ϊ���ڵ㣬
		1.����ͨ���ý�㣬��ǰ��������һ����rootС�Ľ��Ϊ��������root��㣬������ΪnewIndex
		  ֻ��Ҫ�ж� left��newIndex��С��root��˵���˴��������������
		2.����ͨ��left��㿪ʼ�����ұ�������һ����root��Ľ������-1��Ϊ��������root��㡣
		  ������ΪnewIndexֻ��Ҫ�жϣ�newIndex+1��right������root��˵���˴��������������
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {

		if(sequence.empty())
			return false;
		return checkSequenceOfBST(sequence, 0, sequence.size() - 1);

    }

	bool checkSequenceOfBST(vector<int> &sequence, int left, int right)
	{
		int root = sequence[right];
		int newIndex;
		if(left >= right)
			return true;

		for(int i = right - 1; i>= left; i--)
		{
			if(root > sequence[i])
			{
				newIndex = i;
				break;
			}
		}

		//������Ӧ����С��root
		for(int i = left; i < newIndex; i++)
		{
			if(sequence[i] > root)
				return false;
		}
		//������Ӧ��������root,�˶δ������ʡ�ԡ�
		/*for(int i = newIndex + 1; i < right; i++)
		{
			if(sequence[i] < root)
				return false;
		}*/

		return checkSequenceOfBST(sequence, left, newIndex) && 
			checkSequenceOfBST(sequence,newIndex + 1, right - 1);
	}
};