#include "iostream"
#include "cstdio"
#include "cmath"
#include "cstring"
using namespace std;

class my_lca {
public:
	int go = 0;
	my_lca* next = nullptr;
};

class tree_node {
public:
	int parent = 0;
	int _dep = 0;
	int par[24] = { 0 };
	my_lca* _left = nullptr, * _right = nullptr;
};

tree_node tree_info[100009];
int root_pos = 0;

void dfs(int pos) {
	if (pos == root_pos) {
		tree_info[pos]._dep = 0;
	}
	else {
		tree_info[pos]._dep = tree_info[tree_info[pos].parent]._dep + 1;
		int k = (int)(log(tree_info[pos]._dep) / log(2));
		tree_info[pos].par[0] = tree_info[pos].parent;
		for (int i = 1; i <= k; ++i) {
			tree_info[pos].par[i] = tree_info[tree_info[pos].par[i - 1]].par[i - 1];
		}
	}
	for (auto p = tree_info[pos]._left->next; p; p = p->next) {
		if (p->go != tree_info[pos].parent) {
			tree_info[p->go].parent = pos;
			dfs(p->go);
		}
	}
}

int LCA(int pos1, int pos2) {
	while (tree_info[pos1]._dep < tree_info[pos2]._dep) {
		int k = int(log(tree_info[pos2]._dep - tree_info[pos1]._dep) / log(2));
		pos2 = tree_info[pos2].par[k];
	}
	while (tree_info[pos2]._dep < tree_info[pos1]._dep) {
		int k = int(log(tree_info[pos1]._dep - tree_info[pos2]._dep) / log(2));
		pos1 = tree_info[pos1].par[k];
	}
	while (pos1 != pos2) {
		int k = int(log(tree_info[pos1]._dep) / log(2));
		for (int i = k; i >= 0; --i) {
			if (i == 0 || tree_info[pos1].par[i] != tree_info[pos2].par[i]) {
				pos1 = tree_info[pos1].par[i];
				pos2 = tree_info[pos2].par[i];
			}
		}
	}
	return pos1;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		tree_info[i]._right = tree_info[i]._left = new my_lca;
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		tree_info[u]._right->next = new my_lca;
		tree_info[u]._right = tree_info[u]._right->next;
		tree_info[u]._right->go = v;

		tree_info[v]._right->next = new my_lca;
		tree_info[v]._right = tree_info[v]._right->next;
		tree_info[v]._right->go = u;
	}

	root_pos = 1;
	dfs(1);

	int q;
	cin >> q;

	for (; q > 0; --q) {
		int u, v, w;
		cin >> u >> v >> w;
		int lca1 = LCA(u, v), lca2 = LCA(u, w), lca3 = LCA(v, w);
		if (tree_info[lca1]._dep < tree_info[lca2]._dep) {
			if (tree_info[lca3]._dep > tree_info[lca2]._dep) {
				cout << lca3 << "\n";
			}
			else {
				cout << lca2 << "\n";
			}
		}
		else {
			if (tree_info[lca3]._dep > tree_info[lca1]._dep) {
				cout << lca3 << "\n";
			}
			else {
				cout << lca1 << "\n";
			}
		}
	}

	return 0;
}