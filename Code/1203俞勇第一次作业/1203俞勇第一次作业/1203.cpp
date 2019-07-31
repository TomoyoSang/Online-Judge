#include <iostream>
#include<cstring>
using namespace std;

//Á´±í
template <class type>
class link
{
private:
	
	
	struct node
	{
		type data;
		node* next=nullptr;
		node( ) { };
		~node()  {};

	};
	node* head;
	int amount;

public:
	link(int num=0)
	{
		head =new node ;
		amount = num;

	}
	~link() {};
	
	friend link<type> operator +( link<type> &a,  link<type> &b ) {
		node *n;
		n = a.head;
		while (n->next != NULL) { n = n->next; }
		n->next = b.head->next;
		return a;

	}

	
	link<type> operator =(link<type> &a) {
		head = a.head;
		return *this;

	}

	void input(type*s)
	{
		int len = amount;
		int i = 0;
		node *p;
		p = head;
		for (i = 0; i < len; i++)
		{
			node* n=new node;
			n->data = s[i];
			p->next = n;
			p = p->next;
		}
		p->next = NULL;

	}

	void output()
	{
		int i = 0;
		node* p;
		p = head;

		while (p->next != NULL)
		{
			p = p->next;
			if (i != 0)cout << " ";
			i++;
			cout << p->data;
			
			
		}


	}
	




};

int main()
{
	int n = 0, m = 0, i = 0;
	char* itype=new char [8];
	cin >> itype;
	
	cin >> n >> m;
	


	if (strcmp(itype, "int")==0)
	{
		link <int> type1(n),type2(m);

		int i=0;
		int* s1, *s2;
		s1 = new int[n];
		s2 = new int[m];

		for (i = 0; i < n; i++) { cin >> s1[i]; }
 		for (i = 0; i < m; i++) { cin >> s2[i]; }

		type1.input(s1);
		type2.input(s2);
		
		
		 type1 + type2;
		type1.output();

	}
	
	if (strcmp(itype, "char")==0)
	{
		link <char> type1(n), type2(m);

		int i = 0;
		char* s1, *s2;
		s1 = new char[n + 1];
		s2 = new char[m + 1];

		for (i = 0; i < n; i++) { cin >> s1[i]; }
		for (i = 0; i < m; i++) { cin >> s2[i]; }

		type1.input(s1);//cin>>type1;
		type2.input(s2);

		
		type1 + type2;
		type1.output();
	}

	if (strcmp(itype, "double")==0)
	{
		link <double> type1(n), type2(m);

		int i = 0;
		double* s1, *s2;
		s1 = new double[n + 1];
		s2 = new double[m + 1];

		for (i = 0; i < n; i++) { cin >> s1[i]; }
		for (i = 0; i < m; i++) { cin >> s2[i]; }

		type1.input(s1);
		type2.input(s2);

		
		type1 + type2;
		type1.output();

	}

	return 0;

}