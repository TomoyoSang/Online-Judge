#include <iostream>
#include <cstdio>

using namespace std;


int n, m;
int _pow[32] = { 0 };
int pos[32] = { 0 };
int main()
{
	_pow[0] = 1;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < 31; ++i)
	{
		_pow[i] = _pow[i - 1] * 2;
	}


	int counter = 0;
	int mini = 0;
	int cur = n;
	while (cur >= 1)
	{
		for (int i = 0; i < 31; ++i)
		{
			if (cur < _pow[i + 1])
			{
				pos[mini] = i;
				cur -= _pow[i];
				mini++;
				break;
			}
		}
	}
	

	if (m > n) {
		printf("%d", m - n);
	}

	else if (mini <= m)printf("%d", 0);
	else if (mini > m)
	{
		int len = mini - m;
		int sum = 0;
		while (len > 0)
		{

			sum += _pow[pos[mini - 2]] - _pow[pos[mini - 1]];
			mini--;
			len--;
			pos[mini - 1]++;
		}
		printf("%d", sum);
	}
	

	return 0;


}
