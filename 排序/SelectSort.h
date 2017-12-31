#include<assert.h>
void SelectSort(int *a, size_t n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (size_t i = begin; i <= end; ++i)
		{
			if (a[i]<a[min])
			{
				min = i;
			}
			if (a[i]>a[max])
			{
				max = i;
			}
			swap(a[max], a[end]);
			if (min == end)
			{
				min = max;
			}
			swap(a[min], a[begin]);
			++begin;
			--end;
		}
	}
}