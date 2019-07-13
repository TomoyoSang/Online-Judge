#include <iostream>
#include <cstdio>

using namespace std;

int n = 0;
int N[100030] = { 0 };
//int M[1000000001] = { 0 };
//int Q[1000000000] = { 0 };
int main()
{
	long long sum = 0;
	int cur = 0;
	scanf("%d", &n);
	int _max = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &cur);
		if (i == 0)
		{
			N[i] = cur;
		}
		else N[i] = N[i - 1] + cur;
		if (N[i] >= 0)
		{
			M[N[i]]++;
			_max = (_max > M[N[i]]) ? _max : M[N[i]];
		}
	}
	
	printf("%d", _max);
	return 0;

}