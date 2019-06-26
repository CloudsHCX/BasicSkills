/*
13. Roman to Integer
*/

/*
ͨ���Ե�һ�������ֵ��жϣ������IXC��������ж���һ�ַ������ַ�ƴ�ӳ�key����ӳ�����
��ö�Ӧ��ֵ��Ϣ
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		//��������ֵӳ���
		unordered_map<string, int> numeralsMap{ {"M", 1000}, {"CM", 900}, {"D", 500},
												{"CD", 400}, {"C", 100}, {"XC", 90},
												{"L", 50}, {"XL", 40}, {"X", 10},
												{"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1} };
		string specialFirstRoman("IXC");
		string specialSecondRoman[3]{ {"VX"},{"LC"},{"DM"} };
		string key;
		int len = s.size();
		int j, k;
		int res = 0;
		for (int i = 0; i < len;)
		{
			//ƴ�ӵ�һ��������
			key += s[i];
			//�жϵ�һ���������Ƿ�����IXC
			for (j = 0; j < specialFirstRoman.size(); j++)
			{
				//��һ������������IXC
				if (s[i] == specialFirstRoman[j])
				{
					//��һ������������IXC����Ҫ����һ�������ֽ�һ���ж�
					if ((i++) == len)
						break;
					for (k = 0; k < specialSecondRoman[j].size(); k++)
					{
						if (s[i] == specialSecondRoman[j][k])
						{
							key += s[i];
							i++;
							break;
						}
					}
					break;
				}
			}
			
			//��һ�������ֲ�����IXC
			if (j == specialFirstRoman.size())
				i++;
			//����key��ȡ��ֵ
			res += numeralsMap[key];
			//���key
			key.clear();
		}
		return res;
	}
};