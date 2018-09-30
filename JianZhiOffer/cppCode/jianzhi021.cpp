/*
021 ˳ʱ���ӡ����
��Ŀ����

����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*
������ͨ��һ��dir���������������������ϵ��ƶ���ӡ��ͨ��status[][]��ά����
	  �����Ʒ���״̬��0δ���ʣ�1�Է��ʡ�ѭ����ӡ���鼴�ɡ�
*/
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {
		{0,1},
		{1,0},
		{0,-1},
		{-1,0}
};
class Solution {

public:
   	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		if(matrix.empty())
			return res;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int> > status(row, vector<int>(col));
	
		//cur����˳ʱ���ƶ�
		int cur = 0, x=0, y=0, len = row * col;
		for(int i = 0; i < len; )
		{
			int tmpX = x + dir[cur][0];
			int tmpY = y + dir[cur][1];
			if(tmpY < col && tmpY >= 0 && tmpX < row && tmpX >= 0)
			{
				if(status[tmpX][tmpY] == 0)
				{
					status[x][y] = 1;
					res.push_back(matrix[x][y]);
					x = x + dir[cur][0];
					y = y + dir[cur][1];
					i++;
				}
				else
				{
					status[x][y] = 1;
					res.push_back(matrix[x][y]);
					cur = (cur + 1) % 4;
					x = x + dir[cur][0];
					y = y + dir[cur][1];
					i++;
				}
			}
			else
			{
				status[x][y] = 1;
				res.push_back(matrix[x][y]);
				cur =(cur + 1) % 4;
				x = x + dir[cur][0];
				y = y + dir[cur][1];
				i++;
			}
		}
		return res;
    }
};