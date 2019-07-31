#include <iostream>
#include <cstdio>

using namespace std;

//注意：本轮繁殖产生的新细菌格子不能作为该轮的繁殖中心！！

//培养皿边长
int L = 0;
//模拟培养皿
int plate[101][101] = { 0 };
//上一轮结束时的繁殖结果
int _plate[101][101] = { 0 };
//空白格子数
int blank = 0;
//繁殖轮数
int turns = 0;
//判断该位置是否为空格
int _judge(int i, int j)
{
	if (i >= 0 && i < L&&j >= 0 && j < L&&_plate[i][j] == 0 && plate[i][j] == 0)
	{
		plate[i][j] = 1;
		return 1;
	}
	else return 0;
}
//增殖
void _multiply()
{
	while (blank > 0)
	{
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j)
			{
				if (_plate[i][j] == 1)
				{
					blank -= _judge(i + 1, j);
					blank -= _judge(i, j + 1);
					blank -= _judge(i - 1, j);
					blank -= _judge(i, j - 1);
				}
			}
		}
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j) {
				_plate[i][j] = plate[i][j];
			}
		}

		turns++;
	}
	return;

}

int main()
{
	cin >> L;
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			cin >> plate[i][j];
			_plate[i][j] = plate[i][j];
			if (plate[i][j] == 0)
				blank++;
		}
	}
	_multiply();
	cout << turns;

	return 0;
}