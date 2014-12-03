/*
This program will need to read from a .txt file containing 1000 digits. It wil
then read those digits into an array.
After in the array the digits are loaded from that array into another array
which will hold 13 ints. These ints will then be multiplied together and then 
stored in a variable which will be tested against another variable later to 
check if the current digits in the 13 digit array is bigger than the current 
biggest array of digits.

*/

#include <stdio.h>


int main()
{
	int pos, j, x, bigstart;
	long long toTest, biggest;
	char bignumber[1000];
	char biggestdigits[12];

	//Initializes file
	FILE *fp;
	fp = fopen("bignumber.txt", "r");
	if(!fp)
		return 1;
	fgets(bignumber, 1001, (FILE*)fp);

	//This controls position in bignumber array
	for(pos = 0; pos < 1000-12; pos++)//-13
	{
		for(j = 0; j <= 12; j++)
		{
			toTest *= (bignumber[pos+j] - '0');
		}
		if(toTest > biggest)
			{
				biggest = toTest;
				bigstart = pos;
			}
	}
	for(j = 0; j <= 12; j++)
	{
		biggestdigits[j] = bignumber[bigstart + j];
	}
	printf("Digits %s Product %lld", biggestdigits, biggest);
}
