#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int trains[1020] = { 0 };
int orders[1020] = { 0 };

int main() 
{
	int T = 0;
	scanf("%d", &T);
	int N, M;
	for (; T > 0; T--)
	{
		int j = 0, i = 0;
		memset(trains, 0, sizeof(trains));
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &orders[i]);//要求的顺序
		}

		i = 0;
		int counter = 0;
		
		bool flag = 1;//是否能成功调度

		//调度过程
		//i--该列火车的第i节
		//j--要求的顺序的第j节车厢
		while (j < N)
		{
			if (i == orders[j])//该车厢在火车上
			{
				i++;
				j++;
			}
			else if (counter != 0)//若车站还有车
								//看车站最外面的车是否满足条件	
			{
				if (trains[counter - 1] == orders[j])
				{
					j++;
					counter--;
				}
				else if (trains[counter - 1] > orders[j])//车站最外面的比要求的大了，说明该节车厢在里面出不来了，调度不成功
				{
					printf("NO\n");
					flag = 0;
					break;
				}
				else if (trains[counter - 1] < orders[j])//车站最外面比要求的小，可以让火车上过来几节车厢，看能不能把所需的车厢挖出来
				{
					trains[counter] = i;
					counter++;
					i++;
				}
			
			}
			else //车站没车了，直接往里开
			{
				trains[counter] = i;
				counter++;
				i++;
			}
			
			if (i == N)//此时原来的火车已经全出去或者进车站了
			{
				if (j == N)break;//已满足条件
				else if (counter > 0 && trains[counter - 1] == orders[j])//把车站里的车厢都开出来
				{
					j++;
					counter--;
				}
				else
				{
					printf("NO\n");
					flag = 0;
				}
			}
				
			if (counter > M)//超载，调度不成功
			{
				printf("NO\n");
				flag = 0;
				break;
			}
				
			
		}
		if (flag)printf("YES\n");

		
	}

	return 0;
}