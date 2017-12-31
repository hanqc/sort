#include <iostream>
using namespace std;
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}
int PartSort(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	swap(a[mid], a[end]);
	int& key = a[end];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
		{
			++begin;
		}
		while (begin < end&&a[end] >= key)
		{
			--end;
		}
		swap(a[begin], a[end]);
	}
	swap(a[begin], key);
	return begin;
}
int PartSort1(int* a, int begin, int end)//挖坑法
{
	int& key = a[end];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
		{
			++begin;
		}
		a[end] = a[begin];
		while (begin < end&&a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}
int PartSort2(int* a, int begin, int end)//前后指针法
{
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur<end)
	{
		if (a[cur]<key&&++prev != cur)
		{
			swap(a[cur], a[prev]);
		}
		++cur;
	}
	swap(a[++prev],a[end]);
	return prev;
}
#include <stack>
void QuickSortNonR(int *a, int left, int right)
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (! s.empty())
	{
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();

		int div = PartSort(a, begin, end);
		if (begin<div-1)
		{
			s.push(div - 1);
			s.push(begin);
		}
		if (div+1<end)
		{
			s.push(end);
			s.push(div + 1);
		}
		
	}

}
void QuickSort(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//小区间优化
	if (right - left < 16)
	{
		InsertSort(a + left, left - right + 1);
	}
	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

