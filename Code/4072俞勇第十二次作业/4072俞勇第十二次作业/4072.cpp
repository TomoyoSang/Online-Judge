#include <iostream>
#include <cstdio>

using namespace std;

long long n, m, k;

long long N[100030][3] = { 0 };
bool flag[100030] = { 0 };
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if (k == 0)
	{
		printf("%d", -1);
		return 0;
	}

	for (long long i = 1; i <= m; ++i)
	{
		scanf("%lld %lld %lld", &N[i][0], &N[i][1], &N[i][2]);
	}

	long long cur = 0;
	for (long long i = 1; i <= k; ++i)
	{
		scanf(" %lld", &cur);
		flag[cur] = 1;
	}
	long long cur_min = 1423235365215;
	bool cup = 0;
	for (long long i = 1; i <= m; ++i)
	{
		if (flag[N[i][0]]&&(!flag[N[i][1]]) || (!flag[N[i][0]])&&flag[N[i][1]])
		{
			cup = 1;
			cur_min = (cur_min < N[i][2]) ? cur_min : N[i][2];
		}
	}

	if (!cup)printf("%d", -1);
	else printf("%lld", cur_min);
	return 0;
}