#include <stdio.h>
#include <math.h>

int main()
{
	int outer, inner;
	for(outer = 1; outer < 100; outer++)
	{
		for(inner = 1; inner < 100; inner++)
		{
			if(pow(outer, 2) + pow(inner, 2) + (pow(outer, 2) + pow(inner, 2) == 1000)
			{
				printf("A %d B %d C %d", outer, inner, (pow(outer, 2) + pow(inner, 2)));
				return 1;
			}
		}
	}
	printf("Well shucks, back to the drawing board");
	return 1;
}
