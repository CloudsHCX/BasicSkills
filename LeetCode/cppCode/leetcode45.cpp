/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

ʾ��:

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
     ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
˵��:

���������ǿ��Ե�����������һ��λ�á�
*/

/*
����������BFS��˼�������
*/
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size()==1 || nums.size() == 0)
            return 0;
		
		int start,end;
		start=end=0;
		int step=0;
		while(end < nums.size()-1)
		{
			int tmpEnd = 0;
			for(int i=0;start+i<=end;++i)
			{
				tmpEnd = max(nums[i+start]+start+i, tmpEnd);
				
			}
			start = end +1;
			end = tmpEnd;
			++step;
		}
		return step;
    }
};