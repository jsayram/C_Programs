prog2 : hw2.o hw2_functions.o
	gcc hw2.o hw2_functions.o -o prog2

hw2.o: hw2.c hw2.h
	gcc -c hw2.c

hw2_functions.o: hw2_functions.c hw2_functions.h
	gcc -c hw2_functions.c

clean:
	rm *.o prog*
