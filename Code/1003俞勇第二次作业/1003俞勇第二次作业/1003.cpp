#include <iostream>
using namespace std;

void multiply();
int check[102][102] = { 0 };
int _check[102][102] = { 0 };
int L,i=0,j=0;
int blank = 0;
int counter = 0;
int main()
{
	
	cin >> L;
	for (i = 1; i <= L; i++)
	{
		for (j = 1; j <= L; j++)
		{
			cin >> check[i][j];
			_check[i][j] = check[i][j];
			if (check[i][j] == 0)blank++;
		}
	}

	for (i = 1; i <= L; i++)
	{
		check[0][i] = 1;
		check[L+1][i] = 1;
		check[i][0] = 1;
		check[i][L + 1] = 1;
		_check[0][i] = 1;
		_check[L + 1][i] = 1;
		_check[i][0] = 1;
		_check[i][L + 1] = 1;
	}
	if (blank == 0)cout << 0;
	else 

	multiply();
	return 0;


		
}


void multiply()
{
	for (i = 1; i <= L; i++)
	{
		for (j = 1; j <= L; j++)
		{
			if (check[i][j] == 1)
			{
				if (check[i + 1][j] == 0)
				{
					if (_check[i + 1][j] == 0)
					{
						_check[i + 1][j] = 1;
						blank--;
					}
				}

				if (check[i -1][j] == 0)
				{
					if (_check[i - 1][j] == 0)
					{
						_check[i - 1][j] = 1;
						blank--;
					}
				}

				if (check[i ][j+1] == 0)
				{
					if (_check[i][j+1] == 0)
					{
						_check[i][j + 1] = 1;
						blank--;
					}
					
				}

				if (check[i ][j-1] == 0)
				{
					if (_check[i][j - 1] == 0)
					{
						_check[i][j - 1] = 1;
						blank--;
					}
					
				}

			}
		}
	}
	for (i = 1; i <= L; i++)
	{
		for (j = 1; j <= L; j++)
		{
			check[i][j] = _check[i][j];
		}
	}

	counter++;




	if (blank > 0)multiply();
	else if (blank == 0)cout << counter;
	return;
}