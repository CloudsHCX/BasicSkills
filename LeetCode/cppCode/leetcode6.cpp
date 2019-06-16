/*
LeetCode6 ZigZag
��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�

L   C   I   R
E T O E S I I G
E   D   H   N
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
ʾ�� 1:

����: s = "LEETCODEISHIRING", numRows = 3
	��� : "LCIRETOESIIGEDHN"
	ʾ�� 2 :

	���� : s = "LEETCODEISHIRING", numRows = 4
	��� : "LDREOEIIECIHNTSG"
	���� :

	L     D     R
	E   O E   I I
	E C   I H   N
	T     S     G
*/
/*
���ǰ����ӡʱ������ַ���ÿһ���Ӧԭ�ַ���������ƫ�ƣ���ͬһ�㣬��������ƫ�Ʒ�ʽ
2 * (numRows - nowRows - 1),2 * (numRows - 1) - 2 * (numRows - nowRows - 1)
�����������в������������
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {

		int step[2], len = s.size();
		string res;
		//�����ֱ�ӷ���
		if (numRows == 1)
			return s;
		int maxStep = 2 * (numRows - 1);
		for (int nowRows = 0; nowRows < numRows; nowRows++)
		{
			int pos = nowRows;
			//����ÿ��Ĳ���
			step[0] = 2 * (numRows - nowRows - 1);
			step[1] = maxStep - step[0];
			int control = 0, tmpPos;//�������ֲ������л�����ʱλ�ô洢
			while (true)
			{
				res += s[pos];
				//����Ծ�������п���
				while (true)
				{
					tmpPos = pos;
					pos += step[control % 2];
					control++;
					if (pos != tmpPos)
						break;
				}
				if (pos >= len)
					break;
			}
		}
		return res;
	}
};