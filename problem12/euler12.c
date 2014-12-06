#include <stdio.h>
#include <math.h>

long getTri(int amt)
{
	int i;
	long current;
	current = 0;

	for(i = 0; i <= amt; i++)
	{
		current += i;
	}
	return current;
}

int checkDivs(long n)
{
	long i;
	int divs;
	divs = 0;

	for(i = 1; i <= n; i++)
	{
		if(n % i == 0)
			divs++;
	}
	return divs;
}

int main()
{
	int i;
	long last;
	for(i = 0; checkDivs(getTri(i)) <= 500 && i < 26000; i++)
	{
		if(i % 50 == 0)
			printf("%d\n", i);
	}
	printf("%ld", getTri(i-1));
}
