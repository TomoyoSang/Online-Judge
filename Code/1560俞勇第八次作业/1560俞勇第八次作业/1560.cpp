#include "iostream"

#include "cstdio"

#include "cstring"

#include "cmath"

using namespace std;



char ans[100009] = { 0 };



class bst {

public:

	class node {

	public:

		int _value = 0;

		node* left_child = nullptr, *right_child = nullptr;

		node* parent = nullptr;

	};

	node* rooter = nullptr;



	void find(const int& _value) {

		memset(ans, 0, sizeof(ans));

		int length = 0;

		ans[length++] = '*';

		for (auto p = rooter; p;) {

			if (p->_value == _value) {

				printf("%s\n", ans);

				return;

			}

			else if (_value < p->_value) {

				ans[length++] = 'l';

				p = p->left_child;

			}

			else {

				ans[length++] = 'r';

				p = p->right_child;

			}

		}

		printf("Nothing.\n");

	}



	void insert(const int& _value) {

		if (!rooter) {

			rooter = new node;

			rooter->_value = _value;

			return;

		}

		//寻找

		auto p = rooter;

		for (; p;) {

			if (p->_value == _value)

				return;

			if (_value < p->_value) {

				if (p->left_child)

					p = p->left_child;

				else {

					p->left_child = new node;

					p->left_child->parent = p;

					p = p->left_child;

					break;

				}

			}

			else {

				if (p->right_child)

					p = p->right_child;

				else {

					p->right_child = new node;

					p->right_child->parent = p;

					p = p->right_child;

					break;

				}

			}

		}

		//增加

		p->_value = _value;

	}



	void erase(const int& _value) {

		auto p = rooter;

		for (; p;) {

			if (p->_value == _value) {

				//如果是叶子结点则直接删除

				if (!p->left_child && !p->right_child) {

					if (p == rooter)

						rooter = nullptr;

					else if (p->parent->left_child == p)

						p->parent->left_child = nullptr;

					else

						p->parent->right_child = nullptr;

					delete p;

				}

				//如果只有左孩子

				else if (p->left_child && !p->right_child) {

					if (p == rooter) {

						rooter = p->left_child;

						p->left_child->parent = nullptr;

					}

					else if (p->parent->left_child == p) {

						p->parent->left_child = p->left_child;

						p->left_child->parent = p->parent;

					}

					else {

						p->parent->right_child = p->left_child;

						p->left_child->parent = p->parent;

					}

					delete p;

				}

				//如果有右孩子

				else if (p->right_child) {

					auto q = p->right_child;

					for (; q->left_child; q = q->left_child);

					p->_value = q->_value;

					if (q->parent->left_child == q)

						q->parent->left_child = q->right_child;

					else

						q->parent->right_child = q->right_child;

					if (q->right_child)

						q->right_child->parent = q->parent;

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



bst my_bst;



int main() {

	int n;

	scanf("%d", &n);



	for (int i = 0; i < n; ++i) {

		char op;

		int temp;

		scanf("\n%c %d", &op, &temp);

		if (op == '+') {

			my_bst.insert(temp);

		}

		else if (op == '-') {

			my_bst.erase(temp);

		}

		else {

			my_bst.find(temp);

		}

	}



	return 0;

}