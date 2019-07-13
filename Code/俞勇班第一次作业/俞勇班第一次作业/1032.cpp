#include<iostream>
using namespace std;

int Ackerman(int, int);
int main()
{
	int m, n;
	cin >> m >> n;
	int Acker = Ackerman(m, n);
	cout << Acker;

	return 0;
}

int Ackerman(int m, int n)
{
	if (m == 0)return n + 1;
	if ((m != 0) && (n == 0))
	{
		return Ackerman(m - 1, 1);
	}

	if ((m != 0) && (n != 0))return Ackerman(m-1, Ackerman(m, n-1));


}