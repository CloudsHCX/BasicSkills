/*
9. Palindrome Number
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		//ת���ַ���
		string palindStr = to_string(x);
		int left = 0, right = palindStr.size() - 1;
		//ͨ������index�ƶ��ж�
		while (left < right)
		{
			if (palindStr[left] != palindStr[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};