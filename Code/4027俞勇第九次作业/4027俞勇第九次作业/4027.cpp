#include <iostream>
#include <cstdio>

using namespace std;

int dp[1002][1002] = { 0 };
int line1[1002] = { 0 };
int line2[1002] = { 0 };
int _max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &line1[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &line2[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = _max(dp[i - 1][j], dp[i][j - 1]);
			if (line1[i] == line2[j])
			{
				dp[i][j]++;
			}
		}
	}

	printf("%d", dp[n][n]);
	return 0;

}