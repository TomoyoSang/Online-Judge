#include <iostream>
#include <cstdio>

using namespace std;

int n, k;
int N[5000] = { 0 };
void Quicksort1(int left,int right)
{
	if (left == right)return;
	else if (left - right == 1)return;
	else
	{
		int tmp1 = left;
		int tmp2 = right;
		int key = N[left];
		while (left < right)
		{
			while (left < right&&N[right] >= key)
			{
				right--;
			}
			if (left < right)
			{
				N[left] = N[right];
				left++;
			}

			while (left < right&&N[left] <= key)
			{
				left++;
			}
			if (left < right)
			{
				N[right] = N[left];
				right--;
			}


		}
		N[left] = key;
		Quicksort1(tmp1, left);
		Quicksort1(left + 1, tmp2);
		return;
	}


}

int dp_data[5001][5001] = { 0 };

int dp(int pos, int remain) {
	if (pos >= n || remain <= 0)
		return 0;
	if (dp_data[pos][remain] > 0)
		return dp_data[pos][remain];
	int i;
	int ans1 = dp(pos + 1, remain), ans2 = 0;
	for (i = pos; i < n; ++i) {
		if (N[i] - N[pos] <= 5)
			++ans2;
		else
			break;
	}
	ans2 += dp(i, remain - 1);
	dp_data[pos][remain] = ans1 > ans2 ? ans1 : ans2;
	return dp_data[pos][remain];
}


int main()
{
	
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
	}

	Quicksort1(0,n-1);

	cout << dp(0, k);
	

	return 0;
}