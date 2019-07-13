#include<iostream>

using namespace std;

int main()
{
	double earning;
	cin >> earning;

	double tmp = earning - 3500;

	if (tmp <= 0) { cout << '0'; return 0; }

	double i1=0, i2=0, i3=0, i4=0, i5=0, i6=0,i7=0;
	
	if (tmp > 80000) {
		i1 = (tmp - 80000) / 100 * 45;
		tmp = 80000;
	}

	if ((tmp <= 80000) && (tmp > 55000))
	{
		i2 = (tmp - 55000) / 100 * 35;
		tmp = 55000;
	}

	if ((tmp <= 55000) && (tmp > 35000))
	{
		i3 = (tmp - 35000) / 100 * 30;
		tmp = 35000;
	}

	if ((tmp <= 35000) && (tmp > 9000)) 
	{
		i4 = (tmp - 9000) / 100 * 25;
		tmp = 9000;
	}

	if ((tmp <= 9000) && (tmp > 4500))
	{
		i5 = (tmp - 4500) / 100 * 20;
		tmp = 4500;
	}

	if ((tmp <= 4500) && (tmp > 1500))
	{
		i6 = (tmp - 1500) / 100 * 10;
		tmp = 1500;
	}

	if (tmp <= 1500)
	{
		i7 = tmp / 100 * 3;
	}

	cout << int(i1 + i2 + i3 + i4 + i5 + i6 + i7);

	return 0;
}