/*
049 ��1+2+3+...+n

��Ŀ����
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��
case�ȹؼ��ּ������ж���䣨A?B:C����
*/

/*
����&&�Ķ�·˼�룬��ʵ�ֵݹ���ٽ������ж�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
		int sum = n;
		(n > 0) && (sum += Sum_Solution(n - 1));
		return sum;
    }
};