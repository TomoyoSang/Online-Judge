#include <iostream>

using namespace std;

void QuickSort(int* array, int *directions,int left, int right);
int PartSort(int* array,int *directions, int left, int right);

int main()
{
	// ‰»Î£∫
	int N = 0;
	int L = 0;
	scanf("%d", &N);
	scanf("%d", &L);

	int i = 0, *places, *directions;
	places = new int[N];
	directions = new int[N];
	for (i = 0; i < N; i++)
	{
		scanf("%d", &places[i]);
		directions[i] = ((i +1)% 2);

	}



	int mintime = 0, maxtime = 0;


	int  left0 = L;
		int left1 = 0;
	int right0 = 0;
	int right1 = L;
	for (i = 0; i < N; i++)
	{
		if (directions[i] == 0)
		{
			if (places[i] < left0)left0 = places[i];
			if (places[i] > right0)right0 = places[i];
		}
		if (directions[i] == 1)
		{
			if (L - places[i] > left1)left1 = L - places[i];
			if (L - places[i] < right1)right1 = L - places[i];
		}
		mintime = (left0 < right1) ? left0 : right1;
		maxtime = (left1 < right0) ? right0 : left1;
	}


	printf("%d %d",mintime, maxtime);

	return 0;






}