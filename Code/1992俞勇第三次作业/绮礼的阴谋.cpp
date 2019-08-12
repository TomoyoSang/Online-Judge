#include <iostream>
#include <cstdio>

using namespace std;

int n = 0;
int scope[10052][2] = { 0 };
void Quicksort(int left, int right)
{
	if (left >= right)return;
	int tmp1 = left, tmp2 = right;
	int key0 = scope[left][0];
	int key1 = scope[left][1];
	int tmp = 0;
	while (left < right)
	{
		while (left < right&&scope[right][0] >= key0)
		{
			right--;
		}
		if (left < right)
		{
			scope[left][0] = scope[right][0];
			scope[left][1] = scope[right][1];
			left++;
		}
		while (left < right&&scope[left][0] <= key0)
		{
			left++;
		}
		if (left < right)
		{
			scope[right][0] = scope[left][0];
			scope[right][1] = scope[left][1];
			right--;
		}
	}
	scope[left][0] = key0;
	scope[left][1] = key1;
	Quicksort( tmp1, left);
	Quicksort(left + 1, tmp2);
	return;
}
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &scope[i][0],&scope[i][1]);
	}

	Quicksort(0, n - 1);

	register int sum = 0;
	for (int i = 0; i < n-1; ++i)
	{
		//1.有公共区间
		//**********
		//    ***** 
		//或：
		//**********
		//    ********** 
		//向下迭代，保证下面的范围较大
		if (scope[i][1] >= scope[i + 1][0])
		{
			scope[i + 1][0] = scope[i][0];
			if (scope[i][1] >= scope[i + 1][1])
			{
				scope[i + 1][1] = scope[i][1];
			}
			
		}
		//2.脱节了：
		//***** 
		//         ****
		//直接清算，从下一个继续看
		else
		{
			sum += scope[i][1] - scope[i][0];
		}
		
	}
	//最后一个区间无论如何也无法参与清算
	//需手动清算
	sum += scope[n - 1][1] - scope[n - 1][0];
	printf("%d", sum);
	return 0;
}