
//���ֲ���������ظ����飬�����±꣬���򷵻�-1
int binary_search(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//����whileѭ�����ж��ֲ���
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		//��data[mid] == search_data����ֱ�ӷ����±�
		if (data[mid] == search_data)
		{
			return mid;
		}
		//��data[mid] < search_data����������ݴ���mid�ұ�
		else if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//��data[mid] > search_data����������ݴ���mid���
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

//���ֲ����������ظ����飬���ز���Ԫ�ص�һ�γ��ֵ��±꣬���򷵻�-1
int binary_search_first_data(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//����whileѭ�����ж��ֲ���
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		//��data[mid] == search_data����Ҫ�ж�mid�Ƿ�Ϊ�׸�Ԫ���±�
		if (data[mid] == search_data)
		{
			//��midΪ0����mid��ǰһ����Ϊsearch_data����Ϊ�׸�Ԫ���±�
			if (mid == 0 || data[mid - 1] != search_data)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		//��data[mid] < search_data����������ݴ���mid�ұ�
		else if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//��data[mid] > search_data����������ݴ���mid���
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

//���ֲ����������ظ����飬���ز���Ԫ�����һ�γ��ֵ��±꣬���򷵻�-1
int binary_search_last_data(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//����whileѭ�����ж��ֲ���
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		//��data[mid] == search_data����Ҫ�ж�mid�Ƿ�Ϊ���һ��Ԫ���±�
		if (data[mid] == search_data)
		{
			//��midΪ0����mid�ĺ�һ����Ϊsearch_data����Ϊ���һ��Ԫ���±�
			if (mid == (size - 1) || data[mid + 1] != search_data)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		//��data[mid] < search_data����������ݴ���mid�ұ�
		else if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//��data[mid] > search_data����������ݴ���mid���
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

//���ֲ����������ظ����飬���ҵ�һ�����ڵ��ڸ���ֵ��Ԫ�أ����򷵻�-1
int binary_search_first_exceed(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//����whileѭ�����ж��ֲ���
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);

		//��data[mid] < search_data����������ݴ���mid�ұ�
		if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//��data[mid] >= search_data�����mid��ǰһλ�����ж�
		else
		{
			if (mid == 0 || data[mid - 1] < search_data)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
	}

	return -1;
}

//���ֲ����������ظ����飬�������һ��С�ڵ��ڸ���ֵ��Ԫ�أ����򷵻�-1
int binary_search_last_below(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//����whileѭ�����ж��ֲ���
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);

		//��data[mid] > search_data����������ݴ���mid���
		if (data[mid] > search_data)
		{
			high = mid - 1;
		}
		//��data[mid] >= search_data�����mid�ĺ�һλ�����ж�
		else
		{
			if (mid == size - 1 || data[mid + 1] > search_data)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	return -1;
}