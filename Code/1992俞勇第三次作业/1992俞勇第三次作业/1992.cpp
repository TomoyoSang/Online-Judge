#include <iostream>
#include <cstdio>

using namespace std;
int N[10000][2] = { 0 };
int n;

void Quicksort(int left, int right)
{
	if (left == right)return;
	else if (left - right == 1)return;
	else
	{
		int key = N[left][0];
		int key1 = N[left][1];
		int tmp1 = left;
		int tmp2 = right;

		while (left < right)
		{
			while (left<right&&N[right][0]>=key)
			{
				right--;
			}
			if (left < right)
			{
				N[left][0] = N[right][0];
				N[left][1] = N[right][1];
				left++;
			}
			while (left < right&&N[left][0] <= key)
			{
				left++;
			}
			if (left < right)
			{
				N[right][0] = N[left][0];
				N[right][1] = N[left][1];
				right--;
			}
			

		}
		N[left][0] = key;
		N[left][1] = key1;
		Quicksort(tmp1, left);
		Quicksort(left + 1, tmp2);


		return;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &N[i][0], &N[i][1]);
	}

	Quicksort(0, n - 1);
	
	int i = 0, j = 0;
	long long sum = 0;

	for ( i = 0; i < n; i++)
	{
		
		for (j=i ; j < n; j++)
		{
			
			if (N[i][1] >= N[j][1])
			{
				continue;
				
			}
			else if (N[i][1] < N[j][1])
			{
				if (N[i][1] >= N[j][0])
				{
					N[j][0] = N[i][0];
					i = j - 1;
					
					break;
				}
				else if (N[i][1] < N[j][0])
				{
					sum += N[i][1] - N[i][0];
					i = j - 1;
				
					break;

				}
			}
			
		}


		if (j == n)
		{
			sum += N[i][1] - N[i][0];
			break;
		}
		
	}
	
	cout << sum;
	return 0;
}