#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int N[320][3] = { 0 };

void merge_sort(int left, int right)
{
	if (left - right == -1)return;
	if (left == right)return;
	

	int mid = (left + right) / 2;
	merge_sort(left, mid);
	merge_sort(mid, right);

	int** nums = new int*[right - left];
	for (int i = 0; i < right - left; ++i)
	{
		nums[i] = new int[3];
	}

	int tmp1 = left, tmp2 = mid;
	int counter = 0;
	while (counter < right - left)
	{
		if (tmp1>=mid&&tmp2<right)
		{
			nums[counter][0] = N[tmp2][0];
			nums[counter][1] = N[tmp2][1];
			nums[counter][2] = N[tmp2][2];
			counter++;
			tmp2++;
		}
		else if (tmp1 < mid&&tmp2 >= right)
		{
			nums[counter][0] = N[tmp1][0];
			nums[counter][1] = N[tmp1][1];
			nums[counter][2] = N[tmp1][2];
			counter++;
			tmp1++;
		}

		else
		{
			if (N[tmp1][2] < N[tmp2][2])
			{
				nums[counter][0] = N[tmp2][0];
				nums[counter][1] = N[tmp2][1];
				nums[counter][2] = N[tmp2][2];
				counter++;
				tmp2++;
			}
			else if(N[tmp1][2] > N[tmp2][2])
			{
				nums[counter][0] = N[tmp1][0];
				nums[counter][1] = N[tmp1][1];
				nums[counter][2] = N[tmp1][2];
				counter++;
				tmp1++;
			}
			else if (N[tmp1][1] < N[tmp2][1])
			{
				nums[counter][0] = N[tmp2][0];
				nums[counter][1] = N[tmp2][1];
				nums[counter][2] = N[tmp2][2];
				counter++;
				tmp2++;
			}
			else 
			{
				nums[counter][0] = N[tmp1][0];
				nums[counter][1] = N[tmp1][1];
				nums[counter][2] = N[tmp1][2];
				counter++;
				tmp1++;
			}
			


		}
	}

	for (int i = 0; i < right-left; ++i)
	{
		N[left + i][0] = nums[i][0];
		N[left + i][1] = nums[i][1];
		N[left + i][2] = nums[i][2];
	}
	for (int i = 0; i < right - tmp1; ++i)
	{
		delete[]nums[i];
	}
	delete[]nums;
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		N[i][2] = a + b + c;
		N[i][1] = a * 1000 + 300 - i - 1;
		N[i][0] = i+1;
	}

	
	merge_sort(0, n);
	
	for (int i = 0; i < 5; ++i)
	{
		cout << N[i][0] << " " << N[i][2] << "\n";
	}
	system("pause");
	return 0;
}