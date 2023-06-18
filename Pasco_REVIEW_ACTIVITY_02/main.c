#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList.c"

//All functions are tested below
//new functions were also added and created aside form the boilerplate

int main(int argc, char *argv[]) {
	List head;

	// initList(&head);
	initList(&head);
	displayList(head);

	//Insert Front - 13
	insertFront(&head, 13);
	printf("Insert Front - 13\n");
	displayList(head);

	//Insert Rear - 12
	insertRear(&head, 12);
	printf("Insert Rear - 12\n");
	displayList(head);

	//Insert At - 9
	insertAt(&head, 9, 3);
	printf("Insert At 3 - 9\n");
	displayList(head);

	//Insert Sorted - 11
	List sortedList = newList();
	printf("Insert Sorted - 11\n");
	displayList(sortedList);
	insertSorted(&sortedList, 11);
	displayList(sortedList);

	//Search Item - 9
	bool inList = searchItem(head, 9);
	printf("Search Item - 9\n");
	if(inList){
		printf("The item is in the list\n");
	} else {
		printf("The item is not in the list\n");
	}

	//Get number of items - 15
	int counter = getItem(head, 15);
	printf("Get Item - 15\n");
	printf("There are %d number of items in the list\n", counter);

	//Delete Front 
	deleteFront(&head);
	printf("Delete Front - 13\n");
	displayList(head);

	//Delete Rear 
	deleteRear(&head);
	printf("Delete Rear - 12\n");
	displayList(head);

	//Delete At pos 3
	deleteAt(&head, 3);
	printf("Delete At 3 - 2\n");
	displayList(head);

	//Delete first Item 26
	deleteItem(&head, 26);
	printf("Delete Item - 26\n");
	displayList(head);

	//Delete All item 15
	deleteAllItem(&head, 15);
	printf("Delete Item - 15\n");
	displayList(head);

	freeList(head);
	freeList(sortedList);
	
	return 0;
}
