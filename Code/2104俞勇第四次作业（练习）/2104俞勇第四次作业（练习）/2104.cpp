#include <iostream>
#include <cstdio>

using namespace std;

int X = 0, Y = 0;
int N;
int my_map[1020][1020] = { 0 };
int visit[100000][2] = { 0 };


int main()
{
	scanf("%d%d", &X, &Y);
	scanf("%d", &N);
	int x1 = 0, y1 = 0;

	X += 500;
	Y += 500;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x1, &y1);
		my_map[500 + x1][500 + y1] = -1;
		
	}

	//int step = 0;
	int x = 500, y = 500;
	int left = 0, right = 1;
	visit[0][0] = 500;
	visit[0][1] = 500;
	my_map[500][500] = 1;

	while (visit[left][0] != X || visit[left][1] != Y)
	{
		x = visit[left][0];
		y = visit[left][1];
		
		
		left++;
		if (x > 0 && my_map[x - 1][y] == 0)
		{
			visit[right][0] = x - 1;
			visit[right][1] = y;
			my_map[x - 1][y] = my_map[x][y] + 1;
			right++;

		}
		if (x < 999 && my_map[x + 1][y] == 0)
		{
			visit[right][0] = x + 1;
			visit[right][1] = y;
			my_map[x + 1][y] =  my_map[x][y] + 1;
			right++;
		}
		if (y > 0 && my_map[x][y - 1] == 0)
		{
			visit[right][0] = x;
			visit[right][1] = y - 1;
			my_map[x][y - 1] = my_map[x][y] + 1;
			right++;
		}
		if (y < 999 && my_map[x][y + 1] == 0)
		{
			visit[right][0] = x;
			visit[right][1] = y + 1;
			my_map[x][y + 1] = my_map[x][y] + 1;
			right++;
		}

	}

	printf("%d", my_map[X][Y]-1);

		return 0;

}