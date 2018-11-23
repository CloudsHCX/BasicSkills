/*
053 �����˻�����

��Ŀ����
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
����ʹ�ó�����
*/

/*
��������dp���飬һ��������߳˻����飬һ�������ұ߳˻�����
���Ľ�����ǣ� C[i] = A[i-1] * B[i+1]
*/
#include <vector>
#include <iostream>;
using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int> leftMulArr(len), rightMulArr(len), res(len);

		leftMulArr[0] = A[0];
		for (int i = 1; i < len; i++)
			leftMulArr[i] = leftMulArr[i - 1] * A[i];

		rightMulArr[len - 1] = A[len - 1];
		for (int i = len - 2; i >= 0; i--)
			rightMulArr[i] = rightMulArr[i + 1] * A[i];

		res[0] = rightMulArr[1];
		res[len - 1] = leftMulArr[len - 2];
		for (int i = 1; i < len - 1; i++)
		{
			res[i] = leftMulArr[i - 1] * rightMulArr[i + 1];
		}
		return res;
	}
};