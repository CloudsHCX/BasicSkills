/*
043 ��ΪS��������������

��Ŀ����
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,
���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!

�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
     
		vector<vector<int> > res;
		vector<int> curRes;

		if(sum < 3)
		{
			return res;
		}

		int begin = 1, end = 2, mid = (1 + sum) / 2;
		int count = 1+2;
		while(begin < mid && end < sum)
		{
			if(count == sum)//�ոպã�����ֵ
			{
				for(int i = begin; i <= end; i++)
				{
					curRes.push_back(i);
				}
				res.push_back(curRes);
				curRes.clear();
				end++;
				count += end;
			}
			else if(count > sum)//begin����
			{
				count -= begin;
				begin++;
			}
			else //end ����
			{
				end++;
				count += end; 
			}
		}
		return res;
    }
};