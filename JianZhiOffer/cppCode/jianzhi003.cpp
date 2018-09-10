/*
003 ��ά�����еĲ���

��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ������
���ж��������Ƿ��и�������
*/

/*
���������Դ����½ǻ������Ͻǿ�ʼ����ʱÿ�ζ������ƶ�һ��
*/
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		
		if(array.empty())
			return false;

		int row = array.size();        
		int column = array[0].size();

		int i,j;
		for( i = row - 1, j = 0; (i >= 0) && (j < column);)
		{
			//Ŀ��ֵ�������½�ֵ������
			if(target > array[i][j])
				j++;
			else if(target == array[i][j])
				return true;
			else
				i--;

		}
		return false;
	
    }
};