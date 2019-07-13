#include "iostream"
#include "cstring"
using namespace std;

class bst {
public:
	class node {
	public:
		int _value = 0;
		node* left_child = NULL, *right_child = NULL;
		node* father = NULL;
	};

	class iterator {
	public:
		node* cur_pos = NULL;

		//重载++i
		iterator& operator++() {
			if (cur_pos == NULL)
				return *this;
			//假如有右孩子
			if (cur_pos->right_child != NULL) {
				for (cur_pos = cur_pos->right_child; cur_pos->left_child != NULL;)
					cur_pos = cur_pos->left_child;
			}
			//假如是落单的根节点
			else if (cur_pos->father == NULL) {
				cur_pos = NULL;
			}
			//假如是左叶子
			else if (cur_pos->father->left_child == cur_pos)
				cur_pos = cur_pos->father;
			//假如是右叶子
			else {
				auto last = cur_pos;
				for (cur_pos = cur_pos->father;
					cur_pos != NULL && cur_pos->right_child == last;
					cur_pos = cur_pos->father)
					last = cur_pos;
			}
			return *this;
		}

		//重载i++
		iterator operator++(int) {
			auto tmp = *this;
			if (cur_pos == NULL)
				return tmp;
			//假如有右孩子
			if (cur_pos->right_child != NULL) {
				for (cur_pos = cur_pos->right_child; cur_pos->left_child != NULL;)
					cur_pos = cur_pos->left_child;
			}
			//假如是落单的根节点
			else if (cur_pos->father == NULL) {
				cur_pos = NULL;
			}
			//假如是左叶子
			else if (cur_pos->father->left_child == cur_pos)
				cur_pos = cur_pos->father;
			//假如是右叶子
			else {
				auto last = cur_pos;
				for (cur_pos = cur_pos->father;
					cur_pos != NULL && cur_pos->right_child == last;
					cur_pos = cur_pos->father)
					last = cur_pos;
			}
			return tmp;
		}

		bool operator==(const iterator& other) {
			return cur_pos == other.cur_pos;
		}

		bool operator!=(const iterator& other) {
			return cur_pos != other.cur_pos;
		}

		int& operator*() {
			return cur_pos->_value;
		}
	};

	node* rooter = NULL;

	iterator begin() {
		iterator tmp;
		auto p = rooter;
		for (; p->left_child; p = p->left_child);
		tmp.cur_pos = p;
		return tmp;
	}

	iterator end() {
		iterator tmp;
		tmp.cur_pos = NULL;
		return tmp;
	}

	iterator search(const int& _value) {
		iterator ans;
		int length = 0;
		for (auto p = rooter; p;) {
			if (p->_value == _value) {
				ans.cur_pos = p;
				return ans;
			}
			else if (_value < p->_value) {
				p = p->left_child;
			}
			else {
				p = p->right_child;
			}
		}
		ans.cur_pos = NULL;
		return ans;
	}

	void ins_val(const int& _value) {
		if (!rooter) {
			rooter = new node;
			rooter->_value = _value;
			return;
		}
		//寻找
		auto p = rooter;
		for (; p;) {
			if (p->_value == _value) {
				//统一插入右子树
				if (p->right_child) {
					p->right_child->father = new node;
					p->right_child->father->_value = _value;
					p->right_child->father->right_child = p->right_child;
					p->right_child = p->right_child->father;
					p->right_child->father = p;
				}
				else {
					p->right_child = new node;
					p->right_child->_value = _value;
					p->right_child->father = p;
				}
				return;
			}
			if (_value < p->_value) {
				if (p->left_child)
					p = p->left_child;
				else {
					p->left_child = new node;
					p->left_child->father = p;
					p = p->left_child;
					break;
				}
			}
			else {
				if (p->right_child)
					p = p->right_child;
				else {
					p->right_child = new node;
					p->right_child->father = p;
					p = p->right_child;
					break;
				}
			}
		}
		//增加
		p->_value = _value;
	}

	iterator erase(const iterator& pos) {
		iterator ans = pos;
		auto p = pos.cur_pos;
		//如果是叶子结点则直接删除
		if (!p->left_child && !p->right_child) {
			++ans;
			if (p == rooter)
				rooter = NULL;
			else if (p->father->left_child == p)
				p->father->left_child = NULL;
			else
				p->father->right_child = NULL;
			delete p;
		}
		//如果只有左孩子
		else if (p->left_child && !p->right_child) {
			++ans;
			if (p == rooter) {
				rooter = p->left_child;
				p->left_child->father = NULL;
			}
			else if (p->father->left_child == p) {
				p->father->left_child = p->left_child;
				p->left_child->father = p->father;
			}
			else {
				p->father->right_child = p->left_child;
				p->left_child->father = p->father;
			}
			delete p;
		}
		//如果有右孩子
		else if (p->right_child) {
			auto q = p->right_child;
			for (; q->left_child; q = q->left_child);
			p->_value = q->_value;
			if (q->father->left_child == q)
				q->father->left_child = q->right_child;
			else
				q->father->right_child = q->right_child;
			if (q->right_child)
				q->right_child->father = q->father;
			delete q;
		}
		return ans;
	}

	void erase(const int& _value) {
		auto p = rooter;
		for (; p;) {
			if (p->_value == _value) {
				//如果是叶子结点则直接删除
				if (!p->left_child && !p->right_child) {
					if (p == rooter)
						rooter = NULL;
					else if (p->father->left_child == p)
						p->father->left_child = NULL;
					else
						p->father->right_child = NULL;
					delete p;
				}
				//如果只有左孩子
				else if (p->left_child && !p->right_child) {
					if (p == rooter) {
						rooter = p->left_child;
						p->left_child->father = NULL;
					}
					else if (p->father->left_child == p) {
						p->father->left_child = p->left_child;
						p->left_child->father = p->father;
					}
					else {
						p->father->right_child = p->left_child;
						p->left_child->father = p->father;
					}
					delete p;
				}
				//如果有右孩子
				else if (p->right_child) {
					auto q = p->right_child;
					for (; q->left_child; q = q->left_child);
					p->_value = q->_value;
					if (q->father->left_child == q)
						q->father->left_child = q->right_child;
					else
						q->father->right_child = q->right_child;
					if (q->right_child)
						q->right_child->father = q->father;
					delete q;
				}
				return;
			}
			else if (_value < p->_value)
				p = p->left_child;
			else
				p = p->right_child;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bst i_bst;

	int num;
	cin >> num;
	for (; num > 0; num--) {
		char op[100];
		cin >> op;
		if (strcmp(op, "insert") == 0) {
			int tmp;
			cin >> tmp;
			i_bst.ins_val(tmp);
		}
		else if (strcmp(op, "delete") == 0) {
			int tmp;
			cin >> tmp;
			if (auto iter = i_bst.search(tmp); iter != i_bst.end())
				i_bst.erase(iter);
		}
		else if (strcmp(op, "delete_less_than") == 0) {
			int tmp;
			cin >> tmp;
			for (auto p = i_bst.begin(); p != i_bst.end(); ) {
				if (*p < tmp) {
					p = i_bst.erase(p);
				}
				else break;
			}
		}
		else if (strcmp(op, "delete_greater_than") == 0) {
			int tmp;
			cin >> tmp;
			for (auto p = i_bst.begin(); p != i_bst.end(); ) {
				if (*p > tmp) {
					p = i_bst.erase(p);
				}
				else ++p;
			}
		}
		else if (strcmp(op, "delete_interval") == 0) {
			int l, r;
			cin >> l >> r;
			for (auto p = i_bst.begin(); p != i_bst.end();) {
				if (*p > l && (*p) < r)
					p = i_bst.erase(p);
				else if (*p >= r)
					break;
				else ++p;
			}
		}
		else if (strcmp(op, "find") == 0) {
			int tmp;
			cin >> tmp;
			if (i_bst.search(tmp) != i_bst.end())
				cout << "Y" << endl;
			else cout << "N" << endl;
		}
		else if (strcmp(op, "find_ith") == 0) {
			int tmp;
			bool flag = false;
			cin >> tmp;
			int i = 1;
			for (auto p = i_bst.begin(); p != i_bst.end(); ++p, ++i) {
				if (i == tmp) {
					flag = true;
					cout << *p << endl;
					break;
				}
			}
			if (!flag)
				cout << "N" << endl;
		}
	}


	return 0;
}