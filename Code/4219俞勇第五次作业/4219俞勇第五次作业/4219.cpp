#include <iostream>
#include <cstdio>

using namespace std;


int N[200100] = { 0 };

void merge_sort(int left,int right) {
	if (left == right - 1 || left == right)
		return;
	
	int mid = (left + right) >> 1;

	merge_sort(left, mid);
	merge_sort(mid, right);

	int* temp = new int[right - left];

	for (int i = left, j = mid,k=0;k<right-left;++k) {
		if (i < mid && j >= right) {
			temp[k] = N[i];
			++i;
		}
		else if (j < right&&i >= mid) {
			temp[k] = N[j];
			++j;
		}
		else {
			if (N[i] > N[j])
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
	for (int i = 0; i < right-left; i++)
	{
		N[left+i] = temp[i];
	}

	delete temp;
	return;
}

int main()
{

	int T,n;
	scanf("%d%d", &T, &n);
	for (int i=0;i<n;i++)
	{
		scanf("%d", &N[i]);
	}

	merge_sort(0, n);
	long long sum = N[0];
	for (int i = 1; i < n; i++)
	{
		sum += N[i];
		N[i] = sum % 1000000007;
	}
	
	
	for (int k = 0; T > 0; T--)
	{
		scanf("%d", &k);
		if(k!=0&&k<=n)
		printf("%d\n", N[k - 1]);
		else if(k>n)printf("%d\n", N[n - 1]);
			else printf("0\n");
	}

	return 0;

}