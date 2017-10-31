#include <conio.h>
#include <malloc.h>
#include <stdio.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* createQueue() {
	return (struct Node*)NULL;
}

void enqueue(struct Node** start, int data) {
	if ((*start) == NULL) {
		struct Node* newnode = malloc(sizeof(struct Node));
		newnode->data = data;
		newnode->next = NULL;
		*start = newnode;
	}
	else {
		struct Node* copy = *start;
		struct Node* newnode;
		while(copy->next != NULL)
			copy = copy->next;

		newnode = malloc(sizeof(struct Node));
		newnode->data = data;
		newnode->next = NULL;
		copy->next = newnode;
	}
}

int dequeue(struct Node** start) {
	if ((*start)->next == NULL) {
		int data = (*start)->data;
		free(*start);
		*start = NULL;
		return data;
	}
	else {
		int data = (*start)->data;
		struct Node* ptr = (*start)->next;
		free(*start);
		*start = ptr;
		return data;
	}
}


void traverse_queue(struct Node* start) {
	printf("%d->", start->data);
	while(start->next != NULL) {
		start = start->next;
		printf("%d->", start->data);
	}
}

int** createGraph(int n) {
	int i;
	int** rows = malloc(sizeof(int*) * n);
	for(i = 0; i < n; i++)
		rows[i] = malloc(sizeof(int) * n);
	return rows;
}

void add_edge(int** graph, int from, int to) {
	graph[from][to] = 1;
}

void traverse_graph(int** graph, int number_of_nodes, int node) {
	struct Node* queue = createQueue();
	int i;
	int* visited_state = malloc(sizeof(int) * number_of_nodes);

	for(i = 0; i < number_of_nodes; i++)
		visited_state[i] = 0;

	enqueue(&queue, node);
	while(queue != NULL) {
		node = dequeue(&queue);
		if (visited_state[node] != 1) {
			for(i = 0; i < number_of_nodes; i++) {
				if (graph[node][i] == 1) {
					enqueue(&queue, i);
				}
			}
		    printf("%d ", node);
		}
		visited_state[node] = 1;
	}

    free(visited_state);
}

void main() {

	int number_of_nodes, i, j, choice;
	int** graph;

    clrscr();

	printf("Number of nodes: ");
	scanf("%d", &number_of_nodes);
	graph = createGraph(number_of_nodes);

    for(i = 0; i < number_of_nodes; i++) {
        for(j = 0; j < number_of_nodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("1: add_edge, 2: traverse, -1: exit");

	while(1) {
		printf("Choice: ");
		scanf("%d", &choice);
		if (choice == -1)
			break;
		switch(choice) {
			int from, to, start;
			case 1:
				printf("Enter from, to: ");
				scanf("%d%d", &from, &to);
				if (from >= number_of_nodes || to >= number_of_nodes) {
					printf("Node not found!");
				}
				else {
					add_edge(graph, from, to);
				}
				break;
			case 2:
				printf("Enter start: ");
				scanf("%d", &start);
				printf("Traversed graph: ");
				traverse_graph(graph, number_of_nodes, start);
				break;
			default:
				printf("1: add_edge, 2: traverse, -1: exit");
				break;
		}

	}

    getch();
}

/** Output
Number of nodes: 9
1: add_edge, 2: traverse, -1: exitChoice: 1
Enter from, to: 0 1
Choice: 1
Enter from, to: 0 3
Choice: 1
Enter from, to: 0 4
Choice: 1
Enter from, to: 1 2
Choice: 1
Enter from, to: 1 4
Choice: 1
Enter from, to: 2 5
Choice: 1
Enter from, to: 3 4
Choice: 1
Enter from, to: 3 6
Choice: 1
Enter from, to: 4 5
Choice:
1
Enter from, to: 4 7
Choice: 1
Enter from, to: 6 2
Choice: 1
Enter from, to: 7 8
Choice: 2
Enter start: 0
Traversed graph: 0 1 3 4 2 6 5 7 8 Choice: -1
*/
