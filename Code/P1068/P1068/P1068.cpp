#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int N[5003][2] = { 0 };
void Quicksort(int left, int right)
{
	if (left == right)return;
	if (left - right == 1)return;
	int key1 = N[left][0];
	int key2 = N[left][1];
	int tmp1 = left;
	int tmp2 = right;
	while (left < right)
	{
		while (left < right&&(N[right][1] < key2||(N[right][1]==key2&&N[right][0]>key1)))
		{
			right--;
		}
		if (left < right)
		{
			N[left][0] = N[right][0];
			N[left][1] = N[right][1];
			left++;
		}

		while (left < right&&(N[left][1] > key2||(N[left][1]==key2&&N[left][0]<key1)))
		{
			left++;
		}
		if (left < right)
		{
			N[right][1] = N[left][1];
			N[right][0] = N[left][0];
			right--;
		}


	}
	N[left][0] = key1;
	N[left][1] = key2;
	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	m = (int )(m * 1.5);
	for (int i = 0; i < n; ++i)
	{
		cin >> N[i][0] >> N[i][1];
	}

	Quicksort(0, n - 1);
	int key = N[m - 1][1]; 
	while (N[m][1] >= key)
	{
		m++;
	}
	cout << N[m - 1][1] << " " << m << "\n";
	for (int i = 0; i < m; ++i)
	{
		cout << N[i][0] << " " << N[i][1] << "\n";
	}
	

	return 0;

}