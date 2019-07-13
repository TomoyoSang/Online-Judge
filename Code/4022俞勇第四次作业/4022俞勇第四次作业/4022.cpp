#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int x;
	long long n, sum = 0;
	scanf("%d", &x);
	scanf("%lld", &n);
	if (n >= 7)sum += n / 7 * 1250;
	n %= 7;
	for (; n > 0; --n)
	{
		if (x % 7 != 0 && x % 7 != 6)sum += 250;
		x++;
	}

	printf("%lld", sum);
	return 0;
}