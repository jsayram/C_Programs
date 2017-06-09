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
 * Description: Implementation of linked list that holds a Last name, First name, Account Number
				and a Balance ,user has menu options, user may
 *				(0) Write linked list to an output file 
 *				(1) Print The list to the screen 
 *				(2) Add new account at head of the list.
 *				(3) Calculate and display Average balance.
 *
 * Input: User input starting .txt file to
 * 		  User may input their own account 
 *
 * Output: A "_out.txt" file user may also print to the screen 
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hw3.h"
#include "hw3_functions.h"

int main (void)
{ 	/*This is the file input*/
	FILE *dataFile=NULL,*outFile;//pointers for file input and output
	char dFile[MAX_SIZE];//to scan in the file name
	printf("Data File Name: "); //prompts user to enter data file
	scanf("%s",dFile); 
	dataFile = fopen(dFile,"r");
	/*Error check for file input,This will cause the program to exit it the 
	if the users file does not exist, and error will appear and the program will exit*/
	errorCheck(dataFile);
	//end of file input
    
	/*Various variables
	acct: variable for account number 
	choice: this is used for the flow of the program, based on the user input
			The menu options
	size: Variable to hold the size of the input string dFile name
		  used for the output file option of the program 
	count=0: A count variable initialized as zero to hold the value of members in the list
	         iterated every time a new member is scanned from a file or imputed by user 
	bal: balance variable holds the balance at every scan and user input.
	b_total: used for calculating the average balance*/
	int acct,choice,size,count=0;
	double bal,b_total=0;
	/* lname: holds the string for the last name
	   fname: holds the string for the first name*/
	char lName[MAX_SIZE],fName[MAX_SIZE];
	//struct to initialize a list called head to null, this will hold all the 
	//first names, last names ,accounts,and balances
	struct list *head=NULL;
	
	/*This scans the users input file, scanning two strings an integer and a double 
	int that order string string integer double from the file, at a time */
	while(fscanf(dataFile,"%s%s%d%lf",&lName,&fName,&acct,&bal)!=EOF)
	{   b_total+=bal; //at every scann this will add up the balances scanned and 
						//so bal will be scanned , placed in variable b_total;
		/*function to populate linked list with the lastname, firstname, account, and balance
		  user passes in head and the variables for each element at each scan it will create a link to the 
		  linked list and the list will be returned and added to head */
		head=addMember(head,lName,fName,acct,bal); 
	    count++; //counter variable to count how many times the file is scanned indicating 
				//how many members there are 
	}
	menu(); /*user menu options,prompts user what they would like to
			(0) Write linked list to an output file 
			(1) Print The list to the screen 
 			(2) Add new account at head of the list.
 			(3) Calculate and display Average balance.*/

	/*start of loop for the menu, at each loop it will prompt the user 
		what they would like to do based on the options above , that 
		choice is placed in the variable choice, and based on that choice it will
		go into the apropriate if statement*/
	while (scanf("%d",&choice))
	{	fflush(stdin); //flushes buffer for any \n characters" 
		if(choice==1){ //option (1) Print The list to the screen  
			print_Bank(head);/*function gets passed the head of the list and prints 
								the list to the screen*/
			fflush(stdin);/*flushes buffer to make sure no characters left to mess with 
							return to menu options*/
		}
		if(choice==2){// option (2) Add new account at head of the list.
			/*User will be promted to input a first and last name into variables lName and fName*/
			printf("Add a member to the list\n");
			printf("Enter new member's last name ?");
			scanf("%s",&lName);
			fflush(stdin);/*flushes buffer to make sure no characters left to mess with 
							return to menu options*/
			printf("Enter new member's first name ?");
			scanf("%s",&fName);
			acct=account();//this will prompt user for the account and passed back to variable acct
			bal=balance();//this will prompt user for balance and passed back variable bal
			/*once the new names are scanned, they are passed in with the head of the list, so a new 
			member can be added to the head of the list*/
			head=user_add(head,lName,fName,acct,bal);
			fflush(stdin);/*flushes buffer to make sure no characters left to mess with 
							return to menu options*/
			count++; //this iterates the member count
			b_total+=bal; //adds the balance to total balance of the list
		}
		if(choice==3){ //option (3) Calculate and display Average balance.
		    /*lets user know what is the memeber count and calculates the average by dividing the total 
			sum of balances by the member count ie:  b_total/count*/
			printf("There are %d members with an average balance of %.2lf\n",count,b_total/count);
			fflush(stdin); /*flushes buffer to make sure no characters left to mess with 
							return to menu options*/
		}
		if(choice==0)//option(0) Write linked list to an output file
		{	size= strlen(dFile); //gets the size of the string for the input file name
			dFile[size - 4] = 0; //subtracts 4 from the string to get rid of .txt extension and 
									//make room for the concatenation of "_out.txt" 
			strcat(dFile,"_out.txt"); //concatenates "_out.txt" to the end of the dFile name string
		    outFile=fopen(dFile,"w"); //with the dFile string updated to the new name of the file with the "_out.txt"
										//writes to the output file pointer
			print_File(outFile,head); //pointer passed in to print_file function with the head of the list which is written into 
										//the file Name_out.txt
			//This lets the user know that the file has been successfully outputted to the new file name
			printf("Accounts outputted to (%s)\n\t\t\nThank you\n\nProgram (Exit)\n",dFile);
			free(head);  //free head 
			fclose(dataFile); //closes inputfile
			fclose(outFile); //closes output
			exit(0); //gracefully exits
		}
		//if user does not choose any of the options listed it will let the user know it was not a valid entry
		if(choice!=0 && choice!=1 && choice!=2 && choice!=3)
		{
			printf("\nSorry, (%d) is not a valid entry please",choice);
		}
	menu(); /*If the user did not choose the correct option the while loop will keep going until
				one of the 4 options is selected (0),(1),(2),(3) , the loop will simply keep running till 
			    prompting the user for his options, similarly after the user chooses an option other than (0), 
				this menu() will execute, and the user may keep going adding members,calculating averages
  				or printing to screen*/ 
	}//end while loop
	//making sure the files are closed and memory freed for head. 
	free(head); 
	fclose(dataFile);
	fclose(outFile);
return 0; 
}


