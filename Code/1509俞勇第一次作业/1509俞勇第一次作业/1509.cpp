#include <iostream>
#include<cstdio>

using namespace std;

int gaps(int yue, int year);
int gapyear(int year,int yue);
void printout(int yue, int zhou, int xingqi, int year);
bool leapyear(int year);
bool existence(int year, int month, int day);

int main(){

	int yue = 0, zhou = 1,  xingqi= 1;
	int previous = 1850,latter=2050;
	int i = 0, j = 0;

	cin >> yue >> zhou >> xingqi >> previous >> latter;
	for (i = previous; i <= latter; i++)
	{
		printout(yue, zhou, xingqi, i);
	}
	
	return 0;

	}

void printout(int yue, int zhou, int xingqi, int year)
{
	int days = gaps( yue,  year);
	int weekday = (1 + days) % 7 + 1;
	int thisday = 0;
	if (weekday < xingqi)
	{
		thisday = xingqi - weekday + 7 * zhou - 6; 
	}
	else if(weekday==xingqi){
		 thisday = 7 * zhou - 6; 
	}
	else if (weekday > xingqi) {
		thisday = xingqi - weekday + 7 * zhou + 1; 
	}
		
	bool i = existence(year, yue, thisday);
	if (i)
	{
		printf("%04d", year);
		printf("%c", '/');
		printf("%02d", yue);
		printf("%c", '/');
		printf("%02d", thisday);
		cout << endl;
	}
	else {
		printf("%s", "none"); cout << endl;
	}
}

bool leapyear(int year)
{
	return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) ? 1 : 0;
}

bool existence(int year, int month, int day)
{
	bool flag = leapyear(year);
	bool cunzai = 0;
	if (flag)
	{
		switch (month)
		{
		case 1:if ((day > 0) && (day <= 31))cunzai = 1; break;
		case 2:if ((day > 0) && (day <= 29))cunzai = 1;; break;
		case 3:if ((day > 0) && (day <= 31))cunzai = 1;; break;
		case 4:if ((day > 0) && (day <= 30))cunzai = 1;; break;
		case 5:if ((day > 0) && (day <= 31))cunzai = 1;; break;
		case 6:if ((day > 0) && (day <= 30))cunzai = 1;; break;
		case 7:if ((day > 0) && (day <= 31))cunzai = 1;; break;
		case 8:if ((day > 0) && (day <= 31))cunzai = 1;; break;
		case 9:if ((day > 0) && (day <= 30))cunzai = 1;; break;
		case 10:if ((day > 0) && (day <= 31))cunzai = 1;; break;
		case 11:if ((day > 0) && (day <= 30))cunzai = 1;; break;
		case 12:if ((day > 0) && (day <= 31))cunzai = 1;; break;

		}

	}
	
	else switch (month)
	{
	case 1:if ((day > 0) && (day <= 31))cunzai = 1; break;
	case 2:if ((day > 0) && (day <= 28))cunzai = 1;; break;
	case 3:if ((day > 0) && (day <= 31))cunzai = 1;; break;
	case 4:if ((day > 0) && (day <= 30))cunzai = 1;; break;
	case 5:if ((day > 0) && (day <= 31))cunzai = 1;; break;
	case 6:if ((day > 0) && (day <= 30))cunzai = 1;; break;
	case 7:if ((day > 0) && (day <= 31))cunzai = 1;; break;
	case 8:if ((day > 0) && (day <= 31))cunzai = 1;; break;
	case 9:if ((day > 0) && (day <= 30))cunzai = 1;; break;
	case 10:if ((day > 0) && (day <= 31))cunzai = 1;; break;
	case 11:if ((day > 0) && (day <= 30))cunzai = 1;; break;
	case 12:if ((day > 0) && (day <= 31))cunzai = 1;; break;

	}
	return cunzai;

}

int gaps(int yue, int year)
{
	int days=0,months,years;
	bool leap = leapyear(year);
	for (years = 1850; years < year; years++)
	{
		days += gapyear(years,yue);

	}
	if (yue != 1) {
		
			switch (yue)
			{
			case 2:days += 31; break;
			case 3:days += 31+(int)(28 + leap); break;
			case 4:days += 62+ (int)(28 + leap); break;
			case 5:days += 92+ (int)(28 + leap); break;
			case 6:days += 123+ (int)(28 + leap); break;
			case 7:days += 153+ (int)(28 + leap); break;
			case 8:days += 184+ (int)(28 + leap); break;
			case 9:days += 215+ (int)(28 + leap); break;
			case 10:days += 245+ (int)(28 + leap); break;
			case 11:days += 276+ (int)(28 + leap); break;
			case 12:days += 306+ (int)(28 + leap); break;
			}


	}
	return days;

}

int gapyear(int year,int yue)
{
	
	bool leap = 1;
	
	leap = leapyear(year);
	if (leap)return 366;
	else return 365;
	
}