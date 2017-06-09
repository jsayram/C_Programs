/* Project #5
  EGRE245 Spring 2014
  Jose Ramirez */

#include <stdio.h>
#include <math.h>

double f(double x);

int main (void)
{   printf("Proj. #5 - Jose Ramirez\n\n");
    double a=0;
	double b=0;
    double n=0;
		
//B must be greater than A, and n must be greater than 0). 
	printf("Lower Limit: ");
	scanf("%lf",&a);
	printf("Upper Limit ( should be greater than %f)",a);
	scanf("%lf",&b);
//check if b is greater than a
int count=0;
while (count==0)
{
	   if(a>b)
	   {
		printf("[Errr] the lower limit must be less than the upper limit; please try again\n");
		
		printf("Lower Limit: ");
		scanf("%lf",&a);
		
		printf("Upper Limit ( should be greater than %f)",a);
	    scanf("%lf",&b);
		count=0;
		}
       else 
       count++;	   
}
//n must be greater than zero 
int count2=0;
printf("Number of Trapezoids: ");
scanf("%lf",&n);
//checks if n is greater than zero
while(count2==0)
{
    if(n<=0)
	 {
	    printf("[Error] the number of trapezoids must be greater than 0; Please Try Again\n");
        printf("Number of Trapezoids: ");
		scanf("%lf",&n);
		count2=0;
	  }
	  count2++;
}
double d=0;  //this is delta
d=(b-a)/n;
//printf("\nTHIS IS DELTA: %f \n\n",d);

//calculate area under curve
double i=1;
double sum=0;
//multiplies the first and last function by 1/2 and sums 
//up the values.
sum=((f(a)+f(b))*0.5);
while (i<n)
{
      //this sums up all the middle values and first/last values 
	 sum+=f(a+i*d);
	 ++i;		
}
	//multiplies the first and last sums by delta  
	sum=sum*d;
	//prints out the 
	printf("Value: %f\n",sum);
	
}
//test function inside main
 /*double f(double x)
{
     return x*x;
}*/
  
