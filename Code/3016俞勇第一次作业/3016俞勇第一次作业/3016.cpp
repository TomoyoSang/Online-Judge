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
	
	
	/*while (left- right<0)
	{
		
		tmp = num[left] - average-remain;
		if (tmp >= 0) { times += extra; extra = 0; }
		i = num[left + 1] + tmp;
		if (i< 0)
		{
			tmp = -num[left + 1];
			remain = average - num[left] - num[left + 1];
			extra++;
		}
		num[left] -= tmp;
		num[left + 1] += tmp;
		left++; 
		times++;

		tmp = num[right] - average-remain;
		if (tmp >= 0) { times += extra; extra = 0; }
		i = num[right - 1] + tmp;
		if ( i< 0)
		{
			tmp = -num[right-1];
			remain = average - num[right] - num[right + 1];
			extra++;
		}
		num[right] -= tmp;
		num[right-1] += tmp;
		right--;
		times++;
		





	}*/

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