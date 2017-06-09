prog1 : hw1.o hw1_functions.o
	gcc hw1.o hw1_functions.o -o prog1

hw1.o: hw1.c
	gcc -c hw1.c

hw1_functions.o: hw1_functions.c
	gcc -c hw1_functions.c

clean:
	rm *.o prog*
