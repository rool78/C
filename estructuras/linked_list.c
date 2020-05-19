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
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = new_node;
    new_node->next = prev_node->next;

    prev_node->next = new_node;

}

/*TODO Append
Add a node at the end*/
void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = new_data;
    new_node->next = NULL;
    
    struct Node* n = (*head_ref);
    
    while(n->next != NULL){
        n = n->next;
    }

    if(n->next == NULL){
        n->next = new_node;
    }
}

void delete(struct Node** head_ref, int key){
    struct Node* n = (*head_ref);

    if((*head_ref)->value == key){

    }

    if(n->value == key){
        n->value = NULL;
        return;
    }

    while(n->next != NULL){
        if(n->next->value == key){
            //delete
            struct Node* tmp = n->next;
            if(tmp->next != NULL){
                n->next = tmp->next;
            }else{
                n->next = NULL;
            }
            free(tmp);
            return;
        }else{
            n = n->next;
        }
        
    }
}

// Program to create a simple linked 
// list with 3 nodes 
int main(){
    printf("Playing with my Linked List");
    
    struct Node* head = NULL; 

    push(&head, 78);
    push(&head,33);
    printList(head);

    printf("\nProbando Append:");

    append(&head, 57);
    append(&head, 23);
    printList(head);

    printf("\nProbando Delete:");


    delete(&head, 57);

    printList(head);

    return 0;
}

