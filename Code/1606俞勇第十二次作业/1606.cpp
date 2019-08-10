#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

//我用的VS2019打开的
//VS2017可能会不过编

int counter = 0;
int num = 0;
int n, m;
int N[55][55] = { 0 };
int M[2500][2] = { 0 };
bool vis[55][55] = { 0 };
bool vis1[55][55] = { 0 };
void dfs1(int left, int right)
{
	vis1[left][right] = 1;
	if (N[left][right] == 0)counter++;
	if (left > 0 && N[left - 1][right] != -1 && vis1[left - 1][right] == 0)
	{
		dfs1(left - 1, right);
	}
	if (left < n-1 && N[left + 1][right] != -1 && vis1[left + 1][right] == 0)
	{
		dfs1(left + 1, right);
	}
	if (right > 0 && N[left][right - 1] != -1 && vis1[left][right - 1] == 0)
	{
		dfs1(left, right - 1);
	}
	if (right < m -1&& N[left][right + 1] != -1 && vis1[left][right + 1] == 0)
	{
		dfs1(left, right + 1);
	}
	return;
	
}
void dfs2(int left, int right)
{
	vis[left][right] = 1;
	if (N[left][right] == 0)counter++;
	if (left > 0 && N[left - 1][right] != -1 && vis[left - 1][right] == 0)
	{
		dfs2(left - 1, right);
	}
	if (left < n-1 && N[left + 1][right] != -1 && vis[left + 1][right] == 0)
	{
		dfs2(left + 1, right);
	}
	if (right > 0 && N[left][right - 1] != -1 && vis[left][right - 1] == 0)
	{
		dfs2(left, right - 1);
	}
	if (right < m-1 && N[left][right + 1] != -1 && vis[left][right + 1] == 0)
	{
		dfs2(left, right + 1);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	char cur;
	int counter1 = 0, counter2 = 0;
	
	int _stx, _sty;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> cur;
			if (cur == '#')N[i][j] = -1;
			else if (cur == '.')
			{
				_stx = i, _sty = j;
				N[i][j] = 0;
				counter1++;
			}
			
			else if (cur == '?')
			{
				N[i][j] = 1;
				M[counter2][0] = i;
				M[counter2][1] = j;
				counter2++;
			}
		}
	}



	
	dfs1(_stx, _sty);
	if (counter < counter1)
	{
		cout << "Impossible";
		return 0;
	}
	
	for (int i = 0; i < counter2; ++i)
	{
		if (!vis1[M[i][0]][M[i][1]])
			continue;
		memset(vis, 0, sizeof(vis));
		counter = 0;
		N[M[i][0]][M[i][1]] = -1;
		dfs2(_stx,_sty);
		N[M[i][0]][M[i][1]] = 1;
		if (counter == counter1)num++;
		if (num >= 1)
		{
			cout << "Ambiguous";
			return 0;
		}
		
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vis1[i][j] == 1)
			{
				cout << '.';
			}
			else cout << '#';
		}
		cout << "\n";
	}
	return 0;

}