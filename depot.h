#ifndef SPL_DEPOT_H
#define SPL_DEPOT_H

struct  	Product{
  int serial_no;
};

#define 	STACK_SIZE_LIMIT   3

typedef struct DepotImplementation * 	Depot;

typedef struct DNodeImplementation* D_Node;


Depot 	create_depot ();

void 	delete_depot (Depot depot);

void 	push_depot (Depot depot, Product *product);

int 	get_count (Depot depot);

Product * 	pop_depot (Depot depot);


#endif
