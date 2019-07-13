#include <iostream>
#include <cstdio>

using namespace std;

int N[302][302][3] = { 0 };
int queue[100000][2] = { 0 };
int iendx = 0, iendy = 0;
int cur_pos = 0, cur_len = 1;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &N[i][j][0]);
			if (N[i][j][0] == 2)
			{
				queue[0][0] = i;
				queue[0][1] = j;
			}
			if (N[i][j][0] == 3)
			{
				iendx = i;
				iendy = j;
			}
		}
	}
	N[queue[0][0]][queue[0][1]][1] = 6;
	N[queue[0][0]][queue[0][1]][2] = 0;
	int ifadd = 0;
	while (cur_len != 0 && (queue[cur_pos][0] != iendx || queue[cur_pos][1] != iendy))
	{

		if (N[queue[cur_pos][0]][queue[cur_pos][1]][0] == 4)
			N[queue[cur_pos][0]][queue[cur_pos][1]][1] = 6;
		//推入队列的判断条件：
		//1.不越界
		//2.不是建筑
		//3.体力值大于之前的体力值
		if (queue[cur_pos][0] > 1 && N[queue[cur_pos][0] - 1][queue[cur_pos][1]][0] != 0 && N[queue[cur_pos][0]][queue[cur_pos][1]][1]  - 1 > N[queue[cur_pos][0] - 1][queue[cur_pos][1]][1])
		{
			//体力值
			N[queue[cur_pos][0] - 1][queue[cur_pos][1]][1] = N[queue[cur_pos][0]][queue[cur_pos][1]][1] + ifadd - 1;
			//时间
			N[queue[cur_pos][0] - 1][queue[cur_pos][1]][2] = N[queue[cur_pos][0]][queue[cur_pos][1]][2] + 1;
			//推入队列
			queue[(cur_pos + cur_len) % 100000][0] = queue[cur_pos][0] - 1;
			queue[(cur_pos + cur_len) % 100000][1] = queue[cur_pos][1];
			//队列长度
			cur_len++;
		}
		if (queue[cur_pos][0] < n&& N[queue[cur_pos][0] + 1][queue[cur_pos][1]][0] != 0 && N[queue[cur_pos][0]][queue[cur_pos][1]][1]  - 1>N[queue[cur_pos][0] + 1][queue[cur_pos][1]][1])
		{
			//体力值
			N[queue[cur_pos][0] + 1][queue[cur_pos][1]][1] = N[queue[cur_pos][0]][queue[cur_pos][1]][1] + ifadd - 1;
			//时间
			N[queue[cur_pos][0] + 1][queue[cur_pos][1]][2] = N[queue[cur_pos][0]][queue[cur_pos][1]][2] + 1;
			//推入队列
			queue[(cur_pos + cur_len) % 100000][0] = queue[cur_pos][0] + 1;
			queue[(cur_pos + cur_len) % 100000][1] = queue[cur_pos][1];
			//队列长度
			cur_len++;
		}
		if (queue[cur_pos][1] > 1 && N[queue[cur_pos][0]][queue[cur_pos][1] - 1][0] != 0 && N[queue[cur_pos][0]][queue[cur_pos][1]][1]  - 1 > N[queue[cur_pos][0]][queue[cur_pos][1] - 1][1])
		{
			//体力值
			N[queue[cur_pos][0]][queue[cur_pos][1] - 1][1] = N[queue[cur_pos][0]][queue[cur_pos][1]][1] + ifadd - 1;
			//时间
			N[queue[cur_pos][0]][queue[cur_pos][1] - 1][2] = N[queue[cur_pos][0]][queue[cur_pos][1]][2] + 1;
			//推入队列
			queue[(cur_pos + cur_len) % 100000][0] = queue[cur_pos][0];
			queue[(cur_pos + cur_len) % 100000][1] = queue[cur_pos][1] - 1;
			//队列长度
			cur_len++;
		}
		if (queue[cur_pos][1] < m&& N[queue[cur_pos][0]][queue[cur_pos][1] + 1][0] != 0 && N[queue[cur_pos][0]][queue[cur_pos][1]][1] - 1>N[queue[cur_pos][0]][queue[cur_pos][1] + 1][1])
		{
			//体力值
			N[queue[cur_pos][0]][queue[cur_pos][1] + 1][1] = N[queue[cur_pos][0]][queue[cur_pos][1]][1] + ifadd - 1;
			//时间
			N[queue[cur_pos][0]][queue[cur_pos][1] + 1][2] = N[queue[cur_pos][0]][queue[cur_pos][1]][2] + 1;
			//推入队列
			queue[(cur_pos + cur_len) % 100000][0] = queue[cur_pos][0];
			queue[(cur_pos + cur_len) % 100000][1] = queue[cur_pos][1] + 1;
			//队列长度
			cur_len++;
		}
	
		cur_pos = (cur_pos + 1) % 100000;
		cur_len--;
	}
	if (cur_len == 0)printf("%d", -1);
	else printf("%d", N[queue[cur_pos][0]][queue[cur_pos][1]][2]);
	return 0;
}