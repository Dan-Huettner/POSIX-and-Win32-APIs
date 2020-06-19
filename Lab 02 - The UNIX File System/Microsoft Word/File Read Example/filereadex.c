/* Contains function declarations for fopen, fscanf, fclose, and printf */
#include <stdio.h>

int main ()
{
	/* The unique identifier for the file to be read
	   This is given to a Standard C Library function when specifying a file
	   to read or write */
	FILE * fileID;

	/* A character array to store the string to be read from the file */
	char string[80];

	/* Opens the file for reading */
	fileID = fopen ("/proc/sys/kernel/foo","r");
	
	/* Reads in a string from a file */
	fscanf (fileID, "%s", string);
	
	/* Closes the file */
	fclose (fileID);

	/* Prints the string that was read from the file to the console */
	printf ("%s\n",string);
	
	return 0;
}