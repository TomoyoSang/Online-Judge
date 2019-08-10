#include <iostream>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int *num, i = 0,sum=0;
	num = new int[N];
	for (i = 0; i < N; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	int average = sum / N;
	int times = 0, tmp = 0;
	

	for (i = 0; i < N-1; i++)
	{
		if (num[i] != average) {
			tmp = num[i] - average;
			num[i + 1] += tmp;
			times++;
		}
	}
	printf("%d", times);

	return 0;



}