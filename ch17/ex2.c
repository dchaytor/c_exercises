/*	ex 17-2: 	write a function to delete an element of a linked list	*/

#include <stdio.h>
#include <stdlib.h>

static struct node {
	struct node *next;
	char c;
};
static struct node* head = NULL;

// pass pointer of data to add to list;
// adding at head by default
struct node* addNode(char data)	{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> next == NULL;
	if (head != NULL) 
		newnode -> next = head;
	newnode -> c = data;
	head = newnode;	
	return newnode;
}

// pass to function node to delete
void delNode(struct node** condemned)	{
	struct node* nextnode = head;
	struct node* thisnode = head;
	while (thisnode != NULL)	{
		nextnode = thisnode -> next;
		if (nextnode == *condemned)	{ // found node to kill
			thisnode -> next = nextnode -> next;
			free(nextnode); // assumes allocated with malloc
			break;	
		}	
		thisnode = nextnode;
	}
}

void printList()	{
	struct node* thisnode = head;
	while (thisnode != NULL)	{
		printf("%c ", thisnode -> c);
		thisnode = thisnode -> next;
	}
	printf("\n");
}

void clearList()	{
	struct node* thisnode = head;
	struct node* nextnode = head;
	while (thisnode != NULL)	{
		nextnode = thisnode -> next;
		delNode(&thisnode);
		thisnode = nextnode;
	}
}

int main()	{
	struct node* n1 = addNode('1');
	struct node* n2 = addNode('2');
	struct node* n3 = addNode('3');
	struct node* n4 = addNode('4');
	struct node* n5 = addNode('5');
	struct node* n6 = addNode('6');
	
	printList();
	delNode(&n2);
	printList();
	clearList();
	return 0;
}
