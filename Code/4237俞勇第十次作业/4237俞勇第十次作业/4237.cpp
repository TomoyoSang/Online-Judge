#include <iostream>
#include <cstdio>
#include <cmath>
#define imod 1000000007

using namespace std;

struct node
{
	long long val;
	long long left;
	long long right;
	long long tag;
	long long _pow;
};

node N[800005];

void build_tree(int l,int r,int root)
{
	N[root].left = l;
	N[root].right = r;
	if (r - l == 1)return;
	int mid = (l + r) / 2;
	build_tree(l, mid, root * 2);
	build_tree(mid , r, root * 2 + 1);
	return;
}


void push_down(int root)
{
	if (N[root].tag != 0)
	{
		N[root * 2].tag = N[root * 2].tag * 257 + N[root].tag;
		N[root * 2 + 1].tag = N[root * 2 + 1].tag * 257 + N[root].tag;
		N[root * 2]._pow++;
		N[root * 2 + 1]._pow++;
	}

	N[root * 2].val = N[root * 2].val *257 + N[root].tag*(N[2 * root].right - N[2 * root].left);
	N[root * 2 + 1].val = N[root * 2 + 1].val * 257 + N[root].tag*(N[2 * root+1].right - N[2 * root+1].left);
	N[root].tag = 0;
	return;
}
void update(int l, int r, long long tag, int root)
{
	if (l <= N[root].left&&N[root].right <= r)
	{
		N[root].tag = N[root].tag * 257 + tag;
		N[root].val = N[root].val * 257 + (N[root].right - N[root].left)*tag;
		return;
	}

	int mid = (N[root].left + N[root].right) >> 1;
	push_down(root);
	if (l < mid) {
		update(l, r, tag, root * 2);
	}
	if (r > mid) {
		update(l, r, tag, root * 2 + 1);
	}
	return;
}
int Find(int x,int root)
{
	if (N[root].left == N[root].right)return N[root].right;
	if (x != N[root].left)
	{
		push_down(root);
		int mid = (N[root].left + N[root].right) >> 1;
		if (x < mid)return Find(x, 2 * root);
		else return Find(x, 2 * root + 1);
	}
}
void query(int l,int r)
{
	int place1 = Find(l, 1);
	int place2 = Find(r, 1);
	if (N[place1].val == N[place2].val)
	{
		cout << "YES" << '\n';
		N[place1].val = 0;
		N[place2].val = 0;
	}
	else
	{
		cout << "NO" << '\n';
	}
}
long long n, m;
long long L, R, K;
long long X, Y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int ope = 0;
	build_tree(1, n + 1, 1);
	for (; m > 0; --m)
	{
		cin >> ope;
		if (!ope)
		{
			cin >> L >> R >> K;
			update(L, R + 1, K, 1);
		}
		else if (ope)
		{
			cin >> X >> Y;
			query(X, Y);
		}

	}
	return 0;

}