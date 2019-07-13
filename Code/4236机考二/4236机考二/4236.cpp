#include <iostream>
#include <cstdio>

using namespace std;

int V[100009] = { 0 };
long long sum = 0;
int R[100009] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &V[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &R[i]);
	}
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j <= i; j++)
		{
			if (V[j] >= R[i])
			{
				sum += R[i];
				V[j] -= R[i];
			}
			else if (V[j] < R[i])
			{
				sum += V[j];
				V[j] = 0;
			}

		}

		if (i != 0)printf(" ");
		printf("%lld", sum);
	}

	return 0;

}