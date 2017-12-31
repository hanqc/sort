void CountSort(int *a,size_t n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n;i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		if (a[i]<min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* counts = new int[range];
	memset(counts, 0, sizeof(int)*range);
	for (size_t i = 0; i < n; ++i)
	{
		counts[a[i] - min]++;
	}
	int j = 0;
	for (size_t i = 0; i < range; i++)
	{
		while (counts[i]--)
		{
			a[j++] = i + min;
		}
	}
	delete[] counts;
}