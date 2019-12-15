/*
28. Implement strStr()

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
/*
�ַ���ƥ��
����һ��ֱ�ӱ���������ƥ���ַ�����BF�㷨
���������ڷ���һ�Ļ����ϣ�����hashֵ��⣬����26��������ʾ��hashֵ�����г�ͻ�����ǻ����int long��
���Բ�������hashRK�㷨
������������BM�㷨�����ַ��ͺú�׺ԭ��
������÷�������⡣
*/

#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
		{
			return 0;
		}
		if (haystack.size() < needle.size())
			return -1;
		
		//����needle��hashֵ
		int hash_needle = 0, hash_match = 0;
		for (int i = 0; i < needle.size(); i++)
		{
			hash_needle += needle[i] - 'a';
			hash_match += haystack[i] - 'a';
		}
		
		//�ҵ���һ��ƥ����±꣬������͵ķ�ʽ����hashֵ�������ڣ��Ƚ�ԭ�ַ���
		int i = 0;
		do
		{
			//��hashֵ
			if ((hash_needle == hash_match) && !haystack.substr(i, needle.size()).compare(needle))
			{
				return i;
			}
			if (i + needle.size() == haystack.size())
			{
				break;
			}
			//��һ��hash_match =��hash_match - ���λ��Ȩ�� * ֵ �� * 26 + ��һλ��Ӧ��ֵ
			hash_match = hash_match - (haystack[i] - 'a') + (haystack[i + needle.size()] - 'a');
			i++;
		} while (i <= (haystack.size() - needle.size()));
		return -1;
	}
};