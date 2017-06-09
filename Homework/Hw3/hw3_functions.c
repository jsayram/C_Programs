/******************************************************************
 * Program #: Homework #3
 *
 * Programmer: Jose Ramirez
 *
 * Due Date: October 3,2014
 *
 * EGRE 246, Fall 2014       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid 
 *         on this program.
 *
 * Description: C source file that contains the implementation of all the functions
 * 				used in program, functions populate a linked list and send it to main
 *				,smaller functions implemented to simplify the flow of main. 
 *
 * Input: NA
 * Output: Linked list returned, and int and double values used in main.
 ******************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
 
 #include "hw3.h"
 #include "hw3_functions.h"
/*Function populates a NuLL liked list with a first name , last name , account number, and balance 
  passed as arguments to the function, this function will be called from the file populate becasuse 
  that is when the list will start off as empty, each scan will take in the arguments and point the right 
  value of node*/
 struct list *addMember(struct list *bank, char *lastName,char *firstName,int accountNum, double balance){
	struct list *temp; //initializes a temporary variable used to add to head of the list
	//this will only be called once at the beginning
	if(bank == NULL) { //this if statement is only executed if the list when passed is empty 
						 //and it will populate the list with the first entry. 
		bank = (struct list*)malloc(sizeof(struct list));
		strcpy(bank->LAST,lastName); //adds last name to the list 
		strcpy(bank->FIRST,firstName); //adds first name to the list
		bank->ACCT = accountNum; //adds account number to the list
		bank->BAL=balance; //adds balance to the list
		bank->next = NULL; //sets the next pointer equal to null 
		return(bank); //returns updated list to main. 
	}
	else //when the list is not empty this will be executed populating the list
	{ 
		temp=(struct list*)malloc(sizeof(struct list));
		strcpy(temp->LAST,lastName);
		strcpy(temp->FIRST,firstName);
		temp->ACCT= accountNum;
		temp->BAL=balance;
		temp->next =bank;
		return(temp); //list will be returned to main added to head 
	}
}
/* function used for user option to input a new member ,when list is not NULL, since the list will
be populated already , it does not need to check if is null and will simply add a new member and 
return it to be used in main*/
struct list *user_add(struct list *bank,char *lName, char *fName,int acct,double bal)
{   struct list *temp;
	temp=(struct list*)malloc(sizeof(struct list));
	strcpy(temp->LAST,lName);
	strcpy(temp->FIRST,fName);
	temp->ACCT=acct;
	temp->BAL=bal;
	temp->next=bank;
	return(temp);
}
/* prompts the user for and account number*/
int account(){
 int acct;
	fflush(stdin); /*flushes buffer to make sure no characters left to mess with 
					 return to menu options*/
	printf("Enter new member's account number ?");
	scanf("%d",&acct);
	return acct;
}
/* prompts the user for and balance number*/
double balance(){
   double bal;
	fflush(stdin);/*flushes buffer to make sure no characters left to mess with 
					 return to menu options*/
	printf("Enter new member's balance ?");
	scanf("%lf",&bal);
	return bal;
}
/* Print function to print to the SCREEN ,it takes in the head of the list and 
iterates through the list printing out each of the elements 
In order of Last Name, First Name, Account Number,and Balance*/
void print_Bank(struct list *bank){
    struct list *temp;
	printf("\nLast\t\tFirst\t\tAccount\tBalance\n");
	printf("-------------------------------------------------\n");
	temp = bank; 
	while(temp != NULL){
		printf("%-16s",temp->LAST);
		printf("%-16s",temp->FIRST);
		printf("%d\t",temp->ACCT);
		printf("%.2lf\n",temp->BAL);
	    temp = temp->next;
	}
}
/* Print function to print to the a FILE,it takes in the head of the list and 
iterates through the list printing out each of the elements 
In order of Last Name, First Name, Account Number,and Balance*/
void print_File(FILE *outFile,struct list *bank){
   struct list *temp;
	temp = bank; 
	while(temp != NULL){
		fprintf(outFile,"%-16s\t",temp->LAST);
		fprintf(outFile,"%-16s\t",temp->FIRST);
		fprintf(outFile,"%d\t",temp->ACCT);
		fprintf(outFile,"%.2lf\n",temp->BAL);
	    temp = temp->next;
	}
}
/*Error Check for input file making sure the file exist
 if the file is not found it will loop back and prompt user for the 
 file name untill it does not equal null*/
void errorCheck(FILE *dataFile){  
   if (dataFile == NULL) 
    {
       printf("\n[ERROR]- That file does not exist,\nPlease input a different data file. \n");
	   main();
	   exit(0);
    }
} 
/*Menu options for the user*/
void menu()
{	printf("\nEnter Option:\n");
	printf("\t(0) Write output file and exit\n");
	printf("\t(1) Print The List\n");
	printf("\t(2) Add new account at head of the list\n");
	printf("\t(3) Calculate and display average balance\n");
	printf("\t\tChoice?: ");
}