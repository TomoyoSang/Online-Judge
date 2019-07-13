#include <iostream>
#include <cstdio>

using namespace std;


int n = 0;
int N[300100] = { 0 };
int multi[300100] = { 0 };
int iminus[300000] = { 0 };
void  Quicksort( int left, int right)
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
	scanf("%d", &n);
	int cal = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
		multi[i] = cal;
		cal *= 2;
		cal %= 1000000007;
	}

	Quicksort(0, n - 1);
	long long leftsum = 0, rightsum = 0;
	int left = 0, right = n - 1;
	while (left<n-1&&right>0)
	{
		leftsum += N[left];
		rightsum += N[right];
		iminus[left] = (rightsum - leftsum) % 1000000007;
		left++;
		right--;
	}


	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ((long long)iminus[i] *(long long )multi[i])% 1000000007;
		sum %= 1000000007;
		
	}
	
	printf("%lld", sum);

	return 0;
}