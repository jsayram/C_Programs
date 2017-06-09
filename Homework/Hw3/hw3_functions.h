/******************************************************************
 * Program #: Homework #3
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
 /*Functions to populate linked list, addMemeber takes a link list when is null
 and user_add adds a memeber to a non null list. */
 struct list *addMember(struct list *bank, char *lastName,char *firstName,int accountNum, double balance);
 struct list *user_add(struct list *bank,char *lName,char *fName,int acct,double bal);
 
 void print_Bank(struct list *bank);//Print to SCREEN 
 void print_File(FILE *outFile,struct list *bank); //PRINT TO FILE
 
 void errorCheck(FILE *dataFile);//error check for input file
 int account();//prompts user for account number
 double balance();//prompts user for balance number
 void menu();//prompts user with menu options
 

 