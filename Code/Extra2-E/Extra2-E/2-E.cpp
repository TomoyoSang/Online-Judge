#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long mod_num = (long long)(1e9 + 7);

int alpha[31] = { 0 };
char str[1000009] = { 0 };
long long hash_value[1500001][2] = { 0 };
long long ihash()
{
	memset(alpha, 0, sizeof(alpha));
	int len = strlen(str);
	int counter = 1;
	for (int i = 0; i < len; i++)
	{
		if (alpha[str[i] - 'a'] == 0)
		{
			alpha[str[i] - 'a'] = counter ;
			str[i] = 'a' + counter - 1;
			counter++;
		}
		else
		{
			str[i] = 'a' + alpha[str[i] - 'a'] - 1;
		}
	}

	long long isum = 0;
	for (int i = 0; i < len; i++)
	{
		isum = isum * 31LL + (long long)(str[i] - 'a' + 1);
		isum %= mod_num;
	}

	return isum;
}
int main()
{
	int bilibili = 0;
	int n;
	long long sum = 0;
	long long cur = 0;
	int imod2 = 0;
	int counter = 1;
	cin >> n;
		sum = 0;
		memset(hash_value, 0, sizeof(hash_value));
		for (int i = 0; i < n; i++)
		{
			counter = 1;
			scanf("%s", str);
			cur = ihash();
			imod2 = cur % 1500001;
			
			while (hash_value[imod2][0] != 0)
			{
				if (hash_value[imod2][0] == cur) {
					counter = hash_value[imod2][1] + 1;
					break;
				}
				imod2 = (imod2 + 1) % 1500001;
			}
			hash_value[imod2][0] = cur;
			hash_value[imod2][1] = counter;
			if (counter != 1&&counter!=0)sum += counter - 1;
		}

		

		
		printf("%lld\n", sum);
	return 0;

}