#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int n;
//�ƶ�����
//0---��
//1---��
//2---��
//3---��
int direction = 0;
int hill_map[155][155] = { 0 };
//��Ӧdirection��x��y�ƶ�
int step[4][2] = { 0 };

//���ߵ��߽�ʱת������
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
	//��ǰ����
	int x = 1, y = 0;
	//��ǰ��ֵ
	int counter = 1;
	//��Ӧdirection��step�ƶ�
	step[0][0] = 0; step[0][1] = 1;
	step[1][0] = 1; step[1][1] = 0;
	step[2][0] = 0; step[2][1] = -1;
	step[3][0] = -1; step[3][1] = 0;
	//�������⽨Χǽ
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