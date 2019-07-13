#include <iostream>
#include <cstdio>

using namespace std;


int painter[1300][1300] = { 0 };
//int icopy[1300][1300] = { 0 };
//int lens[1300][1300] = { 0 };
int maximum = 0;
int N, M;
/*int checkit(int i, int j)
{
	//if (icopy[i][j] == 1)return 0;
	
	int len = 1;
	int cal = 0;
	int imax = 0;
	//if (lens[i - 1][j - 1] != 0)len = lens[i - 1][j - 1] - 1;
	/*for (; len + i <= N, 2 * len + j <= M; len++)
	{
		//if (len > lens[i][j - 1] + 1)break;
		if (icopy[i + len - 1][j + 2 * len - 1] == 1)cal = 1;
		else 
		cal = painter[i + len - 1][j + 2 * len - 1] - painter[i - 1][j + 2 * len - 1] - painter[i + len - 1][j - 1] + painter[i - 1][j - 1];
		if (cal == 0)
		{
			imax = 2 * len*len;
			lens[i][j] = len;
		}
		
	}
	
	/*for (; i - len + 1 > 0,j - 2 * len + 1 > 0; len++)
	{
		if (len > lens[i][j - 1] + 1)break;//如果这一位就是X,就直接跳过
		if (icopy[i - len + 1][j - 2 * len + 1] == 1)break;//如果左上角是X，则之后的都不用检查了
		else cal = painter[i][j] + painter[i - len][j - 2 * len] - painter[i][j - 2 * len] - painter[i - len][j];//该小方框内的X求和
		if (cal == 0)
		{
			imax = 2 * len*len;
			lens[i][j] = len;//第（i，j）位上的最大长度
		}
	}
	return imax;
}*/
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
			//icopy[i][j] = avai;

			painter[i][j] = painter[i][j - 1] + painter[i - 1][j] - painter[i - 1][j - 1] + avai;
			
		}
	}
	
	//检验数组存放内容
	/*for (int i = 0; i <= N; i++)
	{
		printf("\n");
		for (int j = 0; j <= M; j++)
		{
			printf("%d ", icopy[i][j]);
		}
	}*/
	int cur_max = 0;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = cur_max*2; j <= M; j++)
		{
			//counter = checkit(i, j);
			if (j == 0)
				continue;
			int counter = cur_max;
			for (; j >= counter * 2 && i >= counter; ++counter) {
				if (painter[i][j] - painter[i][j - 2 * counter] - painter[i - counter][j] + painter[i - counter][j - 2 * counter] > 0)
					break;
			}
			--counter;
			if (counter > cur_max)cur_max = counter;
		}
	}


	cout << cur_max * cur_max * 2;

	return 0;
}
