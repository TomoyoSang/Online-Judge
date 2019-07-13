#include <iostream>
#include <cstdio>
#define imod 2000000
using namespace std;

int N[4000009] = { 0 };
void ins(int num)
{
	N[num + imod] = 1;
	return;
}
void del(int num)
{
	N[imod + num] = 0;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		
		cin >> cur;
		N[cur + imod] = 1;
		
	}
	int ope_num = 0;
	int ope;
	int num;
	cin >> ope_num;
	for (; ope_num > 0; ope_num--)
	{
		cin >> ope >> num;
		if (ope == 0)del(num);
		else if (ope == 1)ins(num);
	}

	
	for (int i = 0; i <=4000000; ++i)
	{
		if (N[i] == 1)cout << i - imod << " ";
	}
	return 0;
	
}