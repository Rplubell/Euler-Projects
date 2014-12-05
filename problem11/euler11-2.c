#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1000

long vertMult(int array[][20])
{
	int x, y, i;
	long product;
	long longest;
	longest = 0;
	for(x = 0; x <=19; x++)
	{
		for(y = 0; y <= 19-4; y++)
		{
			for(i = 0, product = 1; i <=3; i++)
			{
				product *= array[y + i][x];
				printf("vert x %d y %d i %d currentint %d currentproduct %ld\n", x, y, i, array[y + i][x], product);
			}
			if(product > longest)
				longest = product;
		}
	}
	return longest;
}

long horizMult(int array[][20])
{
        int x, y, i;
        long product;
        long longest;
	longest = 0;
        for(x = 0; x <=19-3; x++)
        {
                for(y = 0; y <= 19; y++)
                {
                        for(i = 0, product = 1; i <=3; i++)
                        {
                                product *= array[y][x + i];
				printf("horiz x %d y %d i %d currentint %d currentproduct %ld\n", x, y, i, array[y][x + i], product);
                        }
                        if(product > longest)
                                longest = product;
                }
        }
        return longest;
}

long lrDiagMult(int array[][20])
{
        int x, y, i;
        long product;
        long longest;
	longest = 1;
        for(x = 0; x <=19-3; x++)
        {
                for(y = 0; y <= 19-4; y++)
                {
                        for(i = 0, product = 1; i <=3; i++)
                        {
                                product *= array[y + i][x + i];
				printf("lrDiag x %d y %d i %d currentint %d currentproduct %ld\n", x, y, i, array[y + i][x + i], product);
                        }
                        if(product > longest)
                                longest = product;
                }
        }
        return longest;
}

long rlDiagMult(int array[][20])
{
        int x, y, i;
        long product;
        long longest;
	longest = 1;
        for(x = 3; x <=19; x++)
        {
                for(y = 0; y <= 19-3; y++)
                {
                        for(i = 0, product = 1; i <=3; i++)
                        {
                                product *= array[y + i][x - i];
                        	printf("rlDiag x %d y %d i %d currentint %d currentproduct %ld\n", x, y, i, array[y + i][x - i], product);
			}
                        if(product > longest)
                                longest = product;
                }
        }
        return longest;
}

int main()
{
	FILE *fp;
	fp = fopen("grid.txt", "r");
	if(!fp)
	{
		printf("Nu can haz opun");
		return -1;
	}

	char buffer[BUFFERSIZE];
	int value, toFill[20][20], ypos, xpos;
	char* ptr;

	//printf("%s \n", buffer);
	for(ypos = 0; fgets(buffer, sizeof(buffer), fp)!= NULL && ypos <= 19; ypos++)
	{
		ptr = strtok(buffer, " ");
		for(xpos = 0; ptr != 0 && xpos <= 19; xpos++)
		{
			//printf("token string %s\n", ptr);
			toFill[ypos][xpos] = atoi(ptr);
			//printf("value: %d\n", toFill[ypos][xpos]);
			//printf("xpos %d ypos %d\n", xpos, ypos);
			ptr = strtok(NULL, " ");
		}
	}

	fclose(fp);

	long longest, holder;

	longest = vertMult(toFill);
	holder = horizMult(toFill);
	if(holder > longest)//Holder used to speed up process
		longest = holder;
	holder = lrDiagMult(toFill);
	if(holder > longest)
                longest = holder;
	holder = rlDiagMult(toFill);
	if(holder > longest)
                longest = holder;

	printf("%ld longest\n", longest);

	/*//This prints contents of array
	int i, x;
	for(i = 0; i < 20; i++)
	{
		printf("\n");
		for(x = 0; x < 20; x++)
			printf("%d ", toFill[i][x]);
	}*/
}
