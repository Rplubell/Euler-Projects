#include <stdio.h>

//This will get the size of a grid of numbers in a txt file.
int fillArray(int xsize, int ysize, FILE *fp)
{
	int toFill[xsize][ysize], xpos, ypos, current, last, gridpos;
	char grid[((xsize * ysize)*2)+1];

	fgets(grid, ((xsize * ysize)*2)+1, (FILE*)fp);

	for(ypos = 0; ypos <= ysize;)
	{
		last = 0;
		for(xpos = 0; xpos <= xsize; gridpos++)
		{
			current = grid[gridpos];

			if(last != '\n' && current != '\n' && last != ' ' && current != ' ')
			{
				toFill[xpos][ypos] = ((last - '0') * 10) + (current - '0');
				xpos++;
			}
			if(current == '\n')
			{
				ypos++;
				break;
			}
			last = current;
		}
	}

	return toFill;
}

int main()
{
	FILE *gridfp;
	gridfp = fopen("grid.txt", "r");
	int grid;
	grid = fillArray(20, 20, &gridfp);

	//This is for testing the array filler
	int i, j;
	for(i = 0; i <= 20; i++)
	{
		for(j = 0; j <= 20; j++)
		{
			printf("%d", grid[j][i]);
		}
	}
}
