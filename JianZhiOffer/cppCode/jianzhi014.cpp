/*
014 ��ֵ�������η�

��Ŀ����
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/

/*
������1��exponent < 0��ȡ������2��exponent == 0������1��3��exponent > 0������ȡֵ
	  ˼·һ������ͨ�� n��Ŀǰָ������ʼ=1��ÿ��*2,res *= res,ֱ��>exponent����ʱ�ٶ�ʣ��
			  ��exponent-n����ֵ������1~exponent-n����res *= base��
	  ˼·��������ͨ��ָ���Ķ�������������ֵ����base = 10, exponent = 5��101�� ���λ1������
	          Ȩ��10^4����res = res * Ȩ�ء�Ϊ0��λ���óˡ�
				
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
		//ָ��<0����ȡ����
		if(exponent < 0) return 1/Power(base, -exponent);
		if(exponent == 0) return 1;
		if(exponent == 1) return base;

		double res = 1.0, tmp = base;
		
		while( exponent != 0)
		{
			if( (exponent & 1) == 1)
				res *= tmp;
			tmp *= tmp;
			exponent >>= 1;
		}
		return res;
    }
};
