void LSDSort(int *a,size_t n)
{
	int digits = 1;
	int base = 10;
	for (size_t i = 0; i < n;++i)
	{
		while (a[i]>=base)
		{
			++digits;
			base *= 10;
		}
	}
	base = 1;
	int* buckets = new int[n];
	for (size_t i = 0; i < digits;++i)
	{
		//0-9号桶的数据个数
		int count[10] = { 0 };
		for (size_t i = 0; i < n; i++)
		{
			int num = (a[i]/base) % 10;
			count[num]++;
		}
		//0-9号桶的第一个数据的起始位置
		int start[10] = { 0 };
		for (size_t i = 1; i < 10; i++)
		{
			start[i] = start[i - 1] + count[i - 1];
		}
		for (size_t i = 0; i < n; i++)
		{
			int num = (a[i] / base) % 10;
			int index = start[num]++;
			buckets[index] = a[i];
		}
		memcpy(a, buckets, sizeof(int)*n);
		base *= 10;
	}
	delete[] buckets;
}