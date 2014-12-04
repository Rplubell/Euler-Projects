#include <stdio.h>


//Function from previous euler project, checks if number is prime
int isPrime(long double testing)
{
        long double i;

	if(testing == 2)
		return 1;

	if(testing % 2 == 0)
		return 0;

	//Skip even numbers
	for(i = 3; i <= sqrtl(testing); i+=2)
	{
		if(testing % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	long double i;
	long double sum;
	for(i = 1; i < 2000000; i += 2)
	{
		if(isPrime(i))
			sum += i;
	}
	printf("%LF Sum\n", sum);
}
