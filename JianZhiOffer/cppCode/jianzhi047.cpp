/*
047 �˿���˳��

��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,
2��С��(һ����ԭ����54��^_^)...��������г����5����,�����Լ�������,
�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,
��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,����A����1,
JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����
LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ� 
����������˳�Ӿ����true����������false��Ϊ�˷������,�������Ϊ��С����0��

*/


/*
����: 1.��vector�����ظ����֣���Ϊ��˳�ӣ�����false��������hash����š�
	  2.��1�Ļ����ϣ���vector�����ֵ����Сֵ��<=4������˳�ӣ���֮Ϊ��˳�ӡ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    bool IsContinuous( vector<int> numbers ) {

		if( numbers.empty())
			return false;

		int len = numbers.size();
		int min_val = 15, max_val = 0;
		vector<int> hash(15,0);

		for(int i = 0; i < len; i++)
		{
			if(numbers[i] == 0)
				continue;
			//����0֮���ظ������˳��
			if(hash[ numbers[i] ] == 0)
				hash[ numbers[i] ] = 1;
			else return false;

			min_val = min(min_val, numbers[i]);
			max_val = max(max_val, numbers[i]);
		}

		//��vector�����ֵ����Сֵ��<=4������˳�ӣ���֮Ϊ��˳��
		if((max_val - min_val) <= 4)
			return true;
		else
			return false;
};