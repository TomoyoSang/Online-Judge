#include <iostream>
#include <cstdio>
using namespace std;

int M, N;
int Height[250002];
double High = 0;

long long V;
double Vi = 0;
int counter;
int g = 0;
void Quicksort(int left, int right)
{
	if (left == right)return;
	else if (left - right == 1)return;
	else
	{
		int key = Height[left];
		int tmp1 = left;
		int tmp2 = right;

		while (left < right)
		{
			while (left < right&&key <= Height[right])
			{
				right--;
			}

			if (left < right)
			{
				Height[left] = Height[right];
				left++;
			}

			while (left < right&&Height[left] <= key)
			{
				
				left++;

			}

			if (left < right)
			{
				Height[right] = Height[left];
				right--;
			}
		}

		Height[left] = key;
		Quicksort(tmp1, left);
		Quicksort(left + 1, tmp2);
		return;
	}
}

int judging(int left)
{
	Vi = 0;
	for (int i = 0; i < left; i++)
	{
		Vi += Height[left] - Height[i];
	}
	if (Vi == V)return 1;
	else if(Vi>V)return 2;
	return 0;

	
}

void erfen(double left, double right)
{
	if ((right - left) < 0.0000001)
	{
		High = (right + left) / 2;
		printf("%.2f", High);
		printf("\n");
		printf("%.2f", (double(g+1) / counter)*100);
		return;
	}
	Vi = 0;
	double mid = (left + right) / 2;

	for (int i = 0; i <= g; i++)
	{
		Vi += mid - Height[i];
	}

	if (Vi > V)
	{
		erfen(left, mid);
	}
	else if (Vi < V)
	{
		erfen(mid, right);
	}

	else if (Vi == V)
	{
		High = mid;
		printf("%.2f", High);
		printf("\n");
		printf("%.2f", (double(g+1) / counter)*100);
		return;
	}
	return;
}


void calcu(int left, int right)
{
	Vi = 0;
	
	if (right - left == 1)
	{
		int flag1=judging(left);
		int flag2=judging(right);
		if (flag1==1)
		{
			printf("%.2f", double(Height[left]));
			printf("\n");
			printf("%.2f", (double(left) / counter) * 100);
		}
		
		else if (flag2==1)
		{
			printf("%.2f", double(Height[right]));
			printf("\n");
			printf("%.2f", (double(right) / counter) * 100);
		}
		else if (flag2 == 0)
		{
			Vi = 0;
			g = right;
			int m = Height[right];
			for (int i = 0; i < right; i++)
			{
				Vi += Height[right] - Height[i];
			}
			while (Vi < V)
			{
				m++;
				Vi += (right+1);
			}
			if (Vi == V)
			{
				printf("%.2f", double(m));
				printf("\n");
				printf("100.00");
				return;
			}
			else if (Vi > V)
			{
				erfen(double(m-1), double(m) );
			}
			

			return;
		}
		else
		{
			g = left;
			erfen(double(Height[left]), double(Height[right]));
			
		}
		return;
	}
	int mid = (left + right) / 2;
	for (int i = 0; i < mid; i++)
	{
		Vi += Height[mid] - Height[i];
	}
//	vi[mid] = Vi;
	if (Vi == V)
	{
		
		printf("%.2f", double(Height[mid]));
		printf("\n");
		printf("%.2f", (double(mid) / counter)*100);
		return;
	}
	else if (Vi < V)
	{
		calcu(mid, right);
	}
	else if (Vi > V)
	{
		calcu(left, mid);
	}
		
	return;
}



int main()
{
	

	scanf("%d%d", &M, &N);

	 counter = M * N;
	for (int i = 0; i < counter; i++)
	{
		scanf("%d", &Height[i]);
		
	}
	scanf("%lld", &V);
	
	if (counter == 1)
	{
		if (V > 0)
		{
			printf("%.2f", double(V + Height[0]));
			printf("\n");
			printf("%.2f", 100.00);
			return 0;
		}
		else
		{
			printf("%.2f", double( Height[0]));
			printf("\n");
			printf("%.2f", 0.00);
			return 0;
		}
	}

	Quicksort(0,counter-1);

	if (V == 0)
	{
		printf("%.2f", double(Height[0]));
		printf("\n");
		printf("%.2f", 0.00);
	}
	else 
		calcu(0, counter-1);

	
	
	
	return 0;
}


