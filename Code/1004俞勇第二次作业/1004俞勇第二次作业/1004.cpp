#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int M, T, U, F, D;
	cin >> M >> T >> U >> F >> D;
	int counter = 0;//������ߵ�·��
	int up_and_down = U + D;//ȥʱ�����»����������£�����ʱ������+��
	int plain = 2 * F;//ƽ������Ϊ2*ƽ����ʱ
	char* condition = new	char[1];//·��
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
	else cout << counter - 1;//���M<0,�����һ��
	return 0;
}