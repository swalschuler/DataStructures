#include "s_Stack.h"

//******************************************************************************
//  Structs
//******************************************************************************
struct Stack
{
  int top;
  int arraySize;
  void **array;
};

//******************************************************************************
//  Static functions
//******************************************************************************
static void doubleStackSize(s_Stack stack)
{
  void **oldArray = stack->array;
  void **newArray = (void *)malloc(sizeof(void *) * stack->arraySize * 2);
  memcpy(newArray, oldArray, stack->arraySize * sizeof(void *));
  stack->array = newArray;
  stack->arraySize = stack->arraySize * 2;
  free(oldArray);
}

//******************************************************************************
//  Public functions
//******************************************************************************
s_Stack createStack(int intialSize)
{
  s_Stack newStack = (s_Stack)malloc(sizeof(struct Stack));
  newStack->top = -1;
  newStack->arraySize = intialSize;
  newStack->array = (void **)malloc(sizeof(void *) * intialSize);
  return newStack;
}

int pushStack(s_Stack stack, void *data)
{
  if (!stack || !data)
    return 0;

  const int newPosition = stack->top + 1;

  if (newPosition >= stack->arraySize)
    doubleStackSize(stack);

  stack->array[newPosition] = data;
  stack->top++;
  return 1;
}

void *peekStack(s_Stack stack)
{
  if (!stack || stack->top < 0)
    return NULL;
  return stack->array[stack->top];
}

void *popStack(s_Stack stack)
{
  if (!stack || stack->top < 0)
    return NULL;
  return stack->array[stack->top--];
}

int isEmpty(s_Stack stack)
{
  if (!stack)
    return -1;

  if (stack->top >= 0)
    return 0;
  return 1;
}