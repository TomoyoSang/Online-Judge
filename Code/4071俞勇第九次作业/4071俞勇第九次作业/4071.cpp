#include <iostream>
#include <cstdio>

using namespace std;

//矩阵的快速幂
//最好查一查
long long A[2][2] = { {1,1} };
long long B[2][2] = { {1,1},{1,0} };
long long cur_B1[2][2] = { {1,1},{1,0} };
long long cur_B2[2][2] = { {1,1},{1,0} };
long long cur_B0[2][2] = { {1,1},{1,0} };
int fast_pow[65] = { 0 };
const long long _mod = 1e9 + 7;
int main()
{
	long long n;
	scanf("%lld", &n);
	int counter = 0;
	if (n <=2)
	{
		printf("%d", n);
		return 0;
	}
	
	
	n -= 1;
	while (n != 0)
	{
		fast_pow[counter] = n % 2;
		counter++;
		n /= 2;
	}

	if (fast_pow[0] == 0)
	{
		B[0][0] = 1;
		B[0][1] = 0;
		B[1][0] = 0;
		B[1][1] = 1;
	}
	
	
	for (int i = 1; i <= counter; i++)
	{
		cur_B0[0][0] = ((cur_B1[0][0] * cur_B2[0][0]) % _mod + (cur_B1[0][1] * cur_B2[1][0]) % _mod) % _mod;
		cur_B0[0][1] = ((cur_B1[0][0] * cur_B2[0][1]) % _mod + (cur_B1[0][1] * cur_B2[1][1]) % _mod) % _mod;
		cur_B0[1][0] = ((cur_B1[1][0] * cur_B2[0][0]) % _mod + (cur_B1[1][1] * cur_B2[1][0] )% _mod) % _mod;
		cur_B0[1][1] = ((cur_B1[1][0] * cur_B2[0][1]) % _mod + (cur_B1[1][1] * cur_B2[1][1] )% _mod) % _mod;

		if (fast_pow[i] == 1)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					cur_B1[j][k] = B[j][k];
					
				}
			}
			B[0][0] = ((cur_B0[0][0] * cur_B1[0][0]) % _mod + (cur_B0[0][1] * cur_B1[1][0]) % _mod) % _mod;
			B[0][1] = ((cur_B0[0][0] * cur_B1[0][1]) % _mod + (cur_B0[0][1] * cur_B1[1][1]) % _mod) % _mod;
			B[1][0] = ((cur_B0[1][0] * cur_B1[0][0]) % _mod + (cur_B0[1][1] * cur_B1[1][0]) % _mod) % _mod;
			B[1][1] = ((cur_B0[1][0] * cur_B1[0][1]) % _mod + (cur_B0[1][1] * cur_B1[1][1]) % _mod) % _mod;

		}
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cur_B1[j][k] = cur_B0[j][k];
				cur_B2[j][k] = cur_B0[j][k];
			}
		}

		
	}
	
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 2; k++)
		{
			cur_B1[j][k] = A[j][k];

		}
	}
	A[0][0] = ((cur_B1[0][0] * B[0][0]) % _mod + (cur_B1[0][1] * B[1][0]) % _mod) % _mod;
	A[0][1] = ((cur_B1[0][0] * B[0][1]) % _mod + (cur_B1[0][1] * B[1][1]) % _mod) % _mod;
	A[1][0] = ((cur_B1[1][0] * B[0][0]) % _mod + (cur_B1[1][1] * B[1][0]) % _mod) % _mod;
	A[1][1] = ((cur_B1[1][0] * B[0][1]) % _mod + (cur_B1[1][1] * B[1][1]) % _mod) % _mod;


	printf("%lld", A[0][0]);

	return 0;
}