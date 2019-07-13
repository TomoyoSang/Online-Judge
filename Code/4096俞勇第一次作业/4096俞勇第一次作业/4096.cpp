	#include <iostream>
	#include <cstring>

	using namespace std;


	void moveover(int ,int);
	void moveonto(int, int);
	void pileover(int, int);
	void pileonto(int, int);

	void moveback(int);
	void quit(int );



	int place[25] = { -1 };
	//int transfer[25] = { -1 };
	int condition[25][25] ;
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	
	
		int N = 0;
		cin >> N;
	
		int i = 0,j=0;
		for (i = 0; i < N; i++)
		{
			condition[i][0] = i;
			place[i] = i;
			for (j = 1; j < N; j++)
			{
				condition[i][j] = -1;
			}
		}
	/*	for (i = 0; i < N; i++)
		{
			condition[i][0] = i;
			place[i] = i;
		
		}
		*/

		char operate[10] = { 0 };
		char moveway[10] = { 0 };
		int order1 = 1, order2 = 1;
		int move = 1, pile = 1, over = 1, onto = 1;
		bool end = 1;

		while (end)
		{
			cin >> operate;
			end = strcmp(operate, "quit");
			if (end == 0) { quit(N); break; }

			cin >> order1;
			cin >> moveway;
			cin >> order2;
			move = strcmp(operate, "move");
			pile = strcmp(operate, "pile");
			over = strcmp(moveway, "over");
			onto = strcmp(moveway, "onto");

			if (move == 0)
			{
				if(over==0)moveover(order1,order2);
				else if (onto == 0)moveonto(order1, order2);
			}

			else if (pile == 0)
			{
				if (over == 0)pileover(order1, order2);
				else if (onto == 0)pileonto(order1, order2);

			}
		
			move = onto = over = pile = 1;
		};
	

	
		return 0;
	}



	void pileonto(int order1,int order2)
	{
		int i = 0;
		int high1 = 0 ,high2=0;
		//移出范围
		int pos1 = place[order1];
		int pos2 = place[order2];
		if (pos1 == pos2)return;
		while (condition[pos1][high1] != order1)
		{
			high1++;
		}
		int low1 = high1 ;
		/*
		while (condition[pos1][high1] != -1)
		{
			high1++;
		}*/
		high1++;
		//移入位置
		while (condition[pos2][high2] != order2	)
		{
			high2++;
		}
		high2++;
		//无关箱子返回
	
		while (condition[pos2][high1] != -1)
		{
			moveback(condition[pos2][high1]);
			high1++;
		}
		//移出/入过程
		i = low1;
		while (condition[pos1][low1] != -1)
		{

			condition[pos2][high2] = condition[pos1][low1];
			place[condition[pos1][low1]] = pos2;
			low1++;
			high2++;
	

		}

		condition[pos1][i] = -1;
		condition[pos2][high2] = -1;

	}

	void moveonto(int order1, int order2)
	{
		int i = 0, j = 0;
		int pos1 = place[order1];
		int pos2 = place[order2];
		if (pos1 == pos2)return;
		while (condition[pos1][i] != order1)
		{
			i++;
		}
		while (condition[pos2][j] != order2)
		{
			j++;
		}
		int k = i;
		i++; j++;
		int l = j;
	

		while (condition[pos1][i] != -1)
		{
			moveback(condition[pos1][i]);
			i++;
		}
		while (condition[pos2][j] != -1)
		{
			moveback(condition[pos2][j]);
			j++;
		}
		condition[pos2][l] = order1;
		condition[pos2][++l] = -1;
		condition[pos1][k] = -1;
		place[order1] = pos2;


	}

	void moveover(int order1, int order2)
	{
		int pos1 = place[order1];
		int pos2 = place[order2];
		if (pos1 == pos2)return;
		int i = 0, j = 0;
		while (condition[pos1][i] != order1)
		{
			i++;
		}
	
		int k = i;
		i++;
		while (condition[pos1][i] != -1)
		{
			moveback(condition[pos1][i]);
			i++;
		}

		condition[pos1][k] = -1;

		while (condition[pos2][j] != -1)
		{
			j++;
		}
		condition[pos2][j] = order1;
		place[order1] = pos2;
		condition[pos2][j + 1] = -1;

	}

	void pileover(int order1, int order2)
	{
		int pos1 = place[order1];
		int pos2 = place[order2];
		if (pos1 == pos2)return;
		int i = 0, j = 0;
		while (condition[pos1][i] != order1)
		{
			i++;
		}
		int k = i;
	
		while (condition[pos2][j] != -1)
		{
			j++;
		}
		while (condition[pos1][i] != -1)
		{
			condition[pos2][j] = condition[pos1][i];
			place[condition[pos1][i]] = pos2;
			i++; j++;
		}
		condition[pos2][j] = -1;
		condition[pos1][k] = -1;

	}

	void moveback(int order)
	{
		int pos = order;
		if (pos == place[order])return;
		/*while (condition[pos][i] != -1)
		{
			i++;
		}
		*/
		condition[pos][0] = pos;
		//condition[pos][i] = order;
		condition[pos][1] = -1;
		place[order] = order;

	}


	void quit(int N)
	{
		int i = 0, j = 0;
		for (i = 0; i < N; i++)
		{
			if (i != 0)cout << '\n';
			j = 0;
			cout << i << ':';
			while (condition[i][j] != -1)
			{
				cout << " ";
				cout << condition[i][j] ;
				j++;
			}
		
		
		}
	
	}
