#include <iostream>
using namespace std;
#include "InsertSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "SelectSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "CountSort.h"
#include "LSDSort.h"
int main()
{
	int a[] = { 21, 12, 32, 42, 72, 28, 62, 25, 29, 60 };
	LSDSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		cout << a[i] << " ";
	}
}