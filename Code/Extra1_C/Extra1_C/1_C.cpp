#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int water[1002] = { 0 };
int ST[1200][10] = { 0 };
int len = 0;
int j_2 = 0;
int imax(int left, int right)
{
	return (left < right) ? right : left;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int n = 0;
	for (; T > 0; T--)
	{
		memset(water, 0, sizeof(water));
		memset(ST, 0, sizeof(ST));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &water[i]);
		}
		
		//预处理
		for (int i = 0; i < n; i++)
		{
			ST[i][0] = water[i];
		}


		for (int j = 1; j <= (int)(log(n) / 0.69314718); ++j)
		{
			for (int i = 0; i+(1<<j) <= n;++i)
			{
				ST[i][j] = imax(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
			}
		}

		
		//在线查询
		int q = 0, j = 0;
		int cur_max = 0;
		int left = 0, right = 0;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d", &left, &right);
			len = right - left + 1;
			j_2 = (int)(log(len)/log(2) + 1);
			
			cur_max = imax(ST[left-1][j_2-1], ST[right- (1 << (j_2-1))][j_2-1]);
			printf("%d\n", cur_max);
		
		}

	}

	return 0;

}