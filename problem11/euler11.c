#include <stdio.h>

//This will get the size of a grid of numbers in a txt file.
int loadArray(int xsize, int ysize, int elementSize, FILE *fp)
{
	int toFill[xsize][ysize], xpos, ypos;

	for(xpos = 0; xpos <= xsize; xpos++)
	{
		for(ypos = 0; ypos <= ysize; ypos++)
		{
			
