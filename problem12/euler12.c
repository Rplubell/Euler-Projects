#include <stdio.h>
#include <math.h>

int makePrimeArray(long *primearr, int amt)
{
	int i;
	long numberlist[amt];		//This will be sieved
	int marked[amt];		//This is used to keep track of non-primes

	//Create array of numbers from 2 - amt
	for(i = 2; i <= amt + 2; i++)
	{
		printf("Generating numlist\n");
		numberlist[i - 2] = i;
	}

	//Sieve the array
	int posInArr, divPos, divSet;
	long primes[amt];
	long divisor = 2;
	divPos = 0;
	i = 0;
	printf("Seiving\n");
	//This will continue until at the end of array
	while(divPos <= amt)
	{
		printf("While-ing divPos %d\n", divPos);
		for(posInArr = divPos + 1; posInArr <= amt; posInArr++)
		{
			printf("Modulo-ing posInArr %d\n", posInArr);
			//Modulo stuff
			if(numberlist[posInArr] % divisor == 0)
				marked[posInArr] = 1;
			else if(marked[posInArr] != 1) marked[posInArr] = 0;
		}

		//Set next modulo-z0r
		for(i = divPos + 1; i <= amt; i++)
		{
			printf("Setting next div marked %d numlis %ld\n", i, numberlist[i]);
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
	int j = 0;
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

	for(i = lastamt; i <= amt; i++)
		current += i;

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

int isNatural(long double n)
{
	long n2;
	n2 = n;
	if(n2 == n)
		return 1;
	else return 0;
}

int fastCheckDivs(long n, int amtprimes, long *primeArray)
{
	int divs = 0;
	int i;
	long current = n;
	for(i = 0; i <= amtprimes; i++)
	{
		printf("Primarr %ld i %i\n", primeArray[i], i);
		if(isNatural(current / primeArray[i]) && primeArray[i] != n && primeArray[i] > n)
		{
			divs++;
			current = n / primeArray[i];
		} else current = n;
	}
	divs += 2;//This is to compensate for 1 and the number itself.
}

int main()
{
	long array[1000];
	int amtprimes = makePrimeArray(array, 1000);
	long tri, last, lastamt;
	int amttri, divs;

	last = 0;
	lastamt = 0;

	tri = getTri(1, last, lastamt);
	printf("floaty%ld\n", tri);

	for(amttri = 1; amttri <= 1000; amttri++)
	{
		printf("In for");
		tri = getTri(amttri, last, lastamt);
		printf("Got tri");
		divs = fastCheckDivs(tri, amtprimes, array);
		printf("Checked divs");
		printf("Divs %d\n", divs);
		if(divs >= 500)
		{
			printf("tri %ld\n", tri);
		}
		lastamt = amttri;
		last = tri;
	}

	printf("%d\n", isNatural(getTri(1, 0, 0)));
}
