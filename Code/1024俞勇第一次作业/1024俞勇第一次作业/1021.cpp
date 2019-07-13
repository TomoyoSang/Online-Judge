#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int length = 0;
	cin >> length;

	int ***map;
	map = new int**[length];
	int i = 0;
	for (i = 0; i < length; i++)
	{
		map[i] = new int*[length];
	}
	int j = 0;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			map[i][j] = new int[2];
			map[i][j][1] = 0;
			map[i][j][0] = 1;

		}
	}



	int direction = 1, counter = 1;
	i = 0; j = -1;

	while (1)
	{
		if (counter > length*length)break;
		if ((direction == 1) && (j + 1 < length)&&(map[i][j+1][1]==0))
		{
			j += 1;
			map[i][j][0] = counter;
			counter++;
			map[i][j][1] = 1;
		}
		else if(direction==1){
			direction = -2; 
			continue;
		}

		if ((direction == -1) && (j >= 1)&& (map[i][j-1][1] == 0))
		{
			j -= 1;
			map[i][j][0] = counter;
			counter++;
			map[i][j][1] = 1;
		}
		else if (direction == -1) {
			direction = 2;
				continue;
		}
			;

		if ((direction == 2) && (i >= 1)&&(map[i-1][j][1] == 0))
		{
			i -= 1;
			map[i][j][0] = counter;
			counter++;
			map[i][j][1] = 1;
		}
		else if (direction == 2)
		{
			direction = 1; continue;
		}
			


		if ((direction == -2) && (i < length - 1) && (map[i + 1][j][1] == 0))
		{
			i += 1;
			map[i][j][0] = counter;
			counter++;
			map[i][j][1] = 1;
		}
		else if(direction==-2)
		{
			direction = -1;
			continue;
		}
			
			
		
	}

	for (i = 0; i < length; i++)
	{
		if (i > 0)cout << endl;
		for (j = 0; j < length; j++)
		{
			cout << setw(6) << map[i][j][0];
		}
	}
	
	
	
	return 0;
	
	


}