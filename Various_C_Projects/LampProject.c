/* Project #4
  EGRE245 Spring 2014
  Jose Ramirez */

#include <stdio.h>
#include <math.h>

int main (void)
{
	printf("Proj. #4 - Jose Ramirez\n\n");
//equation values	
	float c=0;
	float h=0;
	float x=0;
	float i=0;
	float d=0;
	float total=0;

//L variables for illumination
	float L1=0;
	float t=0;
	float b=0;

//helping variables  
    float x1=0;
	float n=0;
   
	printf("Power of lamps (in watts)? ");
	scanf("%f",&c);
	
	printf("Height of lamp (in meters)? ");
	scanf("%f",&h);
	
	printf("Distance apart? (in meters)? ");
	scanf("%f",&x);
	
	printf("Interval? (in meters)? ");
	scanf("%f",&i);
	
	printf("\nPower: %.2f watts\n",c);
	printf("Height: %.2f meters\n",h);
	printf("Distance apart: %.2f meters\n",x);
	printf("Interval: %.2f meters\n",i);
	
	printf("  d\t   L\n");
	printf("------  ------");	
    
	
//this just copies the distance inputed to a new variable
//for future use. 	
 x1=x;
 //total distance for all lamps together 
	total=x*3;

//while the interval is less then the total distance, run	
	while(n<=total)
	{ float x2=0;
	  float L2=0;
	     //while the distance is less then the total distance
	      while(x2<=total)
		  {   
		     //if the interval is equal to the starting distance 0 
			 //the total distance is zero
		     if(n==x2)
			 {   d=0;
			   //printf("\nThis is d=0: %d\n", d);
			 }
			 //if the interval is greater than the starting distance
			 //subtract the starting distance from interval
			 if (n>x2)
			 {
			    d= n-x2;
				//printf("this is the d i-x2: %f\n",d);
			 } 
			 //if the interval is less than the starting distance
			 //subtract the interval from the starting distance.
			 if (n<x2)
			 {
			    d=x2-n;
				//printf("this is the d x2-n: %f",d);
			 }
			 //increase the starting distance by distance imputed
	            x2=x2+x1;
			 //calculate the illumination at each distance 
				t=c*h;
				b=((h*h)+(d*d));
				L1=t/(powf(b,1.5f));
				//sums all outputs together
				L2=L2+L1;
				//printf("\nThis is the L2: %f",L2);
	         }
	printf("\n%6.2f  %7.5f",n,L2);	
  //increase starting interval by imputed interval. 	
	n=n+i;  	 
	}
				
	
	return 0;
	
}