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

void _printTree(struct branch *node, int pad)	{
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
	short data;
	char buf[4];
	puts("Input tree element to be deleted: ");
	fgets(buf, 4, stdin);
	data = sscanf("%d", &data);
	printf("Attempting to delete a %d from the list:\n", data);
	struct branch *badbranch = search(data);	
	if (struct branch *badbranch = search(data) == NULL) 
		printf("Could not find item %d in list\n", data);
	else del(&badbranch);
}

void _ADD()		{

}

void _SEARCH	{

}

// only considering values up to 999 to make printout nicer
int main()	{
	char input;
	puts("BST test program:\n"); 
	while(input != 'q')	{
		puts("[A]DD/[D]ELETE/[S]EARCH/[P]RINT/[Q]UIT  ");
		input = getchar();
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
