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
 * Description: C source file that contains the implementation of all the functions
 * 				used in program,functions that manipulate a representation of complex numbers.
 *
 * Input: NA
 *
 * Output: Complex Numbers in either polar or rectangular coordinates.
 ******************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include "hw2.h"
 
/*Function allows User to input a complex number in either polar or rectangular coordinates*/
void enter_point(struct complex *point){
    char choice1[10];
	double value1=0.0,value2=0.0,value3=0.0,value4=0.0;
	int count=0;
	//prompts user to input a complex number
    printf("Enter A Complex Number"); 
	printf("\nChoose Rectangular (r) or Polar (p) coordinates:");
	scanf("%s",choice1);
	//based on what the user chooses,it will create the correct representation of the complex number
	//that is either polar or rectangular. 
	while(count==0)//this loop is for when the user does not input a correct coordinate system. 
	{	if(choice1[0]=='r' || choice1[0]=='p'|| choice1[0]=='P'|| choice1[0]=='R')
		{	count++;
			//if the user chooses the coordinate system to be rectangular (r) 
			//it will assign real and imaginary values for p1(RE) and p2(IM) in structure pointer. 
			if( choice1[0]=='r' || choice1[0]=='R')
			{	printf("Enter real and imaginary value\n");
				printf("Real Value:");
				scanf("%lf",&value1);
				printf("Imaginary Value:");
				scanf("%lf",&value2);
				point->coord=RECT;
				point->RE =value1;
				point->IM =value2;	
			}
			//if the user chooses the coordinate system to be polar (r) 
			//it will assign Magnitude and Angle(degree) values for p1(MAG) and p2(ANG) in structure pointer. 
			if( choice1[0]=='p'|| choice1[0]=='P')
			{   printf("Enter Magnitude and angle Values\n");
				printf("Magnitude Value:");
				scanf("%lf",&value3);
				printf("Angle Value (Degrees):");
				scanf("%lf",&value4);
				point->coord=POLAR;
				point->MAG=value3;
				point->ANG=value4;
			}
		}
		//if user did not specify a coordinate system for the point correctly, it will prompt the user
		//again to specify a correct coordinate system, either polar (p), or rectangular (r)
		else
		{
			printf("\nThe Coordinate you have enter is not valid\n");
			printf("Please Choose Rectangular (r) or Polar (p) coordinates:");
			scanf("%s",choice1);
		   count=0;
		}
	}
  
}
 /*Function prints a complex number passed in either the Rectangular (r) or polar (p) coordinate 
	specified by the point passed to the function*/
void print_point(struct complex point){
	//if the point passed's coordinate is rectangular (r) it will print it out as Rectangular
	if(point.coord==RECT)
	{
		printf("z = %.4f + %.4fi\n",point.RE,point.IM);
	}
	//if the point passed's coordinate is polar (p) it will print it out as polar
	if(point.coord==POLAR)
	{  
		printf("z = %.4f /_ %.4f\n",point.MAG,point.ANG);
	}
}
/* Converts complex point passed as polar (p) to rectangular (r), 
	or if passed as rectangular (r) it will convert to polar (p)*/
void convert_point(struct complex *point){
	double value;
	double real,imagine;
	double magnitude,angle;
	//If the coordinate is specified for point is in rectangular, this converts to polar. 
	if(point->coord==RECT)
	{	if(point->IM==0)
	    {
			printf("\nPolar;\n");
			point->ANG=0;
		}
		else
		{
			//calculates the (RE^2 +IM^2) then places it temporary variable called value. 
			value=(point->RE*point->RE)+(point->IM*point->IM); 
			magnitude=sqrt(value);//this is the square root of (RE^2 +IM^2) stored in value. 
			angle=atan((point->IM/point->RE))*(180.0/M_PI); // this gets the angle of the rectangular complex number
			printf("\nPolar:\n"); 
			/*this make sure that the angle is appropriate based 
			on the real and imaginary parts of the complex number
			Makes sure the polar complex number is in the right quadrant*/
			if((point->RE < 0) && (point->IM >0)) //this makes sure the angle is between (0 and 90)
			{  											 //based on a negative real and positive imaginary. 
				angle=angle+180.0;
			}
			if((point->RE < 0) && (point->IM <0))//makes sure that the angle is within (180 and 270)
			{ 											//or (-90 and -180) 
					if(angle>-90 || angle<-180)	//based on a Negative Real and Negative Imaginary number. 
					{
						angle=angle+180.0;
					}
			}
			if((point->RE > 0) && (point->IM <0))//makes sure that the angle is within (270 and 360)
			{ 											//or (0 and -90) 
				if(angle<-90)						//based on a Positive Real and Negative Imaginary number. 
				{
					angle=angle+180.0;
				}
				if(angle>0 && angle<270)
				{
					angle=angle+180.0;
				}
			}
			if(angle>360.0) //fail safe , makes sure the angle does not get higher than 360
			{					//It it does it just subtracts 180.
				angle=angle-180.0;
			}
			if(angle==0.0) //fail safe , makes sure the angle does not get higher than 360
			{					//It it does it just subtracts 180.
				angle=0.0;
			}
			point->ANG=angle; // assigns the structure pointer to from holding the IM (Imaginary) to ANG (angle)
			point->MAG=magnitude;// assigns the structure pointer to from holding the RE (REAL) to MAG (Magnitude)  
		}
	}
	//If the coordinate is specified for point is in polar, this converts to rectangular.
	if(point->coord==POLAR)
	{	if(point->MAG==0)
	    {
			printf("\nRectangular;\n");
			point->RE=0;
			point->IM=0;
		}
		else
		{
			//this computes the real part of the rectangular number based on the MAG and ANG of the POLAR complex. 
			real=((point->MAG)*(cos(point->ANG*(M_PI/180.0))));
			//this computes the real part of the rectangular number based on the MAG and ANG of the POLAR complex.
			imagine =((point->MAG)*(sin(point->ANG*(M_PI/180.0))));
			printf("\nRectangular:\n");
			point->RE=real;// assigns the structure pointer to from holding the MAG(Magnitude) to RE (REAL) 
			point->IM=imagine;// assigns the structure pointer to from holding the ANG (ANGLE) to IM (Imaginiary)
		}
	}
	if(point->coord==RECT)//if the coordinate of the complex number passed to function was in rectangular 
	{	//change the coordinate system to POLAR for the new complex number
		point->coord=POLAR;
	}
	else //if the coordinate of the complex number passed to function was in Polar
	{  //change the coordinate system to RECTANGULAR for the new complex number.
		point->coord=RECT;
	}
}
/*Reads complex point form a file with a complex written p1,p2 and Coordinate. 
  Assigned the values for respected rectangular or Polar complex number*/
int read_point(FILE *infile, struct complex *point){
	double num1,num2;
	char coordinate=' ';
	char choose[3];
	//scans a point from a file in order => p1 p2 coordinate. 
	fscanf(infile,"%lf%lf%s",&num1,&num2,&coordinate); 
		/*if the coordinate of the point in the file is missing or and invalid character
			this makes sure that is taken care of by either prompting the user to
			specify the coordinate for point in file or exit of the program*/
		if(coordinate!='r' && coordinate !='p')
		{
			printf("\n[Error]Rectangular or Polar coordinate for point not correctly specified\n");
			printf("if you would like you may specify its coordinate here\n");
			printf("Choose Rectangular (r) or Polar (p)\n ");
			printf("OR To exit program press (x):");
			scanf("%s",&coordinate);
			//if they choose to exit program user will press (x)
			if(coordinate=='x')
			{
				printf("\nOkay go fix the point in the file! GoodBye!\n");
				exit(0);
			}
			/*if they correctly specified a coordinate either Rectangular (r) or Polar (p) 
				it will correctly assign the pointers right coordinate system of the points specified by user*/
			else
			{
				if (coordinate=='r')//if the coordinate system chosen is rectangular
				{	
					point->RE=num1;
					point->IM=num2;
					point->coord=coordinate;
				}
				if (coordinate=='p')//if the point is in polar chosen is polar
				{	
					point->MAG=num1;
					point->ANG=num2;
					point->coord=coordinate;
				}
			}
		}
		/*If the points in file were read correctly the points will be assigned the correct coordinate system 
			read from file*/
		if (coordinate=='r')
		{	
			point->RE=num1;
			point->IM=num2;
			point->coord=coordinate;
		}
		if (coordinate=='p')
		{	
			point->MAG=num1;
			point->ANG=num2;
			point->coord=coordinate;
		}	
}


/* This returns the real part of the complex number if the complex number passed is in polar it will find its 
    real number part equivalent and return in from the function
	and if the complex number passed is in rectangular the real part of the rectangular is just returned.*/
double real(struct complex point){
   double real;
	if(point.coord==RECT)
	{  //If the points coordinate system passed to function is in rectangular it will just return the real. 
		return point.RE;
	}
	if(point.coord==POLAR)
	{   if(point.MAG==0)
	     {   real=0;
		    return real;
		 }
		//If the points coordinate system passed to function is in polar it will convert 
		//the polar complex number to just find its real part equivalent and return it. 
		real=((point.MAG)*(cos(point.ANG*(M_PI/180.0))));
		return real;
	}
}
/* This returns the real part of the complex number if the complex number passed is in polar it will find its 
    real number part equivalent and return in from the function
	and if the complex number passed is in rectangular the real part of the rectangular is just returned.*/
double imag(struct complex point){
  double imaginary;
	if(point.coord==RECT)
	{   //If the points coordinate system passed to function is in rectangular it will just return the Imagniary part.
		return point.IM;
	}
	if(point.coord==POLAR)
	{   if(point.MAG==0)
	     {   imaginary=0;
		    return imaginary;
		 }
		//If the points coordinate system passed to function is in polar it will convert 
		//the polar complex number to just find its imaginary part equivalent and return it. 
		imaginary =((point.MAG)*(sin(point.ANG*(M_PI/180.0))));
		return imaginary;
	}
}
/* This returns the real part of the complex number if the complex number passed is in polar it will find its 
    real number part equivalent and return in from the function
	and if the complex number passed is in rectangular the real part of the rectangular is just returned.*/
double mag(struct complex point){
  double magnitude,value;
	if(point.coord==RECT)
	{  //If the points coordinate system passed to function is in rectangular it will convert 
		//the rectangular complex number to just find its magnitude part equivalent and return it. 
		value=(point.RE*point.RE)+(point.IM*point.IM);
		magnitude=sqrt(value);
		return magnitude;
	}
	if(point.coord==POLAR)
	{	
		//If the points coordinate system passed to function is in polar it will just return the Magnitude part.
		return point.MAG;
	}
}
/* This returns the real part of the complex number if the complex number passed is in polar it will find its 
    real number part equivalent and return in from the function
	and if the complex number passed is in rectangular the real part of the rectangular is just returned.*/
double ang(struct complex point){
	double angle;
	if(point.coord==RECT)
	{  if(point.IM==0)
	     {   angle=0;
		     return angle;
		 }
		 else
		 {
			//If the points coordinate system passed to function is in rectangular it will convert 
			//the rectangular complex number to just find its ANGLE part equivalent and return it. 
			angle=atan((point.IM/point.RE))*(180.0/M_PI);
			/*this make sure that the angle is appropriate based 
			on the real and imaginary parts of the complex number
			Makes sure the polar complex number is in the right quadrant*/
			if((point.RE < 0) && (point.IM >0)) //this makes sure the angle is between (0 and 90)
			{  										//based on a negative real and positive imaginary. 
				angle=angle+180.0;
			}
			if((point.RE < 0) && (point.IM <0))//makes sure that the angle is within (180 and 270)
			{ 									      //or (-90 and -180) 
					if(angle>-90 || angle<-180) //based on a Negative Real and Negative Imaginary number. 
					{
						angle=angle+180.0;
					}
			}
			if((point.RE > 0) && (point.IM <0))//makes sure that the angle is within (270 and 360)
			{ 										  //or (0 and -90) 
				if(angle<-90)                      //based on a Positive Real and Negative Imaginary number.
				{
					angle=angle+180.0;
				}
				if(angle>0 && angle<270)
				{
					angle=angle+180.0;
				}
			}
			if(angle>360.0)// makes sure the angle does not get higher than 360
			{					//It it does it just subtracts 180.
				angle=angle-180.0;
			}	
			if(angle==0.0) //input is zero will keep angle zero
			{					
				angle=0.0;
			}
			return angle;
		}
	}
	if(point.coord==POLAR)
	{   
		//If the points coordinate system passed to function is in polar it will just return the ANGLE.
		return point.ANG;
	}
}


/*This function takes two complex numbers and adds them together regardless of 
  what coordinate system the complex points have*/
void add(struct complex *result, struct complex a, struct complex b){
	 double resultReal, resultImagine;
	 double real,imagine;
	 /* These two If statements convert each of the both numbers to rectangular 
	    if they are in polar when passed through to the function*/
	if(a.coord==POLAR)
	{
		real=((a.MAG)*(cos(a.ANG*(M_PI/180.0))));
		imagine =((a.MAG)*(sin(a.ANG*(M_PI/180.0))));
		a.RE=real;
		a.IM=imagine;
	}
	if(b.coord==POLAR)
	{
		real=((b.MAG)*(cos(b.ANG*(M_PI/180.0))));
		imagine =((b.MAG)*(sin(b.ANG*(M_PI/180.0))));
		b.RE=real;
		b.IM=imagine;
	}
	 printf("\nAddition:\n");
	 //once both numbers are in rectangular result is calculated 
	 result->RE=(a.RE+b.RE); //adds the both of the complex numbers Real number part, sum is assign to results real part
	 result->IM=(a.IM+b.IM); //adds the both of the complex numbers Imaginary number part,sum is assign to results IM part
}
/*This function takes two complex numbers and subtracts them together regardless of 
  what coordinate system the complex points have*/
void sub(struct complex *result, struct complex a, struct complex b){
	 double resultReal, resultImagine;
	 double real,imagine;
	/* These two If statements convert each of the both numbers to rectangular 
	   if they are in polar when passed through to the function*/
	if(a.coord==POLAR)
	{
		real=((a.MAG)*(cos(a.ANG*(M_PI/180.0))));
		imagine =((a.MAG)*(sin(a.ANG*(M_PI/180.0))));
		a.RE=real;
		a.IM=imagine;
	}
	if(b.coord==POLAR)
	{
		real=((b.MAG)*(cos(b.ANG*(M_PI/180.0))));
		imagine =((b.MAG)*(sin(b.ANG*(M_PI/180.0))));
		b.RE=real;
		b.IM=imagine;
	}
	 printf("\nSubtraction:\n"); 
	 //once both numbers are in rectangular result is calculated 
	 result->RE=(a.RE-b.RE);//subtracts the both of the complex numbers Real number part, diff is assign to results real part
	 result->IM=(a.IM-b.IM);//subtracts the both of the complex numbers IM number part, diff is assign to results IMpart
}
/*This function takes two complex numbers and multiplies them together regardless of 
  what coordinate system the complex points have*/
void mult(struct complex *result, struct complex a, struct complex b){
	 double resultTopReal, resultTopImagineOne, resultTopImagineTwo,realAdded;
	 double resultsBottom;
	 double real,imagine;
	 /* These two If statements convert each of the both numbers to rectangular 
	   if they are in polar when passed through to the function*/
	if(a.coord==POLAR)
	{
		real=((a.MAG)*(cos(a.ANG*(M_PI/180.0))));
		imagine =((a.MAG)*(sin(a.ANG*(M_PI/180.0))));
		a.RE=real;
		a.IM=imagine;
	}
	if(b.coord==POLAR)
	{
		real=((b.MAG)*(cos(b.ANG*(M_PI/180.0))));
		imagine =((b.MAG)*(sin(b.ANG*(M_PI/180.0))));
		b.RE=real;
		b.IM=imagine;
	}
	 printf("\nMultiplication:\n");
	 /*Once both numbers are in rectangular, perform multiplication by foil.
	 In the form of (a.RE + a.IM)*(b.RE + b.IM) */
	 resultTopReal=(a.RE*b.RE);
	 resultTopImagineOne=((a.RE*b.IM)+(a.IM* b.RE));
	 /*when two imaginary numbers are multiplied together the answer is in the form of 
		num*i^2 , knowing that i^2= -1 , simply multiply the two nums together and 
		multiply the number by -1 , then it becomes a real number. */
	 resultTopImagineTwo=((a.IM*b.IM)*(-1));
	 
	 realAdded=resultTopReal+resultTopImagineTwo;//then just add the real parts
	 result->RE=realAdded;//assign the real part to the RE pointer of result
	 result->IM=resultTopImagineOne;//assign the imaginary part to the IM pointer of result
}
/*This function takes two complex numbers and divides them together regardless of 
  what coordinate system the complex points have*/
void divi(struct complex *result, struct complex a, struct complex b){
	double resultTopReal, resultTopImagineOne, resultTopImagineTwo,realAdded;
	double resultsBottom;
	double real, imagine;
	/* These two If statements convert each of the both numbers to rectangular 
	   if they are in polar when passed through to the function*/
	if(a.coord==POLAR)
	{
		real=((a.MAG)*(cos(a.ANG*(M_PI/180.0))));
		imagine =((a.MAG)*(sin(a.ANG*(M_PI/180.0))));
		a.RE=real;
		a.IM=imagine;
	}
	if(b.coord==POLAR)
	{
		real=((b.MAG)*(cos(b.ANG*(M_PI/180.0))));
		imagine =((b.MAG)*(sin(b.ANG*(M_PI/180.0))));
		b.RE=real;
		b.IM=imagine;
	}
	 printf("\nDivision:\n");
	 /*Once both numbers are in rectangular, perform division by multiplying
	 its conjugate to the two numbers being divided that is
	 In the form of (a.RE + a.IM)   (Conjugate)
					--------------X -----------
	                (b.RE + b.IM)   (Conjugate)  
      
	  (conjugate)= (b.Re - b.IM)					
	  the problem is broken down into two parts					*/ 
	
	 //first the top two numbers are foiled together that is
	 // (a.RE + a.IM)*(Conjugate)
	 resultTopReal=(a.RE*b.RE);
	 
	 /*since the top is multiplied by the conjugate of the bottom number then 
	   the b.IM is multiplied by -1 for each of the multiplication, for both of the numerator
		and denominator of the fraction*/
	 resultTopImagineOne=((a.RE*(b.IM*-1))+(a.IM* b.RE));
	 /*when two imaginary numbers are multiplied together the answer is in the form of 
		num*i^2 , knowing that i^2= -1 , simply multiply the two nums together and 
		multiply the number by -1 , then it becomes a real number. */
	 resultTopImagineTwo=((a.IM*(b.IM*-1))*(-1));
	
	//The two real numbers are then added together. 
	realAdded=resultTopReal+resultTopImagineTwo;

	 //The bottom number is the conjugate so that is just multiplied by itself
	 //then the two parts are added together to form the whole bottom real number
	 resultsBottom=((b.RE*b.RE)+(b.IM*b.IM));
	 
	result->RE=realAdded/resultsBottom;//top real numbers are then divided by the bottom 
	result->IM=resultTopImagineOne/resultsBottom;//top imaginary numbers are then divided by the bottom 
	if(resultsBottom==0.0)
	{
		result->RE=0.0;
		result->IM=0.0;
	}
}  


/*My smaller Function calls to simplify my main for the results of the 
   arithmetic operations on the complex numbers*/
void user_coord_choice(struct complex result,char pick){  
    printf("Result");
	//to make sure the coordinate does not get changed. 
	if(pick==RECT && result.coord==RECT)
	{ 
		printf("\nRectangular:\n");
		print_point(result);//prints result in the r
	}
	else if(pick==POLAR && result.coord==POLAR)
	{	
		result.coord=RECT;
		convert_point(&result);
		print_point(result);
	}
	else
	{	result.coord=POLAR;
		convert_point(&result);
		print_point(result);
	}
}
