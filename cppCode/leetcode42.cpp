/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£�
���Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ���� ��л Marcos ���״�ͼ��

����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6
*/

/*
����:�������ͨ����̬�滮�������������ģʽ�е㲻ͬ��
	��һ��i��˵����ˮ��������-��ǰi�ĸߣ��������ұ����-��ǰi�ĸߡ�
	������ˮ�Ǹ�����͵ĳ���Ϊ׼��������min�������ߣ��ұ���ߣ�-height[i];

	�ǣ�dpf[i]Ϊi������߶ȣ�dpe[i]Ϊi�ұ����߶�
	����i������ˮ��=min(dpf[i-1], dpe[i+1])-height[i]��ҪΪ�����Ŵ�������ˮ��

����
height    0,1,0,2,1,0,1,3,2,1,2,1
dpf       0 1 1 2 2 2 2 3 3 3 3 3
dpe       3 3 3 3 3 3 3 3 2 2 2 1

i����ˮֵ 0 0 1 0 1 2 1 0 0 1 0 0 = 6
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

		if(height.size() == 0 || height.size() == 1)
			return 0;

		int len = height.size();
		vector<int> dpf(len),dpe(len);

		//i���󲿷����
		dpf[0] = height[0];
		for(int i=1; i<len; ++i)
		{
			dpf[i] = max(height[i], dpf[i-1]);  
		}

		//i���Ҳ������
		dpe[len-1] = height[len-1];
		for(int i=len-2; i>=0 ;--i)
		{
			dpe[i] = max(height[i], dpe[i+1]);
		}

		//�������ˮ
		int maxPool=0;
		for(int i = 1; i<len-1; ++i)
		{
			int minTmp = min(dpf[i-1], dpe[i+1]);
			if( minTmp > height[i])
				maxPool += minTmp - height[i];
		}

		return maxPool;
    }
};