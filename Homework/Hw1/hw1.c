/******************************************************************
 * Program #: Homework #1
 *
 * Programmer: Robert H. Klenke
 *
 * Due Date: NA
 *
 * EGRE 246, Fall 2014       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid 
 *         on this program.
 *
 * Description: Homework exercise in pointer arithmetic using arrays
 *
 * Input: text file with one integer per line - hw1_input.txt is the
 *        provided example
 *
 * Output: text file hw_1_output.txt containing sorted 
 *         list of integers
 *
 ******************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

#define SIZE		100
#define MAXCHAR		256

int read_array(FILE *readfile, int *array, int max_size);
void sort_array(int *array, int size);
void write_array(FILE *writefile, int *array, int size);

void main(void)
{
	int int_array[SIZE];
	int array_size;
	FILE *infile = NULL;
	char infilename[MAXCHAR];
	FILE *outfile;

	printf("Sort an array of integers from a file using pointer arithmetic\n");

	while(infile == NULL) {
		printf("Input filename:");
		scanf("%s",infilename);
		if((infile = fopen(infilename, "r")) == NULL) {
			printf("ERROR: file %s can not be opened!\n",infilename);
		}
	}

	/* open data file for storing array */
	outfile = fopen("hw1_output.txt", "w");
	if(outfile == NULL) {
		printf("ERROR: file \"hw1_out.txt\" can not be opened\n");
		exit(0);
	}

	array_size = read_array(infile, int_array, SIZE);

	sort_array(int_array, array_size);

	write_array(outfile, int_array, array_size);
	
	//closes the file
	fclose(outfile);
}