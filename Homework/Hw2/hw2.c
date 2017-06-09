/******************************************************************
 * Program #: Homework #2
 * 
 * Programmer: Jose Ramirez
 *
 * Due Date: September 22, 2014
 *
 * EGRE 246, Fall 2014       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid 
 *         on this program.
 *
 * Description: File that contains the implementation of main() program
 * 				that test all functions
 *
 * Input: User input of two complex points, or test.txt file to
 * 		 to test each of the functions written that manipulate 
 *		 polar or rectangular complex numbers.
 *
 * Output: Complex Numbers, and Arithmetic Operations with complex numbers.
 ******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "hw2.h"
#include "hw2_functions.h"

int main(void){
	char input[10]; //for start of program file input(f) or user input (u)
	struct complex num1; //first complex number object 
	struct complex result,a,b; //three complex number objects. 
	char coordinate=' '; //character variable for coordinate input
	char pick=' '; //this variable will be used in the User_coord_choice function. 
	char restart[0];//This is for the restart character input (y)Yes and (n)no to exit
	char loopBack=1;//loop back variable for big While loop to run the whole program
	FILE *infile=NULL; //pointer for file input 
	char dFile[20]; //to scan the file name. 
  while(loopBack==1){
		printf("\nWhat would you like to do?\n");
		printf("To Input your own points press (u)\n");
		printf("To Input from a file press (f): ");
		scanf("%s",input);
		printf("\n");
		if(input[0]=='u' || input[0]=='U')
		{
			/*This Test the User input function for one complex number*/
			 //structure for complex object variable
			enter_point(&num1);
			printf("\nComplex Number Entered: ");
			print_point(num1); //this outputs the point the the user imputed
			printf("\nComplex Number converted to ");
			convert_point(&num1); // this converts the point from RECT to POLAR, Or POLAR to RECT
			print_point(num1);//This prints out the point after conversion
			printf("\n");
			/*This outputs the REAL portion of the complex number
			If the coordinate system is POLAR then it will convert the 
			number to the rectangular coordinate system, and then output the REAL 
			part of the number*/
			
			printf("REAL: %.4lf\n",real(num1)); 
			/*This outputs the IMAGINARY portion of the complex number
			If the coordinate system is POLAR then it will convert the 
			number to the rectangular coordinate system, and then output the IMAGINIARY 
			part of the number*/
			
			printf("IMAGINARY: %.4lfi\n",imag(num1));
			/*This outputs the MAGNITUDE portion of the complex number
			If the coordinate system is RECTANGULAR then it will convert the 
			number to the POLAR coordinate system, and then output the MAGNITUDE 
			part of the number**/
			
			printf("MAGNITUDE: %.4lf\n",mag(num1));
			/*This outputs the ANGLE portion of the complex number
			If the coordinate system is RECTANGULAR then it will convert the 
			number to the POLAR coordinate system, and then output the ANGLE 
			part of the number*/
			printf("ANGLE(Degrees): %.4lf\n",ang(num1));
			
			printf("\n\nInput two Complex Numbers to Apply Arithmetic Operations(+,-,*,/) on\n");
			
			/*user inputs two complex numbers to perform arithmetic operations too.
			The user can choose either polar ,rectangular, or a combination of both to 
			be added,subtracted,divided or multiplied*/
			enter_point(&a);
			enter_point(&b);
			
			/* User chooses which coordinate system the Result will be the outputted, 
			(r) rectangular or (p) Polar, if no system if chosen the default system 
			 Rectangular will be the coordinate system of the Result of each arithmetic
			 operation done to the two complex numbers. This will be crucial for the 
			 implementation of the arithmetic operation functions */
			printf("Do you want the results of each operation in polar (p) or rectangular (r)?: ");
			scanf("%s",&coordinate);
			if(coordinate=='r' || coordinate=='R'|| coordinate=='p'|| coordinate=='P')
			{	
				result.coord=coordinate;
			}
			else
			{
				printf("\nNo proper coordinate system selected,Results will default to Rectangular (r)\n");
				result.coord=RECT;
			}
			pick=result.coord;
			/*************************************************************************
			/*Testing of Addition Function with user input numbers.
			/*Addition of two imputed complex numbers polar or rectangular, the result's coordinate system
			/*was chosen by the user, if no polar system chosen or invalid coordinate system chosen, 
			/*then the default Rectangular (r) coordinate system 
			/*will be the output coordinate system for results.
			/*******************************************************************/
			//addition function
			add(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
			/*************************************************************************
			/*Testing of subtraction Function with user input numbers.
			/*Subtraction of two imputed complex numbers polar or rectangular, the result's coordinate system
			/*was chosen by the user, if no polar system chosen or invalid coordinate 
			/*system chosen, then the default Rectangular (r) coordinate system 
			/*will be the output coordinate system for results
			/*******************************************************************/
			//subtraction function
			sub(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
			/*************************************************************************
			/*Testing of Multiplication Function with user input numbers.
			/*Multiplication of two imputed complex numbers polar or rectangular, the result's coordinate system
			/*was chosen by the user, if no polar system chosen or invalid coordinate 
			/*system chosen, then the default Rectangular (r) coordinate system 
			/*will be the output coordinate system for results
			/*******************************************************************/
			//multiplication function
			mult(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
			/*************************************************************************
			/*Testing of Division Function with user input numbers.
			/*Multiplication of two imputed complex numbers polar or rectangular, the result's coordinate system
			/*was chosen by the user, if no polar system chosen or invalid coordinate 
			/*system chosen, then the default Rectangular (r) coordinate system 
			/*will be the output coordinate system for results
			/*******************************************************************/
			//division function
			divi(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
	  }
		//********************************************************************************************************************************************
		//#######################TESTING with FILE INPUT!#############################
		//If the user inputs the that they want to read off from a file at the start of
		//the program , the program will continue form this point if the user inputs 
		// (f) for the option to what they would like to do
		//*********************************************************************************************************************************************
	  else if (input[0]=='f' || input[0]=='F')
	  {	
			//This scan for a file name 
			printf("Data File Name: ");
			scanf("%s",dFile);
			infile = fopen(dFile,"r");
			//if the file name is not imputed then an error message appears 
			//letting the user know what happened, and then the program 
			//returns to the beginning and prompts user what would they like to do?
			while(infile==NULL)
			{	
				printf("\n[ERROR]- That file does not exist,\nPlease input your own points or different file. \n");
				main();
			}
			read_point(infile,&num1);	//reads the first point from the file
			printf("\nFirst Complex Number from file entered: ");
			print_point(num1); //this outputs the point the the user imputed
			printf("\nComplex Number converted to ");
			convert_point(&num1); // this converts the point from RECT to POLAR, Or POLAR to RECT
			print_point(num1);//This prints out the point after conversion
			printf("\n");
			
			/*This outputs the REAL portion of the complex number
			If the coordinate system is POLAR then it will convert the 
			number to the rectangular coordinate system, and then output the REAL
			part of the number*/
			printf("REAL: %.4lf\n",real(num1)); 
			
			/*This outputs the IMAGINARY portion of the complex number
			If the coordinate system is POLAR then it will convert the 
			number to the rectangular coordinate system, and then output the IMAGINIARY 
			part of the number*/
			printf("IMAGINARY: %.4lfi\n",imag(num1));
			
			/*This outputs the MAGNITUDE portion of the complex number
			If the coordinate system is RECTANGULAR then it will convert the 
			number to the POLAR coordinate system, and then output the MAGNITUDE 
			part of the number*/
			printf("MAGNITUDE: %.4lf\n",mag(num1));
			
			/*This outputs the ANGLE portion of the complex number
			If the coordinate system is RECTANGULAR then it will convert the 
			number to the POLAR coordinate system, and then output the ANGLE 
			part of the number*/
			printf("ANGLE(Degrees): %.4lf\n",ang(num1));
			
			printf("\n\nTwo Complex numbers taken from file to Apply Arithmetic Operations(+,-,*,/)\n");
			
			/*Two complex numbers taken from file to perform arithmetic operations too.
			They are either polar ,rectangular, or a combination of both to 
			be added,subtracted,divided or multiplied*/
			read_point(infile,&a);
			print_point(a);
			read_point(infile,&b);
			print_point(b);
			
			/*User chooses which coordinate system the Result will be the outputted, 
			/*(r) rectangular or (p) Polar, if no system if chosen the default system 
			/* Rectangular will be the coordinate system of the Result of each arithmetic
			/*operation done to the two complex numbers.*/
			printf("Do you want the results in polar (p) or rectangular (r)?: ");
			scanf("%s",&coordinate);
			if(coordinate=='r' || coordinate=='R'|| coordinate=='p'|| coordinate=='P')
			{	
				result.coord=coordinate;
			}
			else
			{
				printf("\nNo proper coordinate system selected, Results will default to Rectangular (r)\n");
				result.coord=RECT;
			}
			//this will be used in the user_coord_choice() function to help 
			//with the result coordinate to be in either polar(p) or rectangular (r)
			pick=result.coord;
			
			
			/*Testing of Addition Function with file input numbers.
			Addition of two imputed complex numbers polar or rectangular, the result's coordinate system
			was chosen by the user, if no polar system chosen or invalid coordinate system chosen, 
			then the default Rectangular (r) coordinate system 
			will be the output coordinate system for results.*/
			//addition function
			add(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
			
			/*Testing of subtraction Function with file input numbers.
			 Subtraction of two imputed complex numbers polar or rectangular, the result's coordinate system
			 was chosen by the user, if no polar system chosen or invalid coordinate 
			 system chosen, then the default Rectangular (r) coordinate system 
			 will be the output coordinate system for results*/
			sub(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
			
			/*Testing of Multiplication Function with file input numbers.
			 Multiplication of two imputed complex numbers polar or rectangular, the result's coordinate system
			 was chosen by the user, if no polar system chosen or invalid coordinate 
			 system chosen, then the default Rectangular (r) coordinate system 
			 will be the output coordinate system for results*/
			//multiplication function
			mult(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
			
			/*Testing of Division Function with file input numbers.
			Multiplication of two imputed complex numbers polar or rectangular, the result's coordinate system
			was chosen by the user, if no polar system chosen or invalid coordinate 
			system chosen, then the default Rectangular (r) coordinate system 
			will be the output coordinate system for results*/
			//division function
			divi(&result,a,b);
			user_coord_choice(result,pick);//This will print the correct results
		
		}
		/*If the user at the beginning of the program did not input a 
		  (u) for User Input or (f) for file input */
		else 
		{     
			printf("Input not valid!\n");
			main();
		}
		//This is the end of the program after testing the functions with user input 
		//or file input, this will prompt the user if they would like to start the program again 
		//and input a different set of complex number or another input file. 
		 printf("\nIf you would like to restart program? Press(y)\n"); 
		 printf("else press (n) to exit:");
		 scanf("%s",restart);
		//if the user chooses yes(y) to restart program it will loop back to the beginning of the while loop 
		//and rerun the program. 
		 if(restart[0]=='y' || restart[0]=='Y')
		 {
			loopBack==1;
		 }
		 //if the user chooses no(n) then the program will finish and exit. 
		 if(restart[0]=='n' || restart[0]=='N')
		 {
			exit(0);
		 } 
	}
	//closes file 
	fclose(infile);
}
