#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int n;
//移动方向
//0---右
//1---下
//2---左
//3---上
int direction = 0;
int hill_map[155][155] = { 0 };
//对应direction的x，y移动
int step[4][2] = { 0 };

//当走到边界时转换方向
void direction_change(int x, int y)
{
	if (hill_map[x + step[direction][0]][y + step[direction][1]] != 0)
	{
		direction = (++direction) % 4;
	}
	
	return;
}
int main()
{
	
	scanf("%d", &n);
	//当前坐标
	int x = 1, y = 0;
	//当前数值
	int counter = 1;
	//对应direction的step移动
	step[0][0] = 0; step[0][1] = 1;
	step[1][0] = 1; step[1][1] = 0;
	step[2][0] = 0; step[2][1] = -1;
	step[3][0] = -1; step[3][1] = 0;
	//在区域外建围墙
	for (int i = 1; i <= n; ++i)
	{
		hill_map[i][0] = -1;
		hill_map[i][n + 1] = -1;
		hill_map[0][i] = -1;
		hill_map[n + 1][i] = -1;
	}
	while (true)
	{
		direction_change(x, y);
		hill_map[x + step[direction][0]][y + step[direction][1]] = counter++;
		x += step[direction][0];
		y += step[direction][1];
		if (counter > n*n)break;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << setw(6) << hill_map[i][j];
		}
		cout << "\n";
	}
	return 0;
}