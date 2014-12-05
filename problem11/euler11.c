#include <stdio.h>

/*//This will put .txt file into a 2d array
int fillArray(int *toFill[][20], int xsize, int ysize, FILE *fp)
{
	int xpos, ypos, current, last, gridpos;
	char grid[((xsize * ysize)*2)+1];

	fgets(grid, ((xsize * ysize)*2)+1, (FILE*)fp);

	for(ypos = 0; ypos <= ysize;)
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

        return 1;	{
*/

int main()
{
	FILE *gridfp;
	gridfp = fopen("grid.txt", "r");
	if(!gridfp)
	{
		printf("Nuuuu");
		return 0;
	}
	int toFill[20][20];
	//fillArray(*grid, 20, 20, gridfp);

	int xpos, ypos, current, last, lasty, gridpos, ysize, xsize;
	ysize = xsize = 20;
	gridpos = 0;
	char grid[((xsize * ysize)*2)+1];
        fgets(grid, ((xsize * ysize)*2)+1, (FILE*)gridfp);
        for(ypos = 0; ypos <= ysize;)
        {
                last = 0;
                for(xpos = 0; xpos <= xsize && lasty == ypos; gridpos++)
                {
                        current = grid[gridpos];

                        if(last != '\n' && current != '\n' && last != ' ' && current != ' ')
                        {
                                toFill[xpos][ypos] = ((last - '0') * 10) + (current - '0');
				printf("xpos %d ypos %d last %d current %d value %d\n", xpos, ypos, last, current, ((last-'0') * 10) + (current - '0'));
                                xpos++;
                        }
                        if(current == '\n')
                        {
                                ypos++;
				continue;
                        }
                        last = current;
                }
        }

	//This is for testing the array filler
	int i, j;
	for(i = 0; i <= 20; i++)
	{
		for(j = 0; j <= 20; j++)
		{
			printf("%d ", toFill[j][i]);
		}
	}
}
