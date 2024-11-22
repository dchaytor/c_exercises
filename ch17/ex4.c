/*	write a function to delete an element of a tree	 */
/* -> going to assume this is a BST	*/

#include <stdio.h>
#include <stdlib.h>

static struct branch	{
	struct branch *left;
	struct branch *right;
	short data;
} *root = NULL;

struct branch *add(short data)	{
	struct branch *newbranch = (struct branch*)malloc(sizeof(struct branch));
	struct branch *thisbranch = root;
	if (root == NULL) root = newbranch;
	else	{
		while (thisbranch != NULL)	{ // traverse tree
			if (data <= thisbranch -> data)	{ // go left
				if (thisbranch -> left == NULL)	{
					thisbranch -> left = newbranch;	
					break;
				}
				else thisbranch = thisbranch -> left;
			}
			else	{ // go right
				if (thisbranch -> right == NULL)	{
					thisbranch -> right = newbranch;	
					break;
				}
				else thisbranch = thisbranch -> right;
			}	
		}
	}
	newbranch -> left = NULL;
	newbranch -> right = NULL;	
	newbranch -> data = data;
	return newbranch;
}

// could also add search by pointer but seems kinda useless
// searches through tree, and returns ptr to node if data present, else NULL
struct branch *search(short data)	{
	struct branch *branch = root;
	while (branch != NULL)	{
		if (branch -> data == data) break;
		branch = (branch -> data < data) ? branch->right : branch->left;
	}
	return branch;
}

void del(struct branch **badbranch)	{
	struct branch *repbranch = root;	
	// case for branch with no children
	if ((*badbranch) -> left == NULL && (*badbranch) -> right == NULL)	{
		repbranch = NULL;	
	} 
	// cases for branch with at least 1 child
	else	{
		if ((*badbranch) -> right == NULL)	{
			repbranch = (*badbranch) -> left;
		} else {
			repbranch = (*badbranch) -> right;
			while (repbranch -> left != NULL)	{
				repbranch = repbranch -> left;
			}
			repbranch -> left = (*badbranch) -> left;	
		}
	}

	// look for badbranch in tree to find node that points to it;
	// replace with new branch node
	if (*badbranch == root) 
		root = repbranch;
	else	{
		struct branch *thisbranch = root;
		while (thisbranch != NULL)	{
			if (thisbranch -> left == *badbranch)	{
				thisbranch -> left = repbranch;
				break;
			} else if (thisbranch -> right == *badbranch)	{
				thisbranch -> right = repbranch;		
				break;
			}
			
			// check data to see what next branch to search should be
			if (thisbranch -> data <= (*badbranch) -> data)	{
				thisbranch = thisbranch -> left;
			} else	{
				thisbranch = thisbranch -> right;	
			}
		}
	}
	*badbranch = NULL;	
	free(*badbranch);
}

void _printTree(struct branch *node, short pad)	{
	// print tree horizontally:
	// if next right node is null, print current node padded pad spaces + \n
	// recursively search through right nodes
	pad+=4;	
	if (node -> right != NULL)
		_printTree(node -> right, pad);

	printf("%*d\n", pad, node -> data); 
	
	// recursively search through left nodes
	if (node -> left != NULL)
		_printTree(node -> left, pad);
}

void printTree()	{
	if (root != NULL) _printTree(root, 0);	
}

void _clearTree()	{
	while (root != NULL)
		del(&root);
}

void _DELETE()	{
	int data;
	char buf[4];
	printf("  Input tree element to be deleted: ");
	fgets(buf, 4, stdin);
	
	if (sscanf(buf, "%d", &data) > 0)	{
		printf("  Attempting to delete a %d from the list:\n", data);
		struct branch *badbranch = search((short)data);
		if (badbranch == NULL)
			printf("  Could not find item %d in list\n", data);
		else del(&badbranch);
	} else printf("  Invalid input\n");
}

void _ADD()		{
	int data;
	char buf[4];
	printf("  Enter data to add to tree: ");
	fgets(buf, 4, stdin);
	if (sscanf(buf, "%d", &data) > 0)	{
		add(data);
		printf("  Added %d to the list\n", data);
	} else printf("  Invalid input\n");
}

void _SEARCH()	{
	int data;
	char buf[4];
	printf("  Enter data to look up in tree: ");
	fgets(buf, sizeof(buf), stdin);
	if (sscanf(buf, "%d", &data) > 0)	{
		struct branch *searchbranch = search((short)data);
		if (searchbranch == NULL)
			printf("  Could not find item %d in list\n", data);
		else
			printf("  %d was found in list\n", data);
	} else printf("  Invalid input\n");
}

// only considering values up to 999 to make printout nicer
// INPUT IS SUPER EASY TO OVERFLOW:
// 	- need to read to end of stdin after reading input into buffer
//    otherwise next getchar will just read overflow input
int main()	{
	char input = 'b';
	puts("BST test program:"); 
	while(input != 'q')	{
		printf("[A]DD/[D]ELETE/[S]EARCH/[P]RINT/[Q]UIT\t");
		input = getchar();
		getchar();	// trailing newline
		switch(input)	{
			case 'a':
			case 'A':
				_ADD();
				break;
			case 'd':
			case 'D':
				_DELETE();
				break;
			case 's':
			case 'S':
				_SEARCH();
				break;
			case 'p':
			case 'P':
				printf("\n");
				printTree();
				break;
			//case 'q':
			case 'Q':
				input = 'q';
				break;
		}
	}

	_clearTree();
	return 0;
}
