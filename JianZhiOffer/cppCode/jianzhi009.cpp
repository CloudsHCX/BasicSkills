/*
009 쳲���������
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n<=39
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
		int ret;
		switch (n) 
		{
		case 0: 
			ret = 0;
			break;
		case 1:
			ret = 1;
			break;
		case 2:
			ret = 1;
			break;
		default:
			int fir = 1,sec = 1, cnt = 2, thr;
			while(cnt < n)
			{
				thr = fir + sec;
				fir = sec;
				sec = thr;
				cnt ++ ;
			}
            ret = thr;
			break;
		}
		return ret;
    }
};