#include <iostream>
#include <cstdio>

using namespace std;


int N[10009] = { 0 };
int pre_sum[10009] = { 0 };
void  Quicksort(int left, int right)
{

	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	int key2 = N[left];


	while (left < right)
	{


		while (left < right  &&N[right] >= key2)
		{
			right--;
		}
		if (left < right)
		{
			N[left] = N[right];

			++left;
		}

		while (left < right &&N[left] <= key2)
		{
			left++;
		}
		if (left < right)
		{
			N[right] = N[left];

			--right;

		}


	}

	N[left] = key2;


	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);

	return;

}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
	}

	Quicksort(0, n - 1);
	long long sum = 0;
	pre_sum[0] = N[0];
	for (int i = 1; i < n; i++)
	{
		pre_sum[i] = pre_sum[i - 1] + N[i];
	}
	for (int i = 1; i < n; i++)
	{
		sum += pre_sum[i];
	}
	printf("%lld", sum);
	
	return 0;
}