#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int M, T, U, F, D;
	cin >> M >> T >> U >> F >> D;
	int counter = 0;//最多能走的路程
	int up_and_down = U + D;//去时是上坡回来就是下坡，总用时就是上+下
	int plain = 2 * F;//平地来回为2*平地用时
	char* condition = new	char[1];//路况
	while (M > 0)
	{
		cin >> condition[0];
		if (condition[0] == 'u' || condition[0] == 'd')
		{
			M -= up_and_down;
		}
		else M -= plain;
		counter++;
	}
	if (M == 0)cout << 0;
	else cout << counter - 1;//最后M<0,多加了一次
	return 0;
}