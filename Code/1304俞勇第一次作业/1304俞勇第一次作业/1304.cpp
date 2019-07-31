#include <iostream>

using namespace std;

//这道题看懂的话其实很简单
//只要明白质量相同的两颗球相撞，不考虑序号变化的话，就相当于互不影响的穿过去
//所以现在就变成了一道小学数学题
int main()
{
	//输入：
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