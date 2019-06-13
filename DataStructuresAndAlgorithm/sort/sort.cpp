#include <cstdio>
#include <algorithm>
using namespace std;
//ð������ data[] Ϊ�������飬nΪ�����С
void bubble_sort(int data[], int n)
{
	if (n < 2)
		return;
	
	for (int i = 0; i < n - 1 ; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			//����Ԫ�ؽ��бȽϣ�ǰ����ں���Ԫ��ʱ������Ԫ�أ�����ʶ����
			if (data[j] > data[j+1]) 
			{
				flag = true;
				swap(data[j], data[j + 1]);
			}
		}
		if (!flag)
			break;
	}
}

//�������� data[] Ϊ���������飬nΪ�����С
void insertion_sort(int data[], int n)
{
	if (n < 2)
		return;

	//��δ��������ѡ��Ԫ�ز��뵽����������,[0,i)Ϊ���������䣬[i,n)Ϊδ��������
	int value = 0;
	for (int i = 1; i < n; i++)
	{
		value = data[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			//��������Ԫ��С��ǰ�����ݣ��ƶ�����
			if (value < data[j])
			{
				data[j + 1] = data[j];
			}
			//�����ý���ʱ���˳�ѭ��			
			else
				break;
		}
		//����value������������
		data[j + 1] = value;
	}
}

//ѡ������data[] Ϊ���������飬nΪ�����С
void selection_sort(int data[], int n)
{
	if (n < 2)
		return;

	//��δ���������ҳ���СԪ�ز��뵽����������,[0,i)Ϊ���������䣬[i,n)Ϊδ��������
	int min_index;
	for (int i = 0; i < n - 1; i++)
	{
		//�ҵ�[i,n)��������С��Ԫ��
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (data[min_index] > data[j])
			{
				min_index = j;
			}
		}
		//����СԪ�ز��뵽����������ĩβ
		swap(data[i], data[min_index]);
	}
}

//�ϲ��ݹ����������䣬[left,mid],[mid+1,right]
void merge(int data[], int left, int mid, int right)
{
	//��ʱ���飬�����ϲ�
	int len = right - left + 1;
	int* tmp = new int[len];

	//iΪ������index��jΪ������index��kΪtmp����index
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		//������<��������Ԫ�أ�����data[left]��tmp����
		if (data[i] < data[j])
			tmp[k++] = data[i++];
		//��֮������data[mid+1] ��tmp ����
		else
			tmp[k++] = data[j++];
	}

	//��������ʣ��Ϊ�գ���������ʣ�����tmp����
	if (i > mid)
	{
		while (j <= right)
			tmp[k++] = data[j++];
	}
	//��������ʣ��Ϊ�գ���������ʣ�����tmp����
	else
	{
		while (i <= mid)
			tmp[k++] = data[i++];
	} 

	//��tmp����copy��data[left��right]
	for (int i = 0; i < len; i++)
	{
		data[i + left] = tmp[i];
	}

	delete[] tmp;
}

//�鲢�����ڲ��ݹ鲿��,[left,right]����
void __merge_sort(int data[], int left, int right)
{
	//�ݹ���ֹ����
	if (left >= right)
		return;
	
	int mid = left + ((right - left) >> 2);

	__merge_sort(data, left, mid);
	__merge_sort(data, mid + 1, right);

	merge(data, left, mid, right);
}

//dataΪ���������飬nΪ�����С
void merge_sort(int data[], int n)
{
	__merge_sort(data, 0, n - 1);
}

//��������������ȡ���һ��Ԫ��Ϊpivot��
//���ط��������±�
int partition(int data[], int left, int right)
{
	int pivot = data[right];

	//[left,r)ΪС��pivot���֣�(r,right]Ϊ����pivot����
	int r = left;
	for (int i = left; i < right; i++)
	{
		//С��pivot���뵽[left,r)���
		if (data[i] <= pivot)
		{
			swap(data[i], data[r]);
			++r;
		}
	}

	swap(data[r], data[right]);
	return r;
}

//���������ڲ��ݹ鲿��,[left,right]����
void __quick_sort(int data[], int left, int right)
{
	if (left >=  right)
		return;
	
	//��ԭ������з���
	int pos = partition(data, left, right);

	__quick_sort(data, left, pos - 1);
	__quick_sort(data, pos + 1, right);
}

//dataΪ���������飬nΪ�����С
void quick_sort(int data[], int n)
{
	__quick_sort(data, 0, n - 1);
}