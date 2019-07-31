#include <iostream>
#include <cstdio>

using namespace std;
//����������ʾÿ���߷���x��y�ƶ����
//�磺
//   x            y    
//step[0][0]= ;step[0][1]= 
//step[1][0]= ;step[1][1]= 
//********
//step[7][0]= ;step[7][1]=

//����ΪBFS�Ĵ���ʾ��
int m, n, m1, m2;
int startx, starty, endx, endy;
int N[50][50] = { 0 };
int cur_len = 1;
int map_que[5000][2] = { 0 };
int main()
{
	scanf("%d %d %d %d", &m, &n, &m1, &m2);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &N[i][j]);
			if (N[i][j] == 0 || N[i][j] == 2)
			{
				N[i][j] = -1;
			}
			else if (N[i][j] == 1)
			{
				N[i][j] = 0;
			}
			if (N[i][j] == 3)
			{
				N[i][j] = 0;
				startx = i;
				starty = j;
			}
			else if (N[i][j] == 4)
			{
				endx = i;
				endy = j;
				N[i][j] = 0;
			}


		}
	}

	//����ΪBFS�Ĵ���ʾ��

	//����BFS
	map_que[0][0] = startx;
	map_que[0][1] = starty;
	int ifront = 0;
	while (map_que[ifront][0] != endx || map_que[ifront][1] != endy)
	{
		//����
		if ((map_que[ifront][0] + m1 < m&&map_que[ifront][1] + m2 < n) && N[map_que[ifront][0] + m1][map_que[ifront][1] + m2] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] + m1;
			map_que[ifront + cur_len][1] = map_que[ifront][1] + m2;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		if (map_que[ifront][0] + m2 < m&&map_que[ifront][1] + m1 < n&&N[map_que[ifront][0] + m2][map_que[ifront][1] + m1] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] + m2;
			map_que[ifront + cur_len][1] = map_que[ifront][1] + m1;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		//����
		if (map_que[ifront][0] + m1 < m&&map_que[ifront][1] - m2 >= 0 && N[map_que[ifront][0] + m1][map_que[ifront][1] - m2] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] + m1;
			map_que[ifront + cur_len][1] = map_que[ifront][1] - m2;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		if (map_que[ifront][0] + m2 < m&&map_que[ifront][1] - m1 >= 0 && N[map_que[ifront][0] + m2][map_que[ifront][1] - m1] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] + m2;
			map_que[ifront + cur_len][1] = map_que[ifront][1] - m1;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		//����
		if (map_que[ifront][0] - m1 >= 0 && map_que[ifront][1] + m2 < n&&N[map_que[ifront][0] - m1][map_que[ifront][1] + m2] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] - m1;
			map_que[ifront + cur_len][1] = map_que[ifront][1] + m2;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		if (map_que[ifront][0] - m2 >= 0 && map_que[ifront][1] + m1 < n&&N[map_que[ifront][0] - m2][map_que[ifront][1] + m1] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] - m2;
			map_que[ifront + cur_len][1] = map_que[ifront][1] + m1;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		//����
		if (map_que[ifront][0] - m1 >= 0 && map_que[ifront][1] - m2 >= 0 && N[map_que[ifront][0] - m1][map_que[ifront][1] - m2] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] - m1;
			map_que[ifront + cur_len][1] = map_que[ifront][1] - m2;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}
		if (map_que[ifront][0] - m2 >= 0 && map_que[ifront][1] - m1 >= 0 && N[map_que[ifront][0] - m2][map_que[ifront][1] - m1] == 0)
		{
			map_que[ifront + cur_len][0] = map_que[ifront][0] - m2;
			map_que[ifront + cur_len][1] = map_que[ifront][1] - m1;
			N[map_que[ifront + cur_len][0]][map_que[ifront + cur_len][1]] = N[map_que[ifront][0]][map_que[ifront][1]] + 1;
			cur_len++;
		}

		ifront++;
		cur_len--;
	}

	printf("%d", N[endx][endy]);

	return 0;

}