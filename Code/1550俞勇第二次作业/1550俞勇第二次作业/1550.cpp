#include <iostream>

using namespace std;

//从左到由右（左>右）+从右到左（右>左）+水平

int main()
{
	int sum = 0;
	int n = 0;
	cin >> n;
	int* height;
	height = new int[n];
	int i = 0;
	char s;
	s = cin.get();
	while (s != '[')s = cin.get();
	for (i = 0; i < n; i++)
	{
		if (i != 0)s = cin.get();
		cin >> height[i];

	}
	cin.get();

	//完成输入

	int j = 0, k = 0;
	i = 0;

	while (i < n)
	{
		j = i + 1;
		while ((height[j] <= height[i]) && (j < n))
		{
			j++;

		}
		if (j >= n)break;
		//i++;
		else
		{
			for (k = i + 1; k < j; k++)
			{
				sum += height[i] - height[k];
			}
			i = j;
		}


	}


	i = n - 1;
	j = i - 1;

	while (i > 0)
	{
		j = i - 1;
		while ((height[j] < height[i]) && (j >= 0))
		{
			j--;

		}
		if (j < 0)break;
		else
		{
			for (k = i - 1; k > j; k--)
			{
				sum += height[i] - height[k];
			}
			i = j;
		}



	}




	cout << sum;
	return 0;

}