/*
013 ��������1�ĸ���

��Ŀ����
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
//����һ��
     int  NumberOf1(int n) {
         
		 int count = 0;
		 unsigned int flag = 1;
		 while(flag != 0)
		 {
			if( (n & flag) != 0)
				count++;
			flag <<= 1;
		 }
		 return count;
     }
//��������һ������������������-1ȡ&��ֻ��Ӱ�����ұߵġ�1��λ��������������ɡ�
//       ��1110  1110 & 1101 = 1100 ֻӰ���ˡ�1110�����ұߵ�1,��ˣ��Դ˽���ͳ�Ƽ��ɡ�
     int  NumberOf2(int n) {
         
		 int count = 0;
		 while(n)
		 {
			count++;
			n = n & (n-1);
		 }
		 return count;
     }
};