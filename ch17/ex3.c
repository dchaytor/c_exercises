/*	write a function to delete an element of a double-linked list	*/

#include <stdio.h>
#include <stdlib.h>

static struct node {
	struct node* next;
	struct node* prev;
	char c;
};
static struct node* head = NULL;
static struct node* tail = NULL;

// could maybe use a refactor
void dnode(struct node** condemned)	{
	// handle head and tail case separately
	if (*condemned == head)	{
		head = head -> next;
		free(head -> prev);
		head -> prev = NULL;		
	} else if (*condemned == tail)	{
		tail = tail -> prev;
		free(tail -> next);
		tail -> next = NULL;		
	} else {	// doesn't handle case where tail ref broken
		struct node* thisnode = head;	
		while(thisnode != tail)	{
			if (thisnode == *condemned)	{
				(thisnode -> prev) -> next = thisnode -> next;
				(thisnode -> next) -> prev = thisnode -> prev;
				free(*condemned);
				break;
			}	
			thisnode = thisnode -> next;	
		}
	}
}

// adds new node at head of list
struct node* addhead(char data)	{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if (head != NULL)	{
		head -> prev = newnode;
		newnode -> next = head;
	} else {
		tail = newnode;	
		newnode -> next = NULL;
	}
	head = newnode;
	newnode -> prev = NULL;
	newnode -> c = data;
	return newnode;
}

//adds new node at tail of list
struct node* addtail(char data)	{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if (tail != NULL)	{
		tail -> next = newnode;
		newnode -> prev = tail;
	} else {
		head = newnode;
		newnode -> prev = NULL;
	}
	tail = newnode;	
	newnode -> next = NULL;
	newnode -> c = data;
	return newnode;
}

// could maybe do this more efficiently
void clearlist()	{
	struct node* thisnode = head;
	struct node* nextnode = head;
	while(thisnode != NULL)	{
		nextnode = thisnode -> next;
		free(thisnode);
		thisnode = nextnode;
	}
}

void printlist()	{
	struct node* thisnode = head;
	while (thisnode != NULL)	{
		printf("%c ", thisnode -> c);
		thisnode = thisnode -> next;
	}
	printf("\n");
}

int main()	{
	struct node *n1, *n2, *n3, *n4, *n5;
	n1 = addhead('4');
	n2 = addtail('5');
	n3 = addhead('3');
   	n4 = addtail('9');
	n5 = addhead('1');	
	printlist();
	
	dnode(&n2);
	printlist();	
	dnode(&n5);
	printlist();
	clearlist();
	return 0;
}
