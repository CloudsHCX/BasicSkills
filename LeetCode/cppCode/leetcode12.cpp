/*
12. Integer to Roman
*/

/*
ͨ���ַ�������洢����,շת�������ƴ�Ӷ�Ӧ��������
*/

#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		//�������stringӳ������
		string numeralMap[13] = { "M", "CM", "D", "CD", "C", "XC",
			                    "L", "XL", "X", "IX", "V", "IV", "I"};
		//���ֽ���ӳ������
		int numerals[13] = { 1000, 900, 500, 400, 100, 90,
						50, 40, 10, 9, 5, 4, 1 };

		string res;
		//շת�������ƾ���������
		for (int i = 0; i < 13;)
		{
			//num�ܹ�������ȥnumerals[i]��Ӧ�Ľ�������
			if ((num - numerals[i]) >= 0)
			{
				res += numeralMap[i];
				num -= numerals[i];
				continue;
			}
			i++;
		}
		return res;
	}
};