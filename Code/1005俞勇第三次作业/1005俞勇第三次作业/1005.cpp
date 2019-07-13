#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int N[20][9][9] = { 0 };
int checker[9] = { 0 };
bool rowcheck(int q)
{
	bool flag = 1;

	for (int k = 0; k < 9; k++)
	{
		memset(checker, 0, sizeof(checker));
		for (int i = 0; i < 9; i++)
		{

			checker[N[q][k][i]-1] = 1;
		}
		for (int j = 0; j < 9; j++)
		{
			if (checker[j] == 0)return 0;
		}

		
	}
	
	return 1;
}

bool linecheck(int q)
{
	bool flag = 1;

	for (int k = 0; k < 9; k++)
	{
		memset(checker, 0, sizeof(checker));
		for (int i = 0; i < 9; i++)
		{

			checker[N[q][i][k]-1] = 1;
		}
		for (int j = 0; j < 9; j++)
		{
			if (checker[j] == 0) return 0;

		}

		
	}

	return 1;

}

bool blockcheck(int q)
{
	bool flag = 1;
	for (int k = 0; k < 9; k += 3)
	{
		for (int i = 0; i < 9; i += 3)
		{
			memset(checker, 0, sizeof(checker));
			for (int j = k; j < k + 3; j++)
			{
				for (int m = i; m < i + 3; m++)
				{
					checker[N[q][j][m]-1] = 1;
				}
			}
			for (int p = 0; p < 9; p++)
			{
				if (checker[p] == 0)return 0;
			}

			
		}
	}
	return flag;


}



int main()
{
	int n;
	cin >> n;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				scanf("%d", &N[i][j][k]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{


		


		flag1 = linecheck(i);
		flag2 = rowcheck(i);
		flag3 = blockcheck(i);
		/*cout << endl;
		cout << flag1 << " " << flag2 << " " << flag3 << endl;*/
		if (i != 0)printf("\n");
		if (flag1&&flag2&&flag3)printf("%s", "Right");
		else printf("%s", "Wrong");
		
	}




	return 0;
}


