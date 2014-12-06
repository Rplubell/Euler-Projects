#include <stdio.h>
#include <math.h>

int makePrimeArray(long * primearr[], int amt)
{
	int i, divisor, j, amtprimes, marked[amt], ppoint;
	long numberlist[amt];
	for(i = 2; i <= amt; i++)//Creates list of numbers from 2 - amt
	{
		numberlist[i - 2] = i;
	}

	for(divisor = 2; 
	{
		for(i = 0; i <= amt; i++)
		{
			if(numberlist[i] % divisor == 0)
				marked[i] = 1;
			else
				marked[i] = 0;
		}
		for(i = 0; i <= amt; i++)
		{
			if(marked[i] == 0)
			{
				divisor = numberlist[i];
				break;
			}
		}
	}
}

long getTri(long amt, long last, long lastamt)
{
	long i;
	long current;
	current = last;

	for(i = lastamt; i <= amt; i++)
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
	/*int i;
	long last;
	for(i = 0; checkDivs(getTri(i)) <= 500 && i < 26000; i++)
	{
		if(i % 50 == 0)
			printf("%d\n", i);
	}
	printf("%ld", getTri(i-1));*/
	long i;
	long last;
	long lastamt;
	last = 0;
	lastamt = 0;
	for(i = 0; i < 2000000; i++)
	{
		printf("%ld\n", getTri(i, last, lastamt));
	}
}
