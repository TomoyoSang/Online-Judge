#include <iostream>
#include <cstdio>

using namespace std;



int N[2000100] = { 0 };
int M[2000100] = { 0 };
int main()
{
	int n = 0, d = 0;
	scanf("%d %d", &n, &d);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
	}

	
	int left = 0, right = 1;
	int cur_max = 0;
	int flag = 0;
	M[0] = N[0];
	int i;
	for (i = 1; i < n; i++)
	{
			while (right>left&&N[i] > M[right-1])
			{
				M[right - 1] = 0;
				right--;
			}
			M[right] = N[i];
			right++;
         
		if(i>=2*d+1)
			if (M[left] == N[i - 2 * d - 1])
			{
				left++;
			}

		if (i >= d)
		{
			cur_max = M[left];
			if (cur_max > 2 * N[i - d])
			{
				flag++;
			}
		}

	}

	for (i=n-d; i < n ; i++)
	{
		if(M[left]==N[i-d-1])
		left++;
		cur_max = M[left];
		if (cur_max > 2 * N[i])flag++;
	}

	printf("%d", flag);
	return 0;
}