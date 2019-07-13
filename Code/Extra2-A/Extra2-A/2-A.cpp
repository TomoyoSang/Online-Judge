#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int N[3009] = { 0 };
int sum[10009] = { 0 };
void  Quicksort(int left, int right)
{

	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	int key2 = N[left];


	while (left < right)
	{


		while (left < right  &&N[right] <= key2)
		{
			right--;
		}
		if (left < right)
		{
			N[left] = N[right];

			++left;
		}

		while (left < right &&N[left] >= key2)
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
	int bilibili = 0;
	int n, m;
	while (cin>>n>>m)
	{
		memset(N, 0, sizeof(N));
		memset(sum, 0, sizeof(sum));
		//cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &N[i]);
		}
		Quicksort(0, n - 1);
		int counter = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum[N[i] + N[j]]++;
			}
		}
		
		for (int i = 10000; i >= 0; i--)
		{
			if (!m)break;
			if(sum[i]!=0)
				while (sum[i])
				{
					if (!m)break;
					if (!counter)
					{
						counter++;
					}
					else printf(" ");

					printf("%d", i);
					--sum[i];
					m--;
					
				}
			
		}
		printf("\n");
		
	}
	


	return 0;
}