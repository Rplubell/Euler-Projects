#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1000

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

	int i, x;
	for(i = 0; i < 20; i++)
	{
		for(x = 0; x < 20; x++)
			printf("%d\n", toFill[i][x]);
	}
}
