#include <iostream>
#include <cstdio>

using namespace std;


int fraction[20000][2] = { 0 };
double f_value[20000] = { 0 };

void  Quicksort(int left, int right)
{

	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	double key2 = f_value[left];
	int key1 = fraction[left][0];
	int key3 = fraction[left][1];

	while (left < right)
	{


		while (left < right  &&f_value[right] >= key2)
		{
			right--;
		}
		if (left < right)
		{
			f_value[left] = f_value[right];
			fraction[left][0] = fraction[right][0];
			fraction[left][1] = fraction[right][1];
			++left;
		}

		while (left < right &&f_value[left] <= key2)
		{
			left++;
		}
		if (left < right)
		{
			f_value[right] = f_value[left];
			fraction[right][0] = fraction[left][0];
			fraction[right][1] = fraction[left][1];
			--right;

		}


	}

	f_value[left] = key2;
	fraction[left][0] = key1;
	fraction[left][1] = key3;


	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);

	return;

}

int main()
{
	int N;
	scanf("%d", &N);

	int i = 1;
	int counter = 1;
	while (i <= N)
	{
		for (int j = 1; j < i; j++)
		{
			fraction[counter][0] = j;
			fraction[counter][1] = i;
			f_value[counter] = double(j) / i;
			counter++;
		}

		i++;
	}

	fraction[0][0] = 0;
	fraction[0][1] = 1;
	fraction[counter][0] = 1;
	fraction[counter][1] = 1;
	f_value[counter] = 1;


	Quicksort(0, counter);
	double values = 0;
	int left = 0, right = 0;

	for (i = 0; i <= counter; i++)
	{
		if (f_value[i] != f_value[i + 1])
		{
			printf("%d", fraction[i][0]);
			printf("/");
			printf("%d\n", fraction[i][1]);
		}

		else if (f_value[i] == f_value[i + 1])
		{
			values = f_value[i];
			left = fraction[i][0];
			right = fraction[i][1];
			while (values == f_value[i + 1])
			{
				if (right > fraction[i + 1][1])
				{
					left = fraction[i + 1][0];
					right = fraction[i + 1][1];
				}
				i++;
			}
			printf("%d", left);
			printf("/");
			printf("%d\n", right);


		}


	}

	return 0;
}