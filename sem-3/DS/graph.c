/*#include <conio.h>*/
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
		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
		newnode->data = data;
		newnode->next = NULL;
		*start = newnode;
	}
	else {
		struct Node* copy = *start;
		struct Node* newnode;
		while(copy->next != NULL)
			copy = copy->next;

		newnode = (struct Node*)malloc(sizeof(struct Node));
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
	int** rows = (int**)malloc(sizeof(int*) * n);
	for(i = 0; i < n; i++)
		rows[i] = (int*)malloc(sizeof(int) * n);
	return rows;
}

void add_edge(int** graph, int from, int to) {
	graph[from][to] = 1;
}

void traverse_graph(int** graph, int number_of_nodes, int node) {
	struct Node* queue = createQueue();
	int i;
	int* visited_state = (int*)malloc(sizeof(int));

	for(i = 0; i < number_of_nodes; i++)
		visited_state[i] = 0;

	enqueue(&queue, node);
	while(queue != NULL) {
		/*printf("queue: ");*/
		/*traverse_queue(queue);*/
		node = dequeue(&queue);
	     //	printf("data: %d", node);
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
}

void main() {

	int number_of_nodes, i, j, choice;
	int** graph;

	/*clrscr();*/

	printf("Number of nodes: ");
	scanf("%d", &number_of_nodes);
	graph = createGraph(number_of_nodes);

    for(i = 0; i < number_of_nodes; i++) {
        for(j = 0; j < number_of_nodes; j++) {
            graph[i][j] = 0;
        }
    }

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
				printf("\nmatrix: \n");
				for(i = 0; i < number_of_nodes; i++) {
					for(j = 0; j < number_of_nodes; j++) {
						printf("%d ", graph[i][j]);
					}
					printf("\n");
				}
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

	/*getch();*/
}
