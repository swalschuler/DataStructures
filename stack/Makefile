stackTest: stack.o test.o
	gcc -g -Wall -o stackTest test.o stack.o

stack.o: s_Stack.h s_Stack.c
	gcc -g -Wall -o stack.o s_Stack.c -c

test.o: stackTest.c
	gcc -g -Wall -o test.o stackTest.c -c

clean:
	rm *.o stackTest