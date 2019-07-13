/*#include <iostream>
#include <cstdio>

using namespace std;

int value[1005] = { 0 };
int weight[1005] = { 0 };
int st_bag[1005][10005] = { 0 };
int imax(int left, int right)
{
	return (left < right) ? right : left;
}
int main()
{
	int V, N;
	scanf("%d %d", &V, &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}

	
		for (int j = 1; j <= V; j++)
		{
			for (int i = 1; i <= N; i++)
			{
				if (j >= weight[i])
					st_bag[i][j] = imax(st_bag[i - 1][j], st_bag[i - 1][j - weight[i]] + value[i]);
				else st_bag[i][j] = st_bag[i - 1][j];
			}
			
		}
		
		printf("%d", st_bag[N - 1][V]);



		return 0;
}
*/
#include <iostream>
#include <cstdio>

using namespace std;

int weight[1010] = { 0 };
int value[1010] = { 0 };
int dp_bag[1010][10005] = { 0 };
int main()
{
	int N, V;
	scanf("%d %d", &V, &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (j >= weight[i])
				dp_bag[i][j] = dp_bag[i-1][j - weight[i]] + value[i] > dp_bag[i][j] ? dp_bag[i-1][j - weight[i]] + value[i] : dp_bag[i][j];
		}
	}
	printf("%d", dp_bag[N][V]);

	return 0;
}