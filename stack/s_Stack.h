#ifndef S_STACK
#define S_STACK

/**
 *  Basic stack implementation using dynamic array.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Stack *s_Stack;

/**
 * Creates the stack and returns a pointer to it.
 * 
 * INPUT: Initial size for the dynamic array. 
 *
 * OUTPUT: Pointer to stack
 */
s_Stack createStack(int intialSize);

/**
 * Push data onto the stack.
 * 
 * INPUT: Stack pointer and pointer to data to be pushed
 * 
 * OUTPUT: 0 on NULL argument, 1 on success
 */
int pushStack(s_Stack stack, void *data);

/**
 * Returns a pointer to the first object on the stack.
 * 
 * INPUT: Stack pointer 
 * 
 * OUPUT: Pointer to the top element in the stack
 *        NULL if there is no top element
 */
void *peekStack(s_Stack stack);

/**
 * Returns a pointer to the first object on the stack and 
 * removes it from the stack
 * 
 * INPUT: Stack pointer
 * 
 * OUTPUT: Pointer to the top element in the stack
 *         NULL if there is no top element
 */
void *popStack(s_Stack stack);

/**
 * Returns value based on number of elements in the stack.
 * 
 * INPUT: Stack pointer.
 * 
 * OUTPUT: 0 if stack is empty,
 *         1 if stack has at least one element,
 *         -1 if NULL argument
 */
int isEmpty(s_Stack stack);

#endif // STACK