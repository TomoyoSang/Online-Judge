#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N[7][7] = { 0 };
int startx, starty, endx, endy;

int vis[6][6] = { 0 };


int _min(int a, int b)
{
	if (a == 0)return b;
	else if (b == 0)return a;
	return (a > b) ? b : a;
}

void dfs(int x, int y,int _cur,int sum)
{
	
	if (x == endx && y == endy)
	{
		vis[endx][endy] = _min(vis[endx][endy], sum + _cur * N[endx][endy]);
		return;
	}
	
	if (x != startx || y != starty)
	{
		sum += _cur * N[x][y];
		_cur = (_cur*N[x][y]) % 4 + 1;
		if (vis[x][y] == _min(vis[x][y], sum))return;
		vis[x][y] = sum;
	}
	

	
	if (x > 0)
	{
		
		dfs(x - 1, y,_cur, sum);
		
	}
	if (x < 5)
	{
		
		dfs(x + 1, y,_cur, sum);
		
	}
	if (y > 0)
	{
		
		dfs( x, y-1,_cur, sum);
		
	}
	if (y<5)
	{
	    
		dfs(x , y+1, _cur,sum);
	
	}
	
	return;
}


int main()
{
	int T = 0;
	scanf("%d", &T);
	for (; T > 0; --T)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				scanf("%d", &N[i][j]);
			}
		}

		
		scanf("%d %d %d %d", &startx, &starty, &endx, &endy);

		dfs(startx, starty,1, 0);
		printf("%d", vis[endx][endy]);
	}

	return 0;
}