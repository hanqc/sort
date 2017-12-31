#include <assert.h>
void _MergeSort(int* a,int left,int right,int* tmp)
{
	if (left>= right)
	{
		return;
	}
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid,tmp);
	_MergeSort(a, mid + 1, right,tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	size_t index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1]<a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a+left, tmp+left, (right - left + 1)*sizeof(int));
}
void MergeSort(int *a,size_t n)
{
	assert(a);
	int *tmp = new int[n];
	_MergeSort(a, 0, n - 1, tmp);
	delete []tmp;
}