#include <stdio.h>
#include <math.h>


//Function from previous euler project, checks if number is prime
int isPrime(long double testing)
{
        long double i;
	double fake;

	if(testing == 1)
		return 0;

	if(testing == 2)
		return 1;

	if(modf(testing / 2, &fake) == 0)
		return 0;

	//Skip even numbers
	for(i = 3; i <= sqrt(testing); i+=2)
	{
		if(modf(testing / i, &fake) == 0)
			return 0;
	}
	return 1;
}

int main()
{
	long double i;
	long double sum;
	for(i = 1; i <= 2000000; i++)
	{
		if(isPrime(i))
			sum += i;
		//printf("%d %Lf %Lf\n", isPrime(i), i, sum);
	}
	printf("%Lf Sum\n", sum);
}
