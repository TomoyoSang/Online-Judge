#include <iostream>
#include <cstdio>

using namespace std;


int seq[2000][200] = { 0 };

bool cmp(int X, int Y)
{
	bool flag = 1;
	if (seq[X][0] != seq[Y][0])return 0;
	for (int i = 1; i <= seq[X][0] + 1; i++)
	{
		if (seq[X][i] != seq[Y][i])
		{
			flag = 0;
			break;
		}

	}
	if (flag)
	{
		memset(seq[X], 0, sizeof(seq[X]));
		memset(seq[Y], 0, sizeof(seq[Y]));
	}
	return flag;
}


void insert(int L, int R, int K)
{
	for (int i = L; i <= R; i++)
	{
		seq[i][seq[i][0] + 1] = K;
		seq[i][0]++;
	}

	return;

}

int main()
{
	int opr = 0;
	int K = 0;
	int n = 0, m = 0;
	int L = 0, R = 0;
	scanf("%d %d", &n, &m);
	int counter = 0;
	int X = 0, Y = 0;
	bool flag = 1;
	for (; m > 0; m--)
	{


		scanf("%d", &opr);
		if (opr == 0)
		{

			scanf("%d %d %d", &L, &R, &K);
			insert(L - 1, R - 1, K);
		}
		else if (opr == 1)
		{
			if (!counter)
			{
				counter++;
			}
			else {
				printf("\n");
			}
			scanf("%d %d", &X, &Y);
			flag = cmp(X - 1, Y - 1);
			if (flag)printf("YES");
			else printf("NO");
		}


	}

	return 0;
}