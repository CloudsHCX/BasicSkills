/*
14. Longest Common Prefix
*/
/*
����strs[0]Ϊ��ʼ��ͬ���ַ���prefix��������prefix��strs[1...n]���бȽϣ�
ÿ�αȽϵ���prefix��ʹ��prefix��strs[i]����ͬ��ͬ���ַ�
*/
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		//���⴦��
		if (strs.size() == 0)
			return "";

		string prefix = strs[0];
		int len = strs.size();
		int j, prefixSize;
		//��strs������бȽϣ���prefix�ַ�����strs[i]�Ƚϣ�������ͬ���ַ�
		for (int i = 1; i < len; i++)
		{
			prefixSize = prefix.size();
			for (j = 0; j < prefixSize; j++)
			{
				//ȡ��ͷ��ʼ��ͬ����
				if (strs[i].compare(0, prefixSize - j, prefix, 0, prefixSize - j) == 0)
				{
					prefix = prefix.substr(0, prefixSize - j);
					break;
				}
			}
			//û����ͬ����
			if (j == prefixSize)
			{
				prefix = "";
				break;
			}
		}
		return prefix;
	}
};