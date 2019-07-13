#include <iostream>
#include <cstring>
using namespace std;

void list(int limit);
void ins(int limit);
void del(int limit);
void quit();


char s[110][2100] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//char **s;
	//s = new char *[1000];
	int limit = 0;
	//s[0] = new char[2001];
	cin.getline(s[0],2000, '\n');
	char ending[7] = "******";
	//int equal = strcmp(s[0], ending);
	while (strcmp(s[limit],ending)!= 0)
	{

		limit++;
		//s[limit] = new char[2000];
		cin.getline(s[limit],2000, '\n');
		//equal = strlen(s[limit], ending);
	}

	char* order;
	order = new char[5];
	bool condition = 1;
	while (condition)
	{
		cin >> order;
		if (strcmp(order, "list") == 0)list(limit);
		else if (strcmp(order, "ins") == 0)ins(limit);
		else if (strcmp(order, "del") == 0)del(limit);
		else if (strcmp(order, "quit") == 0) { quit(); break; }



	}
	return 0;
}



void list(int limit) 
{
	int n1 = 0, n2 = 0;
	cin >> n1 >> n2;
	if ((n1 > n2) || (n1 < 0) || (n1 > limit) || (n2 > limit))
	{
		cout << "Error!" << endl;
		return;
	}

	int i = 0;
	for (i = n1-1; i < n2; i++)cout << s[i] << endl;

	return;

}

void ins(int limit)
{
	int line = 0, pos = 0;
	cin >> line >> pos;
	if ((line > limit ) ||line<1|| (strlen(s[line-1]) + 1 < pos)||pos<1)
	{
		cout << "Error!" << endl;
		return;
	}
	
	char insert[2000],p[2000];
	cin.get();
	cin.getline(insert,2000, '\n');
	int i = 0,j=0;
	for (i = 0; i < pos-1; i++)
	{
		p[i] = s[line-1][i];
	}
	
	strcpy((p + i), insert);
	j = strlen(insert);
	int q = i + j;
	strcpy((p + q), (s[line-1] + pos-1));
	strcpy(s[line-1], p);

}

void del( int limit)
{
	int line = 0, pos= 0, num = 0;
	cin >> line >> pos >> num;
	if ((line > limit )||line<1 || (strlen(s[line - 1]) < pos + num-1)||pos<1)
	{
		cout << "Error!" << endl;
		return;
	}

	int i = 0, j = 0;
	j = pos-1;
	for (i = pos + num - 1; s[line - 1][i] != '\0'; i++)
	{
		s[line - 1][j] = s[line - 1][i];
		j++;
	}
	s[line - 1][j] = '\0';

}

void quit()
{
	int i = 0;
	while (strcmp(s[i], "******") != 0)
	{
		cout << s[i] << endl;
		i++;

	}


}