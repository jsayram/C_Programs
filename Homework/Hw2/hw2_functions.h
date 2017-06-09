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
 * Description: Header file that contains the function prototypes 
 *
 * Input: NA
 * Output: NA
 ******************************************************************/
void enter_point(struct complex *point);//user enters complex coordinate in polar or rectangular
void print_point(struct complex point);//print complex point in correct coordinate system (p) or (r)
void convert_point(struct complex *point);//converts point from polar to rectangular, and vice versa. 
int read_point(FILE *infile, struct complex *point);//reads a complex number from an input file. 

//outputs all parts of the complex number in polar and rectangular
double real(struct complex point);//outputs the real part of the point, if polar converts to rectangular for real. 
double imag(struct complex point);//outputs the imaginary part of the point, if polar converts to rectangular for real. 
double mag(struct complex point);//outputs the magnitude of the point, if rectangular converts to polar for magnitude.
double ang(struct complex point);//outputs the angle(degrees) of the point, if rectangular converts to polar for angle(degrees)

//arithmetic operations for complex numbers, results coordinate is specified by the user, or defaulted to rectangular.  
void add(struct complex *result, struct complex a, struct complex b);//adds two complex numbers in either polar or rectangular, or a combination. 
void sub(struct complex *result, struct complex a, struct complex b);//subtracts two complex numbers in either polar or rectangular, or a combination. 
void mult(struct complex *result, struct complex a, struct complex b);//multiplies two complex numbers in either polar or rectangular, or a combination. 
void divi(struct complex *result, struct complex a, struct complex b);//divides two complex numbers in either polar or rectangular, or a combination. 

//User specifies coordinate system polar or rectangular for complex number 
void user_coord_choice(struct complex result,char pick);