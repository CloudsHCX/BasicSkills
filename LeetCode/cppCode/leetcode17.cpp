/*
17. Letter Combinations of a Phone Number
*/

/*
�����digits�ַ�����ת���������������ϣ�����
output[j] += input[i][j / segmentSize % strSize]��������鼴��
ʱ�临�Ӷ�O(3^N*4^N * len)
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return vector<string>();
		unordered_map<char, string> digitMap{ {'2', "abc"}, {'3', "def"}, {'4',"ghi"},
											  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
											  {'8', "tuv"}, {'9', "wxyz"} };
		
		vector<string> input;//��������תΪ����ĸ����
		int count = 1;//���ж������
		int len = digits.size();

		//���������룬ת��Ϊ��Ӧ����ĸ���룬����input,������һ���ж������
		for (int i = 0; i < len; i++)
		{
			input.push_back(digitMap[digits[i]]);
			count *= digitMap[digits[i]].size();
		}

		vector<string> output(count);
		int strSize, segmentSize = count; //�����ַ���Ӧ��string���ȣ���ͬ�εĳ���
		//�����ܳ���
		for (int i = 0; i < len; i++)
		{
			strSize = input[i].size();
			segmentSize /= input[i].size();
			//���������ж�Ӧһ���ַ�ƴ�����
			for (int j = 0; j < count; j++)
				output[j] += input[i][j / segmentSize % strSize];
		}
		return output;
	}
};