#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//宝藏及位置信息的记录
int N[103][103] = { 0 };//位置信息
int treasure[6][2] = { 0 };//宝藏点记录
int counter = 0;//计数器：有多少宝藏、
int n, m;


int vis[8] = { 0 };//全排列是否经过这一点
int _road[6] = { 0 };//全排列的路径
int pace[6][6] = { 0 };//不同宝藏点之间的路径值
int sum_len[130] = { 0 };//某次排列的总路径值
int num = 0;
int sum = 0;

//bfs的变量
int visit[103][103] = { 0 };//求路径值时是否经过这一点
int bfs_que[10030][3] = { 0 };
int _front = 0;
int que_len = 0;

bool test(int i)
{
	int x = treasure[i][0];
	int y = treasure[i][1];
	int _counter = 0;
	/*if (x > 0)
	{
		if (N[x - 1][y] == -1)counter++;
	}
	if (x < n - 1)
	{
		if (N[x + 1][y] == -1)counter++;
	}
	if (y > 0)
	{
		if (N[x][y - 1] == -1)counter++;
	}
	if (y < m - 1)
	{
		if (N[x][y + 1] == -1)counter++;
	}
	if (counter == 4)return 0;
	else if (counter == 3)
	{
		if (x == 0 || x == n - 1 || y == 0 || y == m - 1)return 0;
	}
	else if (counter == 2)
	{
		if (x == 0 && y == 0 || x == 0 && y == m - 1 || x == n - 1 && y == 0 || x == n - 1 && y == m - 1)return 0;
	}*/
	memset(visit, 0, sizeof(visit));
	_front = 0;
	que_len = 1;
	
	bfs_que[_front][0] = x;
	bfs_que[_front][1] = y;

	while (que_len)
	{
		if (bfs_que[_front][0] > 0 && visit[bfs_que[_front][0] - 1][bfs_que[_front][1]] != 1 && N[bfs_que[_front][0] - 1][bfs_que[_front][1]] != -1)
		{
			bfs_que[_front + que_len][0] = bfs_que[_front][0] - 1;
			bfs_que[_front + que_len][1] = bfs_que[_front][1];
			que_len++;
			visit[bfs_que[_front][0] - 1][bfs_que[_front][1]] = 1;
			if (N[bfs_que[_front][0] - 1][bfs_que[_front][1]] == 1)_counter++;
		}
		if (bfs_que[_front][0] < n - 1 && visit[bfs_que[_front][0] + 1][bfs_que[_front][1]] != 1 && N[bfs_que[_front][0] + 1][bfs_que[_front][1]] != -1)
		{
			
			bfs_que[_front + que_len][0] = bfs_que[_front][0] + 1;
			bfs_que[_front + que_len][1] = bfs_que[_front][1];
			que_len++;
			visit[bfs_que[_front][0] + 1][bfs_que[_front][1]] = 1;
			if (N[bfs_que[_front][0] + 1][bfs_que[_front][1]] == 1)_counter++;
		}
		if (bfs_que[_front][1] > 0 && visit[bfs_que[_front][0]][bfs_que[_front][1] - 1] != 1 && N[bfs_que[_front][0]][bfs_que[_front][1] - 1] != -1)
		{
			
			bfs_que[_front + que_len][0] = bfs_que[_front][0];
			bfs_que[_front + que_len][1] = bfs_que[_front][1] - 1;
			que_len++;
			visit[bfs_que[_front][0]][bfs_que[_front][1] - 1] = 1;
			if (N[bfs_que[_front][0]][bfs_que[_front][1] - 1] == 1)_counter++;
		}
		if (bfs_que[_front][1] < m - 1 && visit[bfs_que[_front][0]][bfs_que[_front][1] + 1] != 1 && N[bfs_que[_front][0]][bfs_que[_front][1] + 1] != -1)
		{
			
			bfs_que[_front + que_len][0] = bfs_que[_front][0];
			bfs_que[_front + que_len][1] = bfs_que[_front][1] + 1;
			que_len++;
			visit[bfs_que[_front][0]][bfs_que[_front][1] + 1] = 1;
			if (N[bfs_que[_front][0]][bfs_que[_front][1]+1] == 1)_counter++;
		}
		que_len--;
		_front++;

	}
	if(_counter==counter)
	return 1;
	else return 0;
}

int bfs(int x, int y)
{
	if (pace[_road[x]][_road[y]] != 0)
	{
		return pace[_road[x]][_road[y]];
	}
	memset(visit, 0, sizeof(visit));
	_front = 0;
	que_len = 1;
	int startx = treasure[_road[x]][0], starty = treasure[_road[x]][1];
	int endx = treasure[_road[y]][0], endy = treasure[_road[y]][1];

	bfs_que[_front][0] = startx;
	bfs_que[_front][1] = starty;

	while (bfs_que[_front][0] != endx || bfs_que[_front][1] != endy)
	{
		if (bfs_que[_front][0] > 0&&visit[bfs_que[_front][0] - 1][bfs_que[_front][1]]!=1&&N[bfs_que[_front][0]-1][bfs_que[_front][1]]!=-1)
		{
			bfs_que[_front + que_len][2] = bfs_que[_front][2] + 1;
			bfs_que[_front + que_len][0] = bfs_que[_front][0] - 1;
			bfs_que[_front + que_len][1] = bfs_que[_front][1];
			que_len++;
			visit[bfs_que[_front][0] - 1][bfs_que[_front][1]] = 1;
		}
		if (bfs_que[_front][0] < n-1 && visit[bfs_que[_front][0] +1][bfs_que[_front][1]] != 1 && N[bfs_que[_front][0] + 1][bfs_que[_front][1]] != -1)
		{
			bfs_que[_front + que_len][2] = bfs_que[_front][2] + 1;
			bfs_que[_front + que_len][0] = bfs_que[_front][0] + 1;
			bfs_que[_front + que_len][1] = bfs_que[_front][1];
			que_len++;
			visit[bfs_que[_front][0] + 1][bfs_que[_front][1]] = 1;
		}
		if (bfs_que[_front][1] > 0 && visit[bfs_que[_front][0]][bfs_que[_front][1]-1] != 1 && N[bfs_que[_front][0]][bfs_que[_front][1]-1] != -1)
		{
			bfs_que[_front + que_len][2] = bfs_que[_front][2] + 1;
			bfs_que[_front + que_len][0] = bfs_que[_front][0];
			bfs_que[_front + que_len][1] = bfs_que[_front][1] - 1;
			que_len++;
			visit[bfs_que[_front][0]][bfs_que[_front][1] - 1] = 1;
		}
		if (bfs_que[_front][1] < m-1 && visit[bfs_que[_front][0]][bfs_que[_front][1]+1] != 1 && N[bfs_que[_front][0]][bfs_que[_front][1]+1] != -1)
		{
			bfs_que[_front + que_len][2] = bfs_que[_front][2] + 1;
			bfs_que[_front + que_len][0] = bfs_que[_front][0];
			bfs_que[_front + que_len][1] = bfs_que[_front][1] + 1;
			que_len++;
			visit[bfs_que[_front][0]][bfs_que[_front][1] + 1] = 1;
		}
		que_len--;
		_front++;

	}
	pace[_road[x]][_road[y]] = bfs_que[_front][2];
	memset(bfs_que, 0, sizeof(bfs_que));
	_front = 0;
	que_len=0;
	return pace[_road[x]][_road[y]];
}


int _min(int a, int b)
{
	return (a < b) ? a : b;
}

void dfs(int x)
{
	if (x > counter)
	{
		
		sum = 0;
		for (int i = 0; i < counter; i++)
		{
			sum += bfs(i, i + 1);
		}
		sum_len[num] = sum;
		num++;
		
	}
	

	for (int i = 1; i <= counter; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			_road[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}

	return;
}

int main()
{
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &N[i][j]);
			if (N[i][j] == 2)
			{
				treasure[0][0] = i;
				treasure[0][1] = j;
			}
			else if (N[i][j] == 1)
			{
				treasure[counter + 1][0] = i;
				treasure[counter + 1][1] = j;
				++counter;
			}
		}
	}
	//检验是否可达
	
		bool flag = test(0);
		if (!flag)
		{
			printf("%d", -1);
			return 0;
		}
	
	
	
	int mini = 9999;
	_road[0] = 0;
	dfs(1);
	for (int i = 0; i < num; i++)
	{
		mini = _min(mini, sum_len[i]);
	}

	printf("%d", mini);
	
	

	return 0;
}