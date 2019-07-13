#include <iostream>
#include <cstring>
using namespace std;

int Position[1000][1000];

int main()

{
	memset(Position, -1, sizeof(Position));
	int N;
	cin >> N;
	int i = 0, j = 0,k=0,l=0;
	cin >> i >> j;
	for (k = 0; k < N; k++)
	{
		for (l = 0; l < N; l++)
		{
			Position[k][l] = 0;
		}
	}
	
	i--;
	j--;

	int Sdirection = 1, Ldirection = -1;
	int Scounter = 0, Lcounter = 0;




	k = 0;
	l = N - 1;

	Position[k][l] = 1;
	while (1)
	{
		if ((k == j) && (l == i))break;
		if ((Ldirection == 1) && (Position[k][l + 1] != 1) && (Position[k][l + 1] != -1))
		{
			l++;
			Position[k][l] = 1;
			Lcounter++;
		}
		else if (Ldirection == 1) {
			Ldirection = -2;
			continue;
		}

		if ((Ldirection == -1) && (l >= 1) && (Position[k][l - 1] != 1))
		{
			l--;
			Position[k][l] = 1;
			Lcounter++;

		}
		else if (Ldirection == -1)
		{
			Ldirection = 2;
			continue;
		}

		if ((Ldirection == 2) && (Position[k + 1][l] != -1) && (Position[k + 1][l] != 1))
		{
			k++;
			Position[k][l] = 1;
			Lcounter++;
		}
		else if (Ldirection == 2)
		{
			Ldirection = 1;
			continue;
		}

		if (((Ldirection == -2) && (k >= 1) && (Position[k - 1][l] != 1)))
		{
			k--;
			Position[k][l] = 1;
			Lcounter++;
		}
		else if (Ldirection == -2)
		{
			Ldirection = -1;
			continue;
		}

	}
	cout << Lcounter;

	for (k = 0; k < N; k++)
	{
		for (l = 0; l < N; l++)
		{
			Position[k][l] = 0;
		}
	}

	 k = N - 1;
	 l = 0;
	 Position[k][l] = 1;
	while (1)
	{
		if ((k == j) && (l == i))break;
		if ((Sdirection == 1) && (Position[k][l + 1] != 1) && (Position[k][l + 1] != -1))
		{
			l++;
			Position[k][l] = 1;
			Scounter++;
		}
		else if (Sdirection == 1) {
			Sdirection = -2;
			continue;
		}

		if ((Sdirection == -1) && (l >= 1) && (Position[k][l - 1] != 1))
		{
			l--;
			Position[k][l] = 1;
			Scounter++;

		}
		else if (Sdirection == -1)
		{
			Sdirection = 2;
			continue;
		}

		if ((Sdirection == 2) && (Position[k + 1][l] != -1) && (Position[k + 1][l] != 1))
		{
			k++;
			Position[k][l] = 1;
			Scounter++;
		}
		else if (Sdirection == 2)
		{
			Sdirection = 1;
			continue;
		}

		if (((Sdirection == -2) && (k >= 1) && (Position[k - 1][l] != 1)))
		{
			k--;
			Position[k][l] = 1;
			Scounter++;
		}
		else if (Sdirection == -2)
		{
			Sdirection = -1;
			continue;
		}

	}
	cout << " " << Scounter;


	


	return 0;


}







