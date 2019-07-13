#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N[20005][20005] = { 0 };//距离
long long A, B, C;//三个位置
long long n = 0;//几个房间
long long mini = 15331382;//最短距离
bool known[20002] = { 0 };//是否检查过最短距离


void bfs(long long st)
{
	memset(known, 0, sizeof(known));
	known[st] = 1;
	N[st][st] = 0;
	long long minimu = 134580210062;
	int num = 0;
	for (int i = 1; i <= n; ++i)
	{
		minimu = 134580210062;
		if (!known[i] && N[st][i]<minimu&&N[st][i]!=0)
		{
			minimu = N[st][i];
			num = i;
		}

		known[num] = 1;

		for (int j = 1; j <= n; ++j)
		{
			if (j!=st&&N[num][j] != 0)
			{
				if (!known[j] && (N[st][j] > N[st][num] + N[num][j]) || N[st][j] == 0)
				{
					N[st][j] = N[st][num] + N[num][j];
					N[j][st] = N[st][j];
					known[j] = 1;
				}
			}
		}

	}
	
	return;

}
int main()
{
	scanf("%lld %lld %lld %lld", &n, &A, &B, &C);
	long long u, v, w;
	for (long long i = 1; i < n; ++i)
	{
		scanf("%lld %lld %lld", &u, &v, &w);
		N[u][v] = w;
		N[v][u] = w;
	}

	for (long long i = 1; i <= n; ++i)
	{
		bfs(i);
	}

	long long sum = 0;
	int counter = 0;
	for (long long i = 1; i <= n; ++i)
	{
		sum = N[i][A] + N[i][B] + N[i][C];
		if (sum < mini)
		{
			mini = sum;
			counter = i;
		}
		mini = (sum < mini) ? sum : mini;
	}
	printf("%d\n", counter);
	printf("%lld", mini);
	return 0;

}