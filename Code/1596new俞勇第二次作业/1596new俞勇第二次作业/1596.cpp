#include <iostream>
#include<algorithm>
using namespace std;

double L = 0;

int i = 0, j = 0;
int k = 0, l = 0;

int x = 0, y = 0;
int _x = 0, _y = 0;
long long Space = 0, Lpace = 0;
double looptime = 0;
int main()
{
	cin >> L;
	cin >> x>> y;
	
	x--;
	y--;
	_x = L-1-x;
	_y = L-1-y;
	//x = y;
	//_y = x;


	double mid = (L-1) / 2;
	looptime =mid-max(abs(x-mid),abs(y-mid));
	for (i = 0; i < looptime; i++)
	{
		Lpace += (L  -1- 2 * i) * 4;
	}

	
	
	//泷的路径值
	
	k = L - i - 1;
	l = i;
	
	if (((y<mid)&&(x<k))||((x==i)&&(y>=mid)))
	{
	
		
		
			Lpace += k - x + y - l;
		
		
	}
	else if ((y == k) || (x == l))
	{
		Lpace += 2 * L - 4 * i - 2;
		k = i;
		l = L - i - 1;
		Lpace += x - k + l - y;
	}


	cout << Lpace;
	
	//三叶路径值
	looptime = mid - max(abs(_x - mid), abs(_y - mid));
	for (i = 0; i < looptime; i++)
	{
		Space += (long long)(L - 1 - 2 * i) * 4;
	}
	k = L - i - 1;
	l = i;


		if (((_y < mid) && (_x < k)) || ((_x == i) && (_y >= mid)))
		{


			
			Space += k - _x + _y - l;


		}
		else if ((_y == k) ||( (_x == k)&&(_y!=l)))
		{
			Space += 2 * L - 4 * i - 2;
			k = i;
			l = L - i - 1;
			Space += _x - k + l - _y;
		}


	cout << " "<<Space; 
	

	



	return 0;
}