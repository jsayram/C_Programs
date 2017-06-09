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
 * Description: Header file for C structure that holds two doubles 
 *					 and a character
 * 
 * Input: NA
 *
 * Output: NA
 ******************************************************************/

//coordinate system representations
#define RECT 'r'
#define POLAR 'p'

//Short-Hand for real and imaginary parts
#define RE p1
#define IM p2

//Short-hand for magnitude and angle parts
#define MAG p1
#define ANG p2

struct complex {
	double p1; //complex "part1" - either the real part (Cartesian) or MAG (polar)
	double p2; //complex "part2" - either the imaginary part or angle (degrees)
	char coord; //which coordinate system this complex number is in 'r' or 'p'
};