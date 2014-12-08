#include <stdio.h>
#include <math.h>

#define SIZE 100000

long makePrimeArray(long *primearr, long amt)
{
	long i;
	long numberlist[amt];		//This will be sieved
	int marked[amt];		//This is used to keep track of non-primes

	//Create array of numbers from 2 - amt
	for(i = 2; i <= amt + 2; i++)
	{
		numberlist[i - 2] = i;
	}

	//Sieve the array
	long posInArr, divPos, divSet, test;
	long primes[amt];
	long divisor = 2;
	divPos = 0;
	i = 0;
	printf("Seiving\n");
	//This will continue until at the end of array
	while(divPos <= amt)
	{
		for(posInArr = divPos + 1; posInArr <= amt; posInArr++)
		{
			//Modulo stuff
			if(numberlist[posInArr] % divisor == 0)
				marked[posInArr] = 1;
			else if(marked[posInArr] != 1) marked[posInArr] = 0;
		}

		//Set next modulo-z0r
		for(i = divPos + 1; i <= amt; i++)
		{
			if(marked[i] != 1)
			{
				divPos = i;//caught here
				divisor = numberlist[i];
				divSet = 1;
				break;
			} else divSet = 0;
		}
		if(divSet != 1)//This stops the loop if no more primes
			break;
	}

	//Fill array with non-marked numbers
	long j = 0;
	for(i = 0; i <= amt; i++)
	{
		if(marked[i] != 1)
			primearr[j++] = numberlist[i];
	}

	return j-1;
}

long getTri(long amt, long last, long lastamt)
{
	long i;
	long current;
	current = 0;

	for(i = lastamt + 1; i <= amt; i++)
		current += current + i;

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

int fastCheckDivs(long n, int amtprimes, long *primeArray)
{//This needs double fors or double vars. needs to change prime at diff rate
	int divs = 0;
	long i;
	long current = n;
	long double nat;
	for(i = 0; i <= amtprimes && primeArray[i] < n;)
	{
		//printf("Amtpr %d primarr[i] %ld N %ld", amtprimes, primeArray[i], n);
		if(current % primeArray[i] == 0)
		{
			divs++;
			current = current / primeArray[i];
		} else
		{
			current = n;
			i++;
		}
	}
	divs += 2;//This is to compensate for 1 and the number itself.
	return divs;
}

int main()
{
	long array[SIZE];
	long amtprimes = makePrimeArray(array, SIZE);
	long tri, last, lastamt;
	long amttri, divs;

	last = 1;
	lastamt = 2;

	tri = getTri(1, last, lastamt);
	printf("floaty%ld\n", tri);

	for(amttri = 2; amttri <= SIZE; amttri++)
	{
		tri = getTri(amttri, last, lastamt);
		printf("%ld\n", tri);
		divs = fastCheckDivs(tri, amtprimes, array);
		if(divs >= 500)
		{
			printf("Dis one got 500 %ld\n", tri);
			break;
		}
		lastamt = amttri;
		last = tri;
	}
}
