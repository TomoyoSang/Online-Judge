#include <iostream>
#include <cstring>
using namespace std;


#define endl '\n'
#define E 1000000005

int bin[100] = { 0 };
long long jmods[100001] = { 1 };
long long  imods[10001] = { 1 };
long long q = 1, p = 1;
int nums[20000][2];
int i = 0, j = 0, k = 0, l = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//把1e9+5化成二进制
	i = E;
	while (i != 0)
	{

		bin[l] = i % 2;
		i /= 2;
		l++;

	}


	//jmods【i】表示i的阶乘（除1e9+7的余数）
	jmods[0] = 1;
	jmods[1] = 1;
	for (i = 2; i <= 100000; i++)
	{
		jmods[i] = ((jmods[i - 1]) % 1000000007)*i;
		jmods[i] %= 1000000007;
	}

	//输入阶段
	int N;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> nums[i][0] >> nums[i][1];
	}

	for (i = 0; i < N; i++)
	{
		q = 1;
		p = 1;
		if (nums[i][1] == 0)q = 1;
		else if (nums[i][1] == nums[i][0])q = 1;

		else {
			q *= jmods[nums[i][0]];
			q %= 1000000007;
			p *= jmods[nums[i][1]];
			p %= 1000000007;
			p *= jmods[nums[i][0] - nums[i][1]];
			p %= 1000000007;

			memset(imods, 0, sizeof(imods));
			imods[0] = p;
			for (k = 1; k < l; k++)
			{
				//imods[i] = ((imods[i - 1] * imods[i - 1]) % 1000000007);
				imods[k] = (long long)(imods[k - 1] * imods[k - 1]);
				imods[k] %= 1000000007;
			}

			for (k = 0; k < l; k++)
			{
				if (bin[k] == 1)
				{
					q %= 1000000007;
					q *= imods[k];
				}
				q %= 1000000007;
			}

		}

		cout << q << endl;
	}



	return 0;

}