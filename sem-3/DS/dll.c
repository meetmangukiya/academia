#include <stdio.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

struct Node* createDLL() {
    return (struct Node*)NULL;
}

void insertBegin(int data, struct Node** st) {
    struct Node* start = *st;

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->previous = NULL;

    if (start == NULL) {
        newnode->next = NULL;
    }
    else {
        newnode->next = start;
        start->previous = newnode;
    }
    *st = newnode;
}

void display(struct Node* start) {
    if (start == NULL) {
        printf("List is empty.");
        return;
    }
    while(start->next != NULL) {
        printf("%d->", start->data);
        start = start->next;
    }
    printf("%d", start->data);
}

void deleteElement(int data, struct Node** st) {
    struct Node* start = *st;

    if (start == NULL) {
        printf("ERROR! List is empty.");
        return;
    }

    if (start->data == data) {
        *st = start->next;
        free(start);
        return;
    }

    while(start->data != data && start->next != NULL) {
        start = start->next;
    }
    if (start->data != data) {
        printf("ERROR! Element not found.");
        return;
    }

    start->previous->next = start->next;

    if (start->next != NULL) {
        start->next->previous = start->previous;
    }
    free(start);
}

void deleteBefore(int existing, struct Node** st) {
    struct Node* start = *st;

    if (start == NULL) {
        printf("ERROR! List is empty.");
        return;
    }

    if (start->data == existing) {
        printf("ERROR! There cannot be an element before the first element.");
        return;
    }

    if (start->next->data == existing) {
        start->next->previous = NULL;
        *st = start->next;
        free(start);
        return;
    }

    while(start->next->data != existing && start->next->next != NULL) {
        start = start->next;
    }

    if (start->next->data != existing) {
        printf("ERROR! Data not found.");
        return;
    }

    start->previous->next = start->next;
    start->next->previous = start->previous;
    free(start);
}

void main() {
    struct Node* start = createDLL();
    char helpString[] = "1: insertBegin, 2: deleteElement, 3: deleteBefore, 4: display, -1: exit";
    clrscr();
    puts(helpString);
    while (1) {
	int choice, data;
	printf("Choice: ");
	scanf("%d", &choice);
	if (choice == -1) break;
	switch(choice) {
            case 1:
                printf("Enter data to be added at the beginning: ");
                scanf("%d", &data);
                insertBegin(data, &start);
                break;
            case 2:
                printf("Enter element to be deleted: ");
                scanf("%d", &data);
                deleteElement(data, &start);
                break;
            case 3:
                printf("Enter element whose previous element has to be deleted: ");
                scanf("%d", &data);
                deleteBefore(data, &start);
                break;
            case 4:
                display(start);
		break;
	    default:
		puts(helpString);
		break;
	}
    }

    getch();
}

/** Output
Choice: 1
Enter data to be added at the beginning: 3
Choice: 1
Enter data to be added at the beginning: 4
Choice: 1
Enter data to be added at the beginning: 5
Choice: 4
5->4->3->2->1Choice: 2
Enter element to be deleted: 3
Choice: 4
5->4->2->1Choice: 2
Enter element to be deleted: 4
Choice: 2                                                                       
Enter element to be deleted: 1                                                  
Choice: 4                                                                       
5->2Choice: 3                                                                   
Enter element whose previous element has to be deleted: 2                       
Choice: 3                                                                       
Enter element whose previous element has to be deleted: 9                       
ERROR! Data not found.Choice: 4                                                 
2Choice: 2                                                                      
Enter element to be deleted: 2                                                  
Choice: 4                                                                       
List is empty.Choice: -1                                                        
                                                                                


*/