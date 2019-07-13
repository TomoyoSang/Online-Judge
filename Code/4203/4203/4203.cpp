#include <iostream>
#include <cstring>

using namespace std;
#define P 1000000005

long long mods[100] = { 0 };
int bin[100] = { 0 };
int num[20000][2];
int i = 0, j = 0;
int k = 0, l = 0;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	i = P;
	while (i != 0)
	{

		bin[l] = i % 2;
		i /= 2;
		l++;

	}


	int n;

	cin >> n;

	long long   q = 1, m = 1;
	for (i = 0; i < n; i++)
	{
		cin >> num[i][0] >> num[i][1];
	}

	for (i = 0; i < n; i++)
	{
		q = 1;
		if (num[i][1] == 0)q = 1;
		else if (num[i][1] == num[i][0])q = 1;
		else
		{
			//数值调换
			if (num[i][0] - num[i][1] > num[i][1])
			{
				num[i][1] = num[i][0] - num[i][1];
			}

			//分子上的乘法：乘一次取一次模
			for (j = num[i][0]; j > num[i][1]; j--)
			{
				q *= j;
				q %= 1000000007;

			}
			//除以分母时，把除法转换为乘法
			for (j = num[i][0] - num[i][1]; j >= 2; j--)
			{
				memset(mods, 0, size(mods));
				mods[0] = j;
				//m = j;
				for (k = 1; k < l; k++)
				{
					//m %= 1000000007;
					mods[k] = ((long long)(mods[k - 1] * mods[k - 1]) % 1000000007);
					mods[k] = mods[k] % 1000000007;
				}
				k = 0;
				for (k = 0; k < l; k++)
				{
					if (bin[k] == 1)
					{
						q %= 1000000007;
						q *= mods[k];

					}

				}
				q %= 1000000007;

			}



		}
		cout << q << endl;
	}

	return 0;

}
//111011100110101100101000000101
//111011100110101100101000000101