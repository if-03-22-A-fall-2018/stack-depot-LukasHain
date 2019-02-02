#include "stack.h"
#include "depot.h"
#include "stdlib.h"



struct SNodeImplementation {
  S_Node Next;
  void* data;
};

struct StackImplementation {
  S_Node head;
  int count;
};


Stack create_stack()
{
  Stack stack = (Stack)smalloc(sizeof(struct StackImplementation));
  stack->head = 0;
  stack->count = 0;
  return stack;
}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack)
{
  for (int i = 0; i < stack->count; i++) {
    S_Node head = stack->head;
    stack->head = head->Next;
    sfree(head);
  }
  sfree(stack);
}

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data)
{
  S_Node node = (S_Node)smalloc(sizeof(struct SNodeImplementation));
  node->data = data;
  node->Next = stack->head;
  stack->head = node;
  stack->count++;
}

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack)
{
  return stack->count;
}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void* pop_stack(Stack stack)
{
  S_Node del = stack->head;
  stack->head = del->Next;
  void* ret = del->data;
  sfree(del);
  stack->count--;
  return ret;
}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
*/
void* peek_stack(Stack stack)
{
  return stack->head->data;
}
