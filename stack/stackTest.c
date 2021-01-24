#include <stdio.h>
#include <assert.h>
#include "s_Stack.h"

int main()
{
  s_Stack stack = createStack(1);

  assert(isEmpty(NULL) == -1);
  assert(isEmpty(stack));

  int testInts[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i;
  for (i = 0; i < 10; i++)
  {
    pushStack(stack, testInts + i);
    printf("Pushed %i\n", *(int *)peekStack(stack));
  }

  assert(!isEmpty(stack));

  for (i = 0; i < 10; i++)
  {
    printf("Popped %i\n", *(int *)popStack(stack));
  }

  // If there is nothing in the stack, should return NULL
  assert(!popStack(stack));
  assert(!peekStack(stack));
  assert(isEmpty(stack));

  printf("Success.\n");

  return 0;
}