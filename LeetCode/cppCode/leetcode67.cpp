/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��

ʾ�� 1:

����: a = "11", b = "1"
���: "100"
ʾ�� 2:

����: a = "1010", b = "1011"
���: "10101"
*/

/*
��������������͡���������10������ͷ���������һ����λ�����档
*/
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
		int carry = 0;
		int len1 = a.size();
		int len2 = b.size();
		string res;
		//��a+b
		while(len1 > 0 || len2 > 0)
		{
			int ab = len1 <= 0 ? 0 : a[len1-1] - '0';
			int bb = len2 <= 0 ? 0 : b[len2-1] - '0';
			res.insert(res.begin(), ((ab + bb + carry) % 2) + '0');
			carry = (ab + bb + carry) / 2;
			--len1,--len2;
		}
		//��������λ
		if(carry)
			res.insert(res.begin(), '1' );
		return res; 

    }
};