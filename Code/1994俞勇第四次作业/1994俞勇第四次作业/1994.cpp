#include <iostream>
#include <cstdio>

using namespace std;

//BFS
int n = 0, m = 0;
int my_map[520][520] = { 0 };
void own_place(int left,int right)
{
	if(my_map[left][right] == 0)
	my_map[left][right] = 1;
	else return;
	if (left > 0)own_place(left - 1, right);
	if (left < n - 1)own_place(left + 1, right);
	if (right > 0)own_place(left, right - 1);
	if (right < m - 1)own_place(left, right + 1);
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d",&my_map[i][j]);
		}
	}
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (my_map[i][j] == 0)
			{
				own_place(i,j);
				counter++;
			}

		}
	}
	printf("%d", counter);

	return 0;
}