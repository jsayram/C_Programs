
/* Project #2
  EGRE245 Spring 2014
  Jose Ramirez */


#include <stdio.h>
#include <math.h>

int main (void)
{
	printf("Proj. #2 - Jose Ramirez\n\n");
	
	double r;
	double h;
	float volume;
	float surface;
	
	printf("Radius: ");
	scanf("%lf",&r);
    printf("Radius Entered: %f\n\n",r); 
	
	printf("Height: ");
	scanf("%lf",&h);
	printf("Height Entered: %f\n\n",h);
	
	volume= M_PI*r*r*h;
	surface=2*M_PI*r*r+2*M_PI*r*h;
	
	printf("Volume of Cylinder: %.2f\n",volume);
	printf("Surface Area of Cylinder: %.2f\n",surface);
	
	return 0;
	
}