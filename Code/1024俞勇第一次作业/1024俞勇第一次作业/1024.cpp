#include <iostream>
#include <cstdio>

using namespace std;

int N[10003] = { 0 };
int n = 0;
//闭区间排序
void Quicksort(int left, int right)
{
	if (left >= right)return;
	int key = N[left];
	int tmp1 = left, tmp2 = right;
	while (left < right)
	{
		while (left < right&&N[right] >= key)
		{
			right--;
		}
		if (left < right)
		{
			N[left] = N[right];
			left++;
		}
		while (left < right&&N[left] <= key) 
		{
			left++;
		}
		if (left < right)
		{
			N[right] = N[left];
			right--;
		}
	}
	N[left] = key;
	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);
	return;
}

//更快的快速排序方法：
//未检验
void Quicker(int a[],int n)
{
	int p = a[n - 1], j = 0;
	int tmp = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] <= p)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			j++;
		}
	}
	tmp = a[n - 1];
	a[n - 1] = a[j];
	a[j] = tmp;
	Quicker(a, j);
	Quicker(a + j + 1, n - 1 - j);
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &N[i]);
	}
	Quicksort(0, n-1);
	for (int i = 0; i < n; ++i)printf("%d ", N[i]);
	return 0;
}