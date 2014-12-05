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
	int value;

	while(fgets(buffer, sizeof(buffer), fp)!=NULL)
	{
		printf("%s \n", buffer);
		char* ptr = strtok(buffer," ");
		while(ptr)
		{
			printf("token string %s\n", ptr);
			value = atoi(ptr);
			printf("value: %d\n", value);
			ptr = strtok(NULL, " ");
		}
	}
	fclose(fp);
}
