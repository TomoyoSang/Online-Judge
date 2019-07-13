#include <iostream>
#include <cstdio>
using namespace std;

int counter = 0;
struct node
{
	node* next = NULL;
	int elem ;
};
node* head;
void insert()
{
	int _val = 0;
	scanf("%d", &_val);
	node* p = head;
	while (p->next != NULL)
	{
		if (p->next->elem > _val)
		{
			p = p->next;
			counter++;
		}
		else break;
	}
	node* q = new node;
	q->elem = _val;
	q->next = p->next;
	p->next = q;
	return;
}
int main()
{
	int n;
	head = new node;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		insert();
	}
	printf("%d", counter);
	
	return 0;
}