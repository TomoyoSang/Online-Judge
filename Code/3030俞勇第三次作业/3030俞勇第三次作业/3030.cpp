#include <iostream>
#include <cstdio>
int MAx(int a,int b)
{
	if (a > b)return a;
	return b;

}

using namespace std;

int M = 0, T = 0;
int V[102][1020] = { 0 };
int VT[102][2] = { 0 };
int beibao()
{
	
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= T; j++)
		{
			if (j < VT[i][1])
			{
				V[i][j] = V[i - 1][j];
			}

			else
			{
				V[i][j] = MAx(V[i - 1][j], V[i - 1][j - VT[i][1]] + VT[i][0]);
			}
		}
			
				

	
	return V[M][T];
}


int main()
{
	scanf("%d %d", &T, &M);
	//价值、时间
	for (int i = 1; i <=M ; i++)
	{
		scanf("%d %d", &VT[i][1], &VT[i][0]);
	}

	
	int sum = beibao();
	printf("%d", sum);




	return 0;
}





