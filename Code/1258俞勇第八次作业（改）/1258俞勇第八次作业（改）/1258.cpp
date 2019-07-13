#include <iostream>
#include <cstdio>

using namespace std;

int N[100009] = { 0 };
long long sum = 0;
void merge(int left, int right) {
	if (left == right - 1 || left == right)
		return;

	int mid = (left + right) >> 1;

	merge(left, mid);
	merge(mid, right);

	int* temp = new int[right - left];

	for (int i = left, j = mid, k = 0; k < right - left; ++k) {
		if (i < mid && j >= right) {
			temp[k] = N[i];
			++i;
			
		}
		else if (j < right&&i >= mid) {
			temp[k] = N[j];
			++j;
			
			
		}
		else {
			if (N[i] <= N[j])
			{
				temp[k] = N[i];
				++i;
				
			}
			else
			{
				temp[k] = N[j];
				++j;
				sum += mid - i;
			}

		}
	}
	for (int i = 0; i < right - left; i++)
	{
		N[left + i] = temp[i];
	}

	delete temp;
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
	}
	merge(0, n);

	printf("%lld", sum);
	
	return 0;
}