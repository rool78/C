#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};

void printList(struct Node* list){
    printf("\nValor: %d", list->value);

    if(list->next != NULL){
        printList(list->next);
    }   
}

void printListNoRecursive(struct Node* n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->value); 
        n = n->next; 
    } 
} 

/* Given a reference (pointer to pointer) to the head of a list 
and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	/* 2. put in the data */
	new_node->value = new_data; 

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref); 

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/*TODO Insert after
 We are given pointer to a node, and the new node is inserted after the given node.*/
void insertAfter(struct Node* prev_node, int new_data){

}

/*TODO Append
Add a node at the end*/
void append(struct Node** head_ref, int new_data){
    
}

// Program to create a simple linked 
// list with 3 nodes 
int main(){
    printf("Playing with my Linked List");
    
    struct Node* head = NULL; 

    push(&head, 78);
    push(&head,33);
    printList(head);

    return 0;
}

