#include "stack.h"
#include "depot.h"
#include "stdlib.h"


struct DNodeImplementation {
  D_Node Next;
  Stack stack;
};

struct DepotImplementation {
  D_Node head;
  int count;
};


Depot 	create_depot ()
{
  Depot depot = (Depot)smalloc(sizeof(struct DepotImplementation));
  depot->head = 0;
  depot->count = 0;
  return depot;
}

void 	delete_depot (Depot depot)
{
  for (int i = 0; i < depot->count; i++) {
    D_Node head = depot->head;
    depot->head = head->Next;
    delete_stack(head->stack);
    sfree(head);
  }
  sfree(depot);
}

void 	push_depot (Depot depot, Product *product)
{
  if (depot->head == 0 || get_count(depot->head->stack) >= STACK_SIZE_LIMIT) {
    D_Node node = (D_Node)smalloc(sizeof(struct DNodeImplementation));
    node->stack = create_stack();
    push_stack(node->stack, product);
    node->Next = depot->head;
    depot->head = node;
      depot->count++;
  }
  else{
    push_stack(depot->head->stack, product);
  }
}

int 	get_count (Depot depot)
{
  return depot->count;
}

Product * 	pop_depot (Depot depot)
{
  void* x;
  x = pop_stack(depot->head->stack);
  if (get_count(depot->head->stack) <= 0) {
    D_Node del = depot->head;
    depot->head = depot->head->Next;
    sfree(del);
    depot->count--;
  }
  return (Product*)x;
}
