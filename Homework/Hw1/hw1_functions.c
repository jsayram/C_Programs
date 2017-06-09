/******************************************************************
 * Program #: Homework #1
 *
 * Programmer: Jose Ramirez
 *
 * Due Date: NA
 *
 * EGRE 246, Fall 2014       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid 
 *         on this program.
 *
 * Description: Homework exercise on pointer arithmetic using arrays,
 * program that reads in a list of integers, sorts smallest to largest.
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

 /*This Function Read from a file unsorted integers
  *Populates pointer array
  */
int read_array(FILE *readfile, int *array, int max_size){
	 int num=0;
	 int count=0;
	 int i=0;

   //Scans the file until it reaches the last element in the file then it stops
	while(fscanf(readfile,"%d",&num)!=EOF)
    {  //Populates array pointer with each element in the file.
	    *(array+0+i)=num;
		i++; //counter to iterate one index at a time in pointer array. 
		count++; //counter to get the number of elements in the file, ie: Size of array. 
	
	// Error message To make sure that the number of elements in the file do not 
   //exceed the Maximum number of elements allowed ie: Max_size.  
	if(count>max_size)
	{
		printf("\nERROR! ELements in file exceed the Maximum Size allowed\nThe number allowed is %d, you have %d\n",max_size,count);
		printf("\nTry again with a different file. Thank you!\n\n(Program Exit)\n");
		exit(0); // exits program. 
	}
	}
   
	
	//if it doesn't exceed max size then return the number of elements in file
	else
	{
		/*Prints to screen the unsorted element array, in order as read form file. 
		for(i=0;i<count;i++)
		{
			printf("\tUnsorted Element array(%d)= %d\n\n",i,*(array+i));
		}*/
		return count; // return the number of elements in file, ie: Size of Array pointer.
	}
}
/*This Function sorts Elements
 *From Smallest to largest 
*/
void sort_array(int *array, int size){
	 int i=0;
	 int j=0;
	 int temp=0;
	 int size2=size;
	//Sorts array from smallest to largest. 
	for (i=0; i<size;i++)  //  index 0
	{
		for(j=i+1;j<size2;j++)// index 1
		{
		   // the two indexes are compared if second is smaller than the first swap
			if(*(array+0+j)<*(array+0+i)) 
				{
					temp=*(array+0+j); //temporary variable takes value of second index
					*(array+0+j)=*(array+0+i); //second index takes value of first index 
					*(array+0+i)=temp; //first index takes value of the temporary variable.
				} 						  
		}	  		
	}  
	/*outputs the sorted elements in array to the screen in order. 
	for(i=0;i<size;i++)
	{
		printf("\tSorted Elements array(%d)= %d\n",i,*(array+i));
	}*/
}
/*This Function Writes Elements to an output file hw1_output.txt
 *In order.
*/
void write_array(FILE *writefile, int *array, int size){
    printf("\nSorted Elements written to (hw1_output.txt) file.\n\t\tThank you!\n");
	int i=0;
	//writes the Sorted elements in array to an output file called hw1_output.txt
	for(i=0;i<size;i++)
	{
		fprintf(writefile,"%d\n",*(array+i));
	}
}