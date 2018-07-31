#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct BTNode {
	struct BTNode* left;
	struct BTNode* right;
	struct BTNode* parent;
	int data;
};

struct BTNode createBST() {
	struct BTNode node;
	node.right = node.left = node.parent = node.data = NULL;
	return node;
};

void insert(struct BTNode* node, int data) {
	if (node->data == NULL) {
//		struct BTNode* newnode = (struct BTNode*)malloc(sizeof(BTNode));
		node->data = data;
		node->left = node->right = NULL;
	}
	else {
		if (data < node->data) {
			if (node->left == NULL) {
				struct BTNode* newnode = (struct BTNode*)malloc(sizeof(struct BTNode));
				newnode->data = data;
				newnode->left = newnode->right = NULL;
				newnode->parent = node;
				node->left = newnode;
			}
			else {
				insert(node->left, data);
			}
		}
		else {
			if (node->right == NULL) {
				struct BTNode* newnode = (struct BTNode*)malloc(sizeof(struct BTNode));
				newnode->data = data;
				newnode->right = newnode->left = NULL;
				newnode->parent = node;
				node->right = newnode;
			}
			else {
				insert(node->right, data);
			}
		}
	}
}

void traverse_node(struct BTNode* node) {
    /*if (node != NULL && node->data == NULL && node->parent == NULL) {*/
        /*printf("Tree is empty");*/
        /*return;*/
    /*}*/

	if (node != NULL) {
		traverse_node(node->left);
		printf("%d ", node->data);
		traverse_node(node->right);
	}
}

struct BTNode* search_tree(struct BTNode* root, int data) {
    if (root->data == data)
        return root;
    else {
        if (data < root->data) {
            if (root->left != NULL)
                search_tree(root->left, data);
            else
                return (struct BTNode*)NULL;
        }
        else {
            if (root->right != NULL)
                search_tree(root->right, data);
            else
                return (struct BTNode*)NULL;
        }
    }
}

void delete_node(struct BTNode* node) {
	if (node->left == NULL && node->right == NULL) {
        if (node->parent->left == node)
            node->parent->left = NULL;
        else
            node->parent->right = NULL;
		free(node);
	}
	else if (node->left != NULL && node->right != NULL) {
	    struct BTNode* copy;
    	copy = node->left;
		while(copy->right != NULL)
		    copy = copy->right;

        if (node->parent->left != NULL && node->parent->left == node) {
            node->parent->left = copy;
            copy->parent = node->parent;
        }
        else {
            node->parent->right = copy;
            copy->parent = node->parent;
        }

	    copy->left = node->left;
		copy->right = node->right;
        free(node);
	}
	else {
		if (node->left == NULL) {
			node->parent->right = node->right;
			node->right->parent = node->parent;
			free(node);
		}
		else {
			node->parent->left = node->left;
			node->left->parent = node->parent;
			free(node);
		}
	}
}

void main() {
	struct BTNode root = createBST();
	clrscr();

    printf("1: insert, 2: traverse, 3: search, 4: delete, -1: exit");

	while (1) {
		int choice;
		printf("Choice: ");
		scanf("%d", &choice);
		if (choice == -1) break;
		switch(choice) {
			int data;
			struct BTNode* found;
			case 1:
				printf("Data: ");
				scanf("%d", &data);
				insert(&root, data);
				break;
			case 2:
				traverse_node(&root);
				break;
			case 3:
			    printf("Data to be searched: ");
			    scanf("%d", &data);
			    found = search_tree(&root, data);
			    if (found == NULL)
			        printf("Data not found on tree.");
			    else
			        printf("Data found!");
			    break;
			case 4:
			    printf("Data to be deleted: ");
			    scanf("%d", &data);
			    found = search_tree(&root, data);
			    if (found != NULL) {
			        delete_node(found);
			    }
			    else {
			        printf("Data not found on tree.");
			    }
			    break;

			case -1:
				printf("1: insert, 2: traverse, 3: search, 4: delete, -1: exit");
				break;
		}
	}

	getch();
}

/** Output
1: insert, 2: traverse, 3: search, 4: delete, -1: exitChoice: 1
Data: 15
Choice: 1
Data: 10
Choice: 1
Data: 20
Choice: 1
Data: 8
Choice: 1
Data: 12
Choice: 1
Data: 18
Choice: 1 30
Data: Choice: 1
Data: 15
Choice: 1
Data: 19
Choice: 1
Data: 21
Choice: 2
8 10 12 15 18 19 20 21 30 Choice: 3
Data to be searched: 18
Data found!Choice: 3
Data to be searched: 35
Data not found on tree.Choice: 4
Data to be deleted: 30
Choice: 2
8 10 12 15 18 19 20 21 Choice:
-1
*/
