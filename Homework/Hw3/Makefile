prog3 : hw3.o hw3_functions.o
	gcc hw3.o hw3_functions.o -o prog3

hw3.o: hw3.c hw3.h
	gcc -c hw3.c

hw3_functions.o: hw3_functions.c hw3_functions.h
	gcc -c hw3_functions.c

clean:
	rm *.o prog*
