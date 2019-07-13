#include <iostream>
using namespace std;
//#define endl '\n'




int N1[100000] = { 0 };
int N2[100000] = { 0 };





void  Quicksort(int* array1, int* array2, int left, int right)
{
	
	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	int key2 = array2[left];
	int key1 = array1[left];

	while (left < right)
	{
		
		
		while (left < right  &&array2[right] >= key2  )
		{
			right--;
		}
		if (left<right)
		{
			array2[left] = array2[right];
			array1[left] = array1[right];
			++left;
		}

		while (left < right &&array2[left] <= key2)
		{
			left++;
		}
		if (left<right)
		{
			array2[right] = array2[left];
			array1[right] = array1[left];
			--right;

		}
	

	}

	array2[left] = key2;
	array1[left] = key1;


	Quicksort(array1, array2, tmp1, left);
	Quicksort(array1, array2, left+1, tmp2);

	return;

}




int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	int n = 0;
	//cin >> n;
	scanf("%d", &n);
	int Class = 0;

	for (int i = 0; i < n; i++)
	{
		//cin >> N1[i] >> N2[i];
		scanf("%d%d", &N1[i], &N2[i]);
	}

	Quicksort(N1, N2, 0, n - 1);

	
	
	
	



	int Start = 0;
	int End = 1000001;
	
	int min = 0;
/*	while (flag)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
		{

			if (N1[i] >= Start && N2[i] <= End)
			{
				flag = 1;
				min = i;
				End = N2[i];
				break;
			}

		}

		if (End != 1000001)
		{
			Class++;
			End = 1000001;
			Start = N2[min];

		}

	}
*/

	for (int i = 0; i < n; i++)
	{
		if (N1[i] >= Start && N2[i] <= End)
		{
			Class++;
			Start = N2[i];


		}


	}
	//cout << Class;
	printf("%d", Class);
	return 0;
}




