/******************************************************************
 * Program #: Homework #3
 *
 * Programmer: Robert H. Klenke
 *
 * Due Date: October 3,2014
 *
 * EGRE 246, Fall 2014       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: Header file for C structure that holds two strings, 
 *					 an int, a double, and a next pointer 
 *
 * Input:NA
 *
 * Output:NA
 *
 ******************************************************************/

#define MAX_SIZE 100

//Short-Hand for last name and first name
#define LAST lastName
#define FIRST firstName

//short hand for account number and balance
#define ACCT accountNum
#define BAL balance

//linked list structure
struct list{
	char lastName[MAX_SIZE];
	char firstName[MAX_SIZE];
	int accountNum;
	double balance;
	struct list *next;
};

