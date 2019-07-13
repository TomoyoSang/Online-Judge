#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int Height[50010] = { 0 };
int st_min[50010][20] = { 0 };
int st_max[50010][20] = { 0 };
int imax(int left, int right)
{
	return (left < right) ? right : left;
}
int imin(int left, int right)
{
	return (left > right) ? right : left;
}

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Height[i]);
	}

	for (int i = 0; i < N; i++)
	{
		st_min[i][0] = Height[i];
		st_max[i][0] = Height[i];
	}
	for (int j = 1; j <= (int)(log(N) / 0.69314718); ++j)
	{
		for (int i = 0; i + (1 << j) <= N; i++)
		{
			st_max[i][j] = imax(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
			st_min[i][j] = imin(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
		}
	}

	int left = 0, right = 0;
	int len = 0; int j_2 = 0;
	int cur_max = 0, cur_min = 0;
	for (; Q > 0; Q--)
	{
		scanf("%d %d", &left, &right);
		len = right - left + 1;
		j_2 = (int)(log(len) / 0.69314718);
		cur_max = imax(st_max[left - 1][j_2], st_max[right - (1 << j_2)][j_2]);
		cur_min = imin(st_min[left - 1][j_2], st_min[right - (1 << j_2)][j_2]);
		printf("%d\n", cur_max - cur_min);
	}



	return 0;

}