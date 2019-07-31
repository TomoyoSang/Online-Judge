#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//»ØËÝ·¨

int N[60][60] = { 0 };
int dishes[60] = { 0 };
bool flag1 = 0;
bool ending = 0;
int n, m;
bool judge()
{
	for (int i = 0; i < m; ++i)
	{
		flag1 = 0;
		for (int j = 0; N[i][j] != 0; j++)
		{
			if (N[i][j] < 0)
			{
				if (!dishes[0 - N[i][j]])
				{
					flag1 = 1;
					break;
				}
					
			}
			else
			{
				if (dishes[N[i][j]])
				{
					flag1 = 1;
					break;
				}
			}
		}
		if (!flag1)return flag1;
	}
	return 1;
}
void random(int i)
{
	//if (ending)return;
	bool flag = 0;
	if (i == n + 1)
	{
		flag= judge();
		if (flag)
		{
			ending = 1;
			return;
		}
	}
		
	else
	{
		dishes[i] = 1;
		random(i + 1);
		//if (ending)return;
		dishes[i] = 0;
		random(i + 1);
	}

	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	
	char cur;
	for (; t > 0; --t)
	{
		memset(N, 0, sizeof(N));
		memset(dishes, 0, sizeof(dishes));
		
		cin >> n >> m;
		int j = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> N[i][j];
				cur = cin.get();
				if (cur == '\n')break;
			}
			
		}
		random(0);
		if (ending)cout << "Bingo!" << '\n';
		else cout << "Sigh..." << '\n';
		ending = 0;

	}
	return 0;
}