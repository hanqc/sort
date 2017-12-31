void AdjustDown(int* a, size_t size, int root)
{
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[root])
		{
			swap(a[child], a[root]);
			root = child;
			child = 2 * root + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, size_t size)
{
	// 建堆  
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	// 选数据排序  
	for (size_t i = 0; i < size; ++i)
	{
		swap(a[0], a[size - i - 1]);
		AdjustDown(a, size - i - 1, 0);
	}
}