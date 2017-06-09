 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
 
int main()
{  int num1=0;
    int num2=0;

	printf("Add a member to the list\n");
	printf("the first ?");
	scanf("%d",&num1);
	//fflush(stdin);
	printf("The second ?");
	scanf("%d",&num2);
	printf("This is num1: %d, Num2: %d",num1,num2);
}