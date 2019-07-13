#include <iostream>
#include <cstdio>

using namespace std;

int X = 0, Y = 0;
int N;
int my_map[102	0][1020] = { 0 };
int leftmax = -500, rightmax = -500, leftmin = 500, rightmin = 500;



int imax(int left, int right)
{
	return (left < right) ? right : left;
}

int imin(int left, int right)
{
	return (left < right) ? left : right;
}

void my_pace(int left, int right, int counter)
{
	if (my_map[left][right] == -1)return;
	else if (my_map[left][right] == 0|| my_map[left][right] > counter)my_map[left][right] = counter;
	else if (my_map[left][right] <= counter)return;
	
	if (left > leftmin)my_pace(left - 1, right, counter + 1);
	if (left < leftmax)my_pace(left + 1, right, counter + 1);
	if (right > rightmin)my_pace(left, right - 1, counter + 1);
	if (right < rightmax)my_pace(left, right + 1, counter + 1);
	return;
}

int main()
{
	scanf("%d%d", &X, &Y);
	scanf("%d", &N);
	int x1 = 0, y1 = 0;
	for (int i=0;i<N;i++)
	{
		scanf("%d %d", &x1, &y1);
		leftmax = imax(x1, leftmax);
		leftmin = imin(x1, leftmin);
		rightmax = imax(y1, rightmax);
		rightmin = imin(y1, rightmin);
		my_map[500 + x1][500 + y1] = -1;
	}
	
	if (leftmax < 500)leftmax++;
	if (leftmin > -500)leftmin--;
	if (rightmax < 500)rightmax++;
	if (rightmin > -500)rightmin--;
	leftmax += 500;
	leftmin += 500;
	rightmax += 500;
	rightmin += 500;

	my_pace(500,500,0);
	printf("%d", my_map[500+X][500+Y]);
	return 0;


}