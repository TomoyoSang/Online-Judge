#include<iostream>

using namespace std;

void QuickSort(int* &array, int left, int right);
int PartSort(int* &array, int left, int right);


int main()
{
	int len;
	int *a, *b;
	cin >> len;
	a = new int[len];
	b = new int[len];

	int i = 0;
	int counter;
	for (counter = 0; counter < len; counter++)cin >> a[counter];
	for (counter = 0; counter < len; counter++)cin >> b[counter];

	QuickSort(a, 0, len-1);
	QuickSort(b, 0, len - 1);


	long long sum1 = 0,sum2=0;
	for (counter = 0; counter < len; counter++) { sum1 += (long long)a[counter] * (long long)b[counter]; sum2 += (long long)a[counter] * (long long)b[len - counter - 1]; }
	cout << sum1<<" "<<sum2;

	return 0;
}


void QuickSort(int* &array, int left, int right)
{
	if (left >= right)//表示已经完成一个组
	{
		return;
	}
	int index = PartSort(array, left, right);//枢轴的位置
	QuickSort(array, left, index - 1);
	QuickSort(array, index + 1, right);
}

int PartSort(int* &array, int left, int right)
{
	int& key = array[right];
	int tmp;
	while (left < right)
	{
		while (left < right && array[left] <= key)
		{
			++left;
		}
		while (left < right && array[right] >= key)
		{
			--right;
		}
		tmp = array[left]; array[left] = array[right]; array[right] = tmp;
	}
	tmp = array[left]; array[left] = key; key = tmp;
	return left;
}

