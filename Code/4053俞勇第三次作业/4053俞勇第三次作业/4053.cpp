#include <iostream>
#include <cstdio>

using namespace std;

bool flag = 0;
int n;
int isp[36] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0 };
int A[20] = { 0 };
int vis[20] = { 0 };
void dfs(int cur)
{
	if (cur == n && isp[A[0] + A[n - 1]])
	{
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			
			if (i != 0)printf(" ");
			printf("%d", A[i]);
			
			
		}
		printf("\n");

	}
	else for (int i = 2; i <= n; i++)
	{
		if (!vis[i] && isp[i + A[cur - 1]])
		{
			A[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
	return;
}
int main()
{
	A[0] = 1;
	scanf("%d", &n);
	dfs(1);
	if (!flag)printf("None");

	return 0;
}