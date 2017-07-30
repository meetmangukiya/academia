/**
 * Problem Definition:
 *   Implementation of Singly Linked List (SLL)
 *
 * Aim: Create a Singly Linked List (SLL) and implement following operations using menu
 * driven program in C.
 * 1. createSLL( )
 * 2. insertBegin( )
 * 3. insertAfter( )
 * 4. deleteEnd( )
 * 5. traverse( )
 */

#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createSLL() {
    return (struct Node*)NULL;
}

void traverse(struct Node* start) {
    if (start == NULL) {
        printf("List is empty.");
        return;
    }
    while(start->next != NULL) {
        printf("%d->", start->data);
        start = start->next;
    }
    printf("%d\n", start->data);
}

void insertBegin(int data, struct Node** head) {
    struct Node* start = *head;

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    if (start == NULL)
        newnode->next = NULL;
    else
        newnode->next = start;
    *head = newnode;
}

void insertEnd(int data, struct Node** head) {
    struct Node* start = *head;

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (start == NULL) {
        *head = newnode;
        return;
    }

    while(start->next != NULL) {
        start = start->next;
    }
    start->next = newnode;
}

void insertAfter(int data, int existing, struct Node** head) {
    struct Node* start = *head;
    if (start == NULL) {
        printf("ERROR: List is empty");
        return;
    }

    while(start->data != existing && start->next != NULL) {
        start = start->next;
    }
    if (start->data != existing) {
        printf("%d not found in list", existing);
        return;
    }

    if (start->next == NULL) {
        insertEnd(data, head);
    }
    else {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = start->next;
        start->next = newnode;
    }
}

void deleteBegin(struct Node** head) {
    struct Node* start = *head;
    if (start == NULL) {
        printf("ERROR: List is empty, cannot delete.");
    }
    else if (start->next == NULL) {
        *head = NULL;
        free(start);
    }
    else {
        *head = start->next;
        free(start);
    }
}

void deleteEnd(struct Node** head) {
    struct Node* start = *head;
    if (start == NULL) {
        printf("ERROR: List is empty, cannot delete.");
    }
    else if (start->next == NULL){
        *head = NULL;
        free(start);
    }
    else {
        while(start->next->next != NULL) {
            start = start->next;
        }
	free(start->next);
	start->next = NULL;
    }
}

void main() {
    struct Node* start = createSLL();
    char helpString[] = "1: insertBegin, 2: insertEnd, 3: deleteBegin, 4: deleteEnd, 5: insertAfter, 6: display, -1: exit";

    clrscr();
    puts(helpString);

    while(1) {
	int choice, data, existing;
	printf("Choice: ");
	scanf("%d", &choice);
	if (choice == -1) break;

	switch(choice) {
	    case 1:
		printf("Data to add to the beginning: ");
		scanf("%d", &data);
		insertBegin(data, &start);
		break;
	    case 2:
		printf("Data to add at the end: ");
		scanf("%d", &data);
		insertEnd(data, &start);
		break;
            case 3:
                deleteBegin(&start);
                break;
            case 4:
                deleteEnd(&start);
                break;
            case 5:
                printf("Enter new element, existing element: ");
                scanf("%d%d", &data, &existing);
                insertAfter(data, existing, &start);
                break;
	    case 6:
		traverse(start);
		break;
	    default:
		puts(helpString);
	}
    }

    getch();
}

/**Output

Choice: 2
Data to add at the end: 7
Choice: 6
4->3->2->1->7
Choice: 3
Choice: 6
3->2->1->7
Choice: 4
Choice: 6
3->2->1
Choice: 5
Enter new element, existing element: 2 4
4 not found in listChoice: 5
Enter new element, existing element: 4 2
Choice: 6
3->2->4->1
Choice: 3
Choice: 3
Choice: 3
Choice: 3
Choice: 3
ERROR: List is empty, cannot delete.Choice:
6
List is empty.Choice: -1
*/
