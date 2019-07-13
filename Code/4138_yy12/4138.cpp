#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n, m;
int members[106][20] = { 0 };
int num_mem[106] = { 0 };
int _plus_[106] = { 0 };
double max_eff = 0;
int _possibles[20] = { 0 };
int counter = 0;

void _judge()
{
	double cur = 0;
	bool flag = 1;
	for (int i = 0; i < m; ++i)
	{
		flag = 1;
		for (int j = 0; j < num_mem[i]; ++j)
		{
			
			if (_possibles[members[i][j]] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)cur += _plus_[i];

	}
	if(counter!=0)
	cur /= counter;
	max_eff = (cur > max_eff) ? cur : max_eff;
	return;

}
void _random(int i)
{
	if (i == n )
	{
		_judge();
	}

	else
	{
		_possibles[i] = 1;
		counter++;
		_random(i + 1);
		_possibles[i] = 0;
		counter--;
		_random(i + 1);
	}
	return;

}
int main()
{
	cin >> n >> m;
	int cur = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> num_mem[i];
		

	    cin >> _plus_[i];
		for (int j = 0; j < num_mem[i]; ++j)
		{
			cin >> members[i][j];
		}
	}

	_random(0);

	printf("%.2f", max_eff);
	return 0;
}