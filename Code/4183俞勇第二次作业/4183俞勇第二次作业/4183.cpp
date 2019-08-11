#include <iostream>
#include <cstdio>

using namespace std;

int N[10][1000];
int n[10] = { 0 };
int k[10] = { 0 };
int m;


void Quanpai()
{
	int left = 0, right = 0;
	bool flag = 0;
	int tmp = 0;
	int imax = 0;
	int iplace = 0;
	

	for (int i = 0; i <m ; i++)
	{
		

		while (k[i] > 0)
		{
			flag = 0;


			for (int j = n[i] - 1; j > 0; j--)
			{
				if (N[i][j - 1] < N[i][j])
				{
					

					 imax = N[i][j];
					 iplace = j;
					for (int g = j; g < n[i]; g++)
					{
						if (N[i][g] > N[i][j - 1] && N[i][g] <= imax)
						{
							imax = N[i][g];
							iplace = g;
						}
					}


					tmp = N[i][iplace];
					N[i][iplace] = N[i][j - 1];
					N[i][j - 1] = tmp;
					k[i]--;
					flag = 1;
					
					left = j, right = n[i] - 1;
					while (left < right)
					{
						tmp = N[i][left];
						N[i][left] = N[i][right];
						N[i][right] = tmp;
						left++;
						right--;
					}
					j = n[i] ;
					break;
				}
				
				//¿ìËÙÅÅÐò??
				if (k[i] == 0)break;


			}

			if (!flag)
			{
				k[i]--;
				//µ¹Ðò
				 left = 0, right = n[i] - 1;
					while (left < right)
					{
						tmp = N[i][left];
						N[i][left] = N[i][right];
						N[i][right] = tmp;
						left++;
						right--;
					}



			}


			

		}

		//Êä³ö
		if (i != 0)printf("\n");
		for (int j = 0; j < n[i]; j++)
		{
			if (j != 0)printf(" ");
				printf("%d", N[i][j]);
		}
	}

}



int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	scanf("%d", &m);
	

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &n[i], &k[i]);
		
		for (int j = 0; j < n[i]; j++)
		{
			scanf("%d", &N[i][j]);
		}
		
	}

	
	Quanpai();


	return 0;
}