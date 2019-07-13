#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int N[100005][4] = { 0 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> N[i][0] >> N[i][1] >> N[i][2] >> N[i][3];
	}

	int a, b;
	cin >> a >> b;
	for (; n > 0; --n)
	{
		if (N[n - 1][0] <= a && N[n - 1][1] <= b && N[n - 1][2] + N[n - 1][0] >= a && N[n - 1][3] + N[n - 1][1] >= b)
		{
			cout << n;
			//system("pause");
			return 0;
		}
	}
	cout << -1;
	//system("pause");
	return 0;
}