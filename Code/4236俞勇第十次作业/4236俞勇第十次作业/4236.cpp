#include <iostream>
#include <cstdio>
using namespace std;

long long pri_que[200000] = { 0 };
long long V[100030] = { 0 };
long long R[100030] = { 0 };
long long n;
long long sum[100030] = { 0 };
long long cur_len = 0;
void _push(long long num)
{
	pri_que[++cur_len] = V[num];
	long long j = cur_len;
	while (j > 1 && pri_que[j / 2] > V[num])
	{
		pri_que[j] = pri_que[j / 2];
		j /= 2;
	}
	pri_que[j] = V[num];

	return;
}
void _down(long long hole)
{
	long long child = hole * 2;
	long long tmp = pri_que[hole];

	for (; hole * 2 <= cur_len; hole = child)
	{
		child = hole * 2;
		if (child != cur_len && pri_que[child + 1] < pri_que[child])
		{
			child++;
		}
		if (pri_que[child] < tmp)
		{
			pri_que[hole] = pri_que[child];
		}
		else break;
	}
	pri_que[hole] = tmp;
}
void _pop(long long i)
{
	sum[i] += pri_que[1];
	pri_que[1] = pri_que[cur_len--];
	_down(1);
	return;
}

int main()
{
	scanf("%d", &n);
	for (long long i = 1; i <= n; ++i)
	{
		scanf("%d", &V[i]);
	}
	for (long long i = 1; i <= n; ++i)
	{
		scanf("%d", &R[i]);
	}

	for (long long i = 1; i <= n; ++i)
	{
		_push(i);
		while (cur_len > 0)
		{
			if (pri_que[1] <= R[i])
			{
				_pop(i);
			}
			else break;
		}
		sum[i] += R[i] * cur_len;
		for (long long j = 1; j <= cur_len; ++j)
		{
			pri_que[j] -= R[i];
		}
		printf("%lld ", sum[i]);
	}


	return 0;
}