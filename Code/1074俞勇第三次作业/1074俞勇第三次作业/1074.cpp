#include <iostream>
#include <cstdio>

using namespace std;
//”前缀和“算法

int painter[1300][1300] = { 0 };
int maximum = 0;
int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	char s = 0;
	int avai = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j =1; j <= M; j++)
		{
			
			s = cin.get();
			while (s != '-'&&s != 'X')
			{
				s = cin.get();
			}
			if (s == '-')avai = 0;
			else if (s == 'X')avai = 1;

			//从（0，0）到（i，j）的矩形内的和
			painter[i][j] = painter[i][j - 1] + painter[i - 1][j] - painter[i - 1][j - 1] + avai;
			
		}
	}
	
	
	int cur_max = 0;//当前最大矩形宽度
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = cur_max*2; j <= M; j++)
		{
			
			if (j == 0)
				continue;
			int counter = cur_max;
			for (; j >= counter * 2 && i >= counter; ++counter) {//从（i，j）开始向（0，0）方向的宽cur_max的小矩形
				if (painter[i][j] - painter[i][j - 2 * counter] - painter[i - counter][j] 
					+ painter[i - counter][j - 2 * counter] > 0)//==0时则表示这个小矩形内是空白的
					break;
			}
			--counter;
			if (counter > cur_max)cur_max = counter;
		}
	}


	cout << cur_max * cur_max * 2;

	return 0;
}
