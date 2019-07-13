#include <iostream>
#include<cstring>

using namespace std;

#define MAX 1000001
struct node
{
	node* next;
	char data;

};

void place(char*, node*);
void nodeplus(node*, node*, node*);

char seq1[MAX];
char seq2[MAX];
char seq3[MAX];

int main()
{

	cin >> seq1;
	cin >> seq2;

	node *head1=new node, *head2=new node, *head3=new node;

	place(seq1, head1);
	place(seq2, head2);

	nodeplus(head1, head2, head3);

	int k=0,num = strlen(seq3);
	for (k = num - 1; k >= 0; k--)cout << seq3[k];

	return 0;
}



void place(char*s, node*head)
{
	int m = strlen(s), i;
	head->next = NULL;

	for (i = 0; i < m; i++)
	{
		node *q=new node;
		q->next = NULL;
		q->data = s[i];

		q->next = head->next;
		head->next = q;
		
		
	}
}


void nodeplus(node *head1,node *head2,node* head3)
{
	node *p1, *p2,*p3;
	p1 = head1;
	p2 = head2;
	p3 = head3;

	int i = 0, j = 0, extra = 0, tmp = 0;
	while ((p1->next != NULL) && (p2->next != NULL))
	{
		node *q=new node;
		p3->next = q;
		p1 = p1->next;
		p2 = p2->next;
		p3 = p3->next;
		tmp = p1->data - '0' + p2->data - '0' + extra;
		if (tmp > 9) { tmp -= 10; extra=1; }
		else extra = 0;
		p3->data = (tmp + '0');
		seq3[i] = p3->data;
		i++;
	

	}


	if (p1->next == NULL)
	{
		while (p2->next != NULL) {
			node *q=new node;
			p3->next = q;
			p2 = p2->next;
			p3 = p3->next;
			tmp = p2->data - '0' + extra;
			if (tmp > 9) { tmp -= 10; extra = 1; }
			else extra = 0;
			p3->data = (tmp + '0');
			seq3[i] = p3->data;
			i++; 
			

		}
		
	}

	else {
		while (p1->next != NULL)
		{
			node *q=new node;
			p3->next = q;
			p1 = p1->next;
			p3 = p3->next;
			tmp = p1->data - '0' + extra;
			if (tmp > 9) { tmp -= 10; extra = 1; }
			else extra = 0;
			p3->data = (tmp + '0');
			seq3[i] = p3->data;
			i++;
			
		}
		

		
		
	}

	if (extra == 1)
	{
		node *q = new node;
		p3->next = q;
		p3 = p3->next;
		p3->data = '1';
		p3->next = NULL;
		seq3[i] = p3->data;
	}




}
