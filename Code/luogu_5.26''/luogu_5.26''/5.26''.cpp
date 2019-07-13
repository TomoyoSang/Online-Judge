#include <iostream>
#include <cstdio>

using namespace std;
int N[1020] = { 0 };
int main()
{
	int n;
	scanf("%d", &n);
	int cur = 0;
	int sum = n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &cur);
		if (N[cur] != 0)
		{
			sum--;
		}
		else N[cur] = 1;
	}
	printf("%d\n", sum);
	for (int i = 1; i<=1000; ++i)
	{
		if (N[i] == 1)printf("%d ", i);
	}

	return 0;
}