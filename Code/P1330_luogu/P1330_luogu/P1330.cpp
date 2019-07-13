#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct node
{
	node* next = NULL;
	int cur_num;
	bool fuck = 0;
};
node* nodelist[10005];
int inDegree[10005][2] = { 0 };
int n, m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		insert(a, b);
	}

	Quicksort(0, n - 1);
	

	for (int i = 0; i < n; ++i)
	{
		if(nodelist[inDegree[i][0]]->fuck==0)
	}


}