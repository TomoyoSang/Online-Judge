#include <iostream>
#include <cstdio>

using namespace std;

int N, R = 0;
int P[200005] = { 0 };
int S[200005] = { 0 };
int Num[200005] = { 0 };

void placesort(int left, int right)
{
	if (left == right)return;
	else if (left - right == 1)return;
	else
	{
		int key2 = P[Num[left]];
		//int key1 = S[left];
		int key = Num[left];
		int tmp1 = left;
		int tmp2 = right;
		while (left < right)
		{
			
			
			while (left < right&& P[Num[right]] <= key2)
			{
				right--;
			}
			if (left < right)
			{
				//P[left] = P[right];
				//S[left] = S[right];
				Num[left] = Num[right];
				left++;
			}
			while (left < right&&P[Num[left]] >= key2)
			{
				left++;
			}
			if (left < right)
			{
				//P[right] = P[left];
				//S[right] = S[left];
				Num[right] = Num[left];
				right--;
			}


		}
		//P[left] = key2;
		//S[left] = key1;
		Num[left] = key;
		placesort(tmp1, left);
		placesort(left + 1, tmp2);
		return;

	}

}


void partsort()
{
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		//分高排在前
		if (P[Num[2 * i]] < P[Num[2 * i + 1]])
		{
			tmp = Num[2 * i];
			Num[2 * i] = Num[2 * i + 1];
			Num[2 * i + 1] = tmp;
		}
		//序号小排在前
		else if (P[Num[2 * i]] == P[Num[2 * i + 1]])
		{
			tmp = Num[2 * i];
			Num[2 * i] = Num[2 * i + 1];
			Num[2 * i + 1] = tmp;
		}
		if (i > 0)
		{
			//比较2k与2k+1 分高排在前
			if (P[Num[2 * i]] > P[Num[2 * i - 1]])
			{
				tmp = Num[2 * i];
				Num[2 * i] = Num[2 * i - 1];
				Num[2 * i - 1] = tmp;
			}
			//序号小排在前
			else if (P[Num[2 * i]] == P[Num[2 * i - 1]])
			{
				if (Num[2 * i] < Num[2 * i - 1])
				{
					tmp = Num[2 * i];
					Num[2 * i] = Num[2 * i - 1];
					Num[2 * i - 1] = tmp;
				}
			}
		}


	}
	return;
}

void fight()
{
	for (int i = 0; i < N; i++)
	{
		if (S[Num[2 * i]] > S[Num[2 * i + 1]])
		{
			P[Num[2 * i]] += 2;
		}
		else if (S[Num[2 * i]] == S[Num[2 * i + 1]])
		{
			P[Num[2 * i]]++;
			P[Num[2 * i + 1]]++;
		}
		else  if (S[Num[2 * i]] < S[Num[2 * i + 1]])
		{
			P[Num[2 * i + 1]] += 2;
		}

	}
	return;
}
int main()
{
	//输入
	scanf("%d%d", &N, &R);
	for (int i = 0; i < 2 * N; i++)
	{
		scanf("%d", &P[i]);
		Num[i] = i;
	}
	for (int i = 0; i < 2 * N; i++)
	{
		scanf("%d", &S[i]);
	}
	//第一次：快排
	placesort(0, 2 * N - 1);
	/*for (int i = 0; i < 2 * N; i++)
	{
		printf(" ");
		printf("%d", Num[i]+1);
	}
	printf(" \n");
	*/

	for (int i = 0; i < R; i++)
	{
		//先比赛，后排名
		fight();
		partsort();

	}

	//输出
	for (int i = 0; i < 2 * N; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", Num[i] + 1);

	}
	//printf("%d%d", P[Num[1]], P[Num[2]]);
	return 0;
}