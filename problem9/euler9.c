#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	double c;
	for(b = 1; b < 1000; b++)
	{
		for(a = 1; a <= b; a++)
		{
			c = sqrt(pow(a, 2) + pow(b, 2));
			if(a + b + c == 1000)
			{
				printf("A %d B %d C %f %f\n", a, b, c, a * b * c);
				return 1;
			}
		}
	}
	printf("Well shucks, back to the drawing board");
	return 1;
}
