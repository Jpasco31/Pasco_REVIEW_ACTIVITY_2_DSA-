#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list){  //initialize list
    
    NodePtr node1 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node2 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node3 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node4 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node5 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node6 = (NodeType*)malloc(sizeof(NodeType));

    node1->data = 21;
    node2->data = 2;
    node3->data = 15;
    node4->data = 26;
    node5->data = 4;
    node6->data = 15;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    *list = node1;
}

List newList(){     //create new list (this is a sorted list)
    NodePtr head = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node2 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node3 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node4 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node5 = (NodeType*)malloc(sizeof(NodeType));
    NodePtr node6 = (NodeType*)malloc(sizeof(NodeType));

    head->data = 2;
    node2->data = 4;
    node3->data = 15;
    node4->data = 15;
    node5->data = 21;
    node6->data = 26;

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    return head;
}

//changed to pointer type
NodePtr createNode(DATA data){  //create a new individual dnode by dynamic memory allocation
    NodePtr node = (NodeType*)malloc(sizeof(NodeType));
    if(node == NULL){
        return NULL;
    }
    node->data = data;
    node->next = NULL;

    return node;
}

void displayList(List list){        //display list function
    NodePtr current;

    current = list;

    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

bool insertFront(List *list, DATA item){    //insert front function
    NodePtr newNode = createNode(item);
    if(newNode == NULL){
        return false;
    }

    newNode->next = *list;
    *list = newNode;

    return true;
}

bool insertRear(List *list, DATA item){     //insert Rear function
    NodePtr newNode = createNode(item);
    if(newNode == NULL){
        return false;
    }

    NodePtr current = *list;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;

    return true;
}

bool insertAt(List *list, DATA item, int loc){  //insert at a specific location in the list (NOTE: list counting start from 1-N )
    NodePtr(newNode) = createNode(item);

    if(newNode == NULL){
        return false;
    }

    if(loc == 1){
        insertFront(&(*list), item);
        return true;
    } else {
        int ctr = 1;
        NodePtr current = *list;

        while(current->next != NULL && ctr < loc - 1){
            current = current->next;
            ctr++;
        }

        newNode->next = current->next;
        current->next = newNode;
        return true;
    }
}

bool insertSorted(List *list, DATA data){       // insert a number on a sorted list function
    NodePtr newNode = createNode(data);

    NodePtr current = *list;
    NodePtr previous = NULL;

    while(current->next != NULL && current->data <= data){
        previous = current;
        current = current->next;
    }

    previous->next = newNode;
    newNode->next = current;

    return true;
}

bool searchItem(List list, DATA key){       //search for item in the list will return true if in the list
    NodePtr current = list;

    while(current->next != NULL){
        if(current->data == key){
            return true;
        }
        current = current->next;
    }

    return false;
}

int getItem(List list, DATA key){       //find the number of item that is equal to the key
    NodePtr current = list;
    int ctr = 0;

    while(current->next != NULL){
        if(current->data == key){
            ctr++;
        }
        current = current->next;
    }

    return ctr;
}

bool deleteFront(List *list){       //delete front function
    NodePtr temp = *list;

    (*list) = (*list)->next;

    free(temp);

    return true;
}

bool deleteRear(List *list){        //delete rear function
    NodePtr current = *list;
    NodePtr previous = NULL;

    while(current->next != NULL){
        previous = current;
        current = current->next;
    }

    previous->next = NULL;

    free(current);

    return true;
}

bool deleteAt(List *list, int loc){     //delete at a specific location function
    if(loc == 1){
        deleteFront(list);
        return true;
    }

    NodePtr current = *list;
    NodePtr previous = NULL;

    int ctr = 1;

    while(current->next != NULL && ctr < loc - 1){
        current = current->next;
        ctr++;
    }

    NodePtr toDelete = current->next;
    current->next = current->next->next;
    
    free(toDelete);

    return true;
}   

bool deleteItem(List *list, DATA key){      //delete the first item by key function
    NodePtr current = *list;
    NodePtr previous = NULL;

    int ctr = 1;
    while(current->data != key){
        previous = current;
        current = current->next;
        ctr++;
    }

    previous->next = current->next;
    free(current);
    
    return true;
}

int deleteAllItem(List *list, DATA key){        //delete all item that is equal to the key function
    NodePtr current = *list;
    NodePtr toDelete = NULL;
    NodePtr previous = NULL;

    while(current != NULL){
        if(current->data == key){
            if(previous != NULL){
                previous->next = current->next;
            } else {
                *list = current->next;
            }
            toDelete = current;
            current = current->next;
            free(toDelete);
        } else {
            previous = current;
            current = current->next;
        }
    }
    return true;
}

//newFunction
void freeList(List list){       //free the list function
    NodePtr current;

    current = list;

    while(current != NULL){
        current = current->next;
        free(list);
        list = current;
    }
}