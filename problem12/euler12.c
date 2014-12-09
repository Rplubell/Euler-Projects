#include <stdio.h>
#include <math.h>

#define LIMIT 10000000

int main()
{
	long i, j, divs;
	long current = 0;
	for(i = 0; i < LIMIT; i++)
	{
		current += i;
		divs = 0;
		for(j = 1; j <= current; j++)
		{
			if(current % j == 0)
				divs++;
		}
		if(divs >= 500)
			printf("SDIFKJSDLKFJSDKFLDJSLKF %ld\n", current);
	}
}
