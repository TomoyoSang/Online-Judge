#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

inline int read()
{
	int X = 0, w = 0;
	char ch = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return X;
}
inline void write(int x)
{
	int y = 10, len = 1;
	while (y <= x)
	{
		y *= 10; len++;
	}
	while (len--)
	{
		y /= 10; putchar(x / y + 48);
		x %= y;
	}
}
int imax(int left, int right)
{
	return (left < right) ? right : left;
}

int apples[200010] = { 0 };
int st_data[200100][18] = { 0 };
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	int left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		apples[i] = read();
	}

	for (int i = 0; i < n; i++)
	{
		st_data[i][0] = apples[i];
	}

	for (int j = 1; j <= (int)(log(n) / 0.69341718); ++j)
	{
		for (int i = 0; i < n; i++)
			st_data[i][j] = imax(st_data[i][j - 1], st_data[i + (1 << (j - 1))][j - 1]);
	}
	int cur_max = 0;
	int len = 0;
	int j_2 = 0;
	for (; q > 0; q--)
	{
		left = read();
		right = read();
		len = right - left + 1;
		j_2 = (int)(log(len) / 0.69314718 + 1);

		cur_max = imax(st_data[left - 1][j_2 - 1], st_data[right - (1 << (j_2 - 1))][j_2 - 1]);
		write(cur_max);
		putchar('\n');

	}
	
	return 0;
}