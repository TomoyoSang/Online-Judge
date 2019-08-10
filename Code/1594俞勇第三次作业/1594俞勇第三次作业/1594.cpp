#include <iostream>
#include <cstdio>

using namespace std;

//Ç°×ººÍ
long long n[13000002] = { 0 };

int main()
{
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);

	long long cur = 0;
	int iMax = (N + 1)*(M + 1);
	int m = 0;
	for (int i = 0; i < iMax; i++)
	{
		m = m % (M + 1);
		if (i >= 0 && i <= M )n[i] = 0;
		else if (m == 0)n[i] = 0;
		else
		{
			scanf("%lld", &cur);
			n[i] = n[i - 1] + n[i - M-1] - n[i - M - 2] + cur;
		}
		m++;
	}

	
	int x1, y1, x2, y2;
	int x, y, z,r;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x = (x1-1) * (M + 1) + y1-1 ;
		y = x2 * (M + 1) + y2;
		z= (x1-1) * (M + 1) + y2 ;
		r= x2 * (M + 1) + y1-1;

		printf("%lld\n", n[y]-n[z]-n[r]+n[x]);
	}

	return 0;
}
