#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;
//不知为什么有时候会莫名的被卡一个数据

long long n, m;
long long N[100005] = { 0 };
long long line_tree[400005][4] = { 0 };
long long sum = 0;


class node {
public:
	int left = 0, right = 0;
	long long val = 0;
	long long tag = 0;
};

node smt[400009];

void build_tree(int l, int r, int root) {
	smt[root].left = l;
	smt[root].right = r;
	if (l == r - 1) {
		smt[root].val = N[l];
		return;
	}
	int mid = (l + r) >> 1;
	build_tree(l, mid, root * 2);
	build_tree(mid, r, root * 2 + 1);
	smt[root].val = smt[root * 2].val + smt[root * 2 + 1].val;
}

void push_down(int root) {
	smt[root * 2].tag += smt[root].tag;
	smt[root * 2 + 1].tag += smt[root].tag;
	smt[root * 2].val += smt[root].tag*(smt[root * 2].right - smt[root * 2].left);
	smt[root * 2 + 1].val += smt[root].tag*(smt[root * 2 + 1].right - smt[root * 2 + 1].left);
	smt[root].tag = 0;
}

void update(int l, int r,long long val, int root) {
	if (l <= smt[root].left&&smt[root].right <= r) {
		smt[root].tag += val;
		smt[root].val += (long long)(smt[root].right - smt[root].left)*val;
		return;
	}
	int mid = (smt[root].left + smt[root].right) >> 1;
	push_down(root);
	if (l < mid) {
		update(l, r, val, root * 2);
	}
	if (r > mid) {
		update(l, r, val, root * 2 + 1);
	}
	smt[root].val = smt[root * 2].val + smt[root * 2 + 1].val;
}

long long query(int l, int r, int root) {
	if (l <= smt[root].left&&smt[root].right <= r) {
		return smt[root].val;
	}
	int mid = (smt[root].left + smt[root].right) >> 1;
	push_down(root);
	long long ans = 0;
	if (l < mid) {
		ans += query(l, r, root * 2);
	}
	if (r > mid) {
		ans += query(l, r, root * 2 + 1);
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> N[i];
	}

	build_tree(1, n+1, 1);

	char s = 0;
	long long a, b;
	long long c;
	long long d = 0;
	for (; m > 0; --m)
	{
		cin >> s;

		if (s == 'Q')
		{
			cin >> a >> b;
			sum = query(a, b+1,1);
			cout << sum << endl;
			sum = 0;
		}
		else if (s == 'C')
		{
			cin >> a >> b >> c;
			update(a,b+1,c,1);
		}
	}



	return 0;
}