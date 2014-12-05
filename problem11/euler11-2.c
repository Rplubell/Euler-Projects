#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1000

long vertMult(int array[][20])
{
	int x, y, i;
	long product;
	long longest;
	for(x = 0; x <=20; x++)
	{
		for(y = 0; y <= 20-4; y++)
		{
			for(i = 0, product = 0; i <=4; i++)
			{
				product *= array[y + i][x];
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
        for(x = 0; x <=20-4; x++)
        {
                for(y = 0; y <= 20; y++)
                {
                        for(i = 0, product = 0; i <=4; i++)
                        {
                                product *= array[y][x + i];
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
        for(x = 0; x <=20-4; x++)
        {
                for(y = 0; y <= 20-4; y++)
                {
                        for(i = 0, product = 0; i <=4; i++)
                        {
                                product *= array[y + i][x + i];
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
        for(x = 4; x <=20; x++)
        {
                for(y = 0; y <= 20-4; y++)
                {
                        for(i = 0, product = 0; i <=4; i++)
                        {
                                product *= array[y + i][x + i];
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
	for(ypos = 0; fgets(buffer, sizeof(buffer), fp)!= NULL && ypos <= 20; ypos++)
	{
		ptr = strtok(buffer, " ");
		for(xpos = 0; ptr != 0 && xpos <= 20; xpos++)
		{
			printf("token string %s\n", ptr);
			toFill[ypos][xpos] = atoi(ptr);
			printf("value: %d\n", toFill[ypos][xpos]);
			printf("xpos %d ypos %d\n", xpos, ypos);
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
