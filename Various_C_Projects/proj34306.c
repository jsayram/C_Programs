/* Project #3
  EGRE245 Spring 2014
  Jose Ramirez */

#include <stdio.h>
#include <math.h>

int main (void)
{
	printf("Proj. #3 - Jose Ramirez\n\n");
	
	int a=0; // user Inputs A
	int b=0; // user Input B
	
	int c=0; // Division variable 
	int d,e,f,g,h,i,j,k,l,m,n,o,p,q,r =0; //modulus operator variables 0-15
	
	printf("Enter a decimal (base 10) number between 0 and 32767: ");
	scanf("%d",&a);
	
	printf("Base to convert to?: ");
	scanf("%d",&b);
	
	printf("%d in base %d: ",a,b);
	
//remainders	
	d=a%b;
	
	c=a/b;
	e=c%b;
	
	c=c/b;
	f=c%b;
   
	c=c/b;
	g=c%b;
   
	c=c/b;
	h=c%b;
  
	c=c/b;
	i=c%b;
   
	c=c/b;
	j=c%b;
   
	c=c/b;
	k=c%b;
   
	c=c/b;
	l=c%b;
   
	c=c/b;
	m=c%b;
   
	c=c/b;
	n=c%b;
   
	c=c/b;
	o=c%b;
   
	c=c/b;
	p=c%b;
   
	c=c/b;
	q=c%b;
   
	c=c/b;
	r=c%b;
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",r,q,p,o,n,m,l,k,j,i,h,g,f,e,d);

	return 0;
	
}
