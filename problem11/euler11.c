#include <stdio.h>

//This will get the size of a grid of numbers in a txt file.
int * fillArray(int xsize, int ysize, FILE *fp)
{
	int toFill[xsize][ysize], xpos, ypos, current, last;

	for(ypos = 0; ypos <= ysize;)
	{
		for(xpos = 0; xpos <= xsize; &fp++)
		{
			current = fgetc(&fp)
			//This part needs to convert a something like 08 to and int of 8
			if(last != -1 && current != -1)
			{
				toFill[xpos][ypos] = last * 10 + (current - '0');
				xpos++;
			}
			if(current != '\n')
			{
				if(current == '\0')
					last = -1;
				if(current - '0' < 10 && current - '0' >= 0)
					last = current - '0';
			} else
			{
				ypos++;
				break;
			}
		}
	}
	return toFill;
}
