#include <iostream>
#include <cstdio>

using namespace std;
long long N[100006] = { 0 };
void merge_sort(long long left, long long right)
{
	
		if (left == right - 1 || left == right)
			return;

		long long mid = (left + right) >> 1;

		merge_sort(left, mid);
		merge_sort(mid, right);

		long long* temp = new long long[right - left];

		for (long long i = left, j = mid, k = 0; k < right - left; ++k) {
			if (i < mid && j >= right) {
				temp[k] = N[i];
				++i;
			}
			else if (j < right&&i >= mid) {
				temp[k] = N[j];
				++j;
			}
			else {
				if (N[i] < N[j])
				{
					temp[k] = N[i];
					++i;
				}
				else
				{
					temp[k] = N[j];
					++j;
				}

			}
		}
		for (long long i = 0; i < right - left; i++)
		{
			N[left + i] = temp[i];
		}

		delete temp;
		return;

}
int main()
{
	long long n;
	scanf("%lld", &n);
	for (long long i = 0; i < n; ++i)
	{
		scanf("%lld", &N[i]);
	}
	merge_sort(0, n );
	for (long long i = 0; i < n; ++i)
	{
		if (i != 0)printf(" ");
			printf("%lld", N[i]);
	}
	printf("\n");

	return 0;
}