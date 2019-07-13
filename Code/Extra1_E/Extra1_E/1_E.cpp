#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int imax(int left, int right)
{
	return (left < right) ? right : left;
}
int imin(int left, int right)
{
	return (left < right) ? left : right;
}
int flag = 0;
int a[200009] = { 0 };
int b[200009] = { 0 };
int st_data1[200009][18] = { 0 };
int st_data2[200009][18] = { 0 };

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}


	for (int i = 0; i < n; i++)
	{
		st_data1[i][0] = a[i];
		st_data2[i][0] = b[i];

	}
	for (int j = 1; j <= (int)(log((double)(n)) / 0.69314718); ++j)
	{
		for (int i = 0; i + (1 << j) <= n; ++i)
		{
			st_data1[i][j] = imax(st_data1[i][j - 1], st_data1[i + (1 << (j - 1))][j - 1]);
			st_data2[i][j] = imin(st_data2[i][j - 1], st_data2[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	int left = 0, right = 0;
	int mid = 0;
	int cur_l = 0, cur_r = 0;
	for (int i = 0; i < n; i++)
	{
		left = i;
		right = n - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (st_data1[mid] > st_data2[mid])
			{
				right = mid -1;
			}
			else if (st_data1[mid] < st_data2[mid])
			{
				left = mid + 1;
			}
			else
			{
				//´ýÍê³É
				cur_l = mid;
				cur_r = mid;
				while (left <= cur_l)
				{
					mid = (left + cur_l) / 2;
					if(st_data1[(left+cur_l)/2]==st_data2[(left+cur_l)/2])
				}
				while (cur_r <= right)
				{
					if(st_data1[(right + cur_r) / 2] == st_data2[(right + cur_l) / 2])
				}

			}
		}
	}
	

	printf("%d", flag);
	return 0;

}