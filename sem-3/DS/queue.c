#include<stdio.h>
#include<conio.h>
#define SIZE 5

int QUEUE[SIZE];

struct Queue{
	int front;
	int rear;
	int counter;
	int data[SIZE];
};

struct Queue createQueue();
void enqueue(int element, struct Queue*);
int dequeue(struct Queue*);
void displayFront(struct Queue*);
void displayRear(struct Queue*);
int isFull(struct Queue*);
int count(struct Queue*);
int isEmpty(struct Queue*);

void main() {
	char helpString[100] = "1: enqueue, 2: dequeue, 3: displayRear, 4: displayFront, 5: count, -1: exit";
	struct Queue Q = createQueue();
	clrscr();
	puts(helpString);
	printf("Front, Rear, Count: %d %d %d", Q.front, Q.rear, Q.counter);
	while(1) {
		int choice, data;

		printf("\nChoice: ");
		scanf("%d", &choice);
		if (choice == -1) break;

		switch(choice) {
			case 1:
				if (!isFull(&Q)) {
					printf("Data to be enqueued: ");
					scanf("%d", &data);
					enqueue(data, &Q);
					printf("Rear, Front, Count: %d %d %d", Q.rear, Q.front, Q.counter);
				}
				else {
					printf("Queue Overflow");
				}
				break;
			case 2:
				if (!isEmpty(&Q)) {
					printf("Dequeued: %d", dequeue(&Q));
				}
				else {
					printf("Queue Underflow");
				}
				printf("\nRear, Front, Count: %d %d %d", Q.rear, Q.front, Q.counter);
				break;
			case 3:
				displayRear(&Q);
				break;
			case 4:
				displayFront(&Q);
				break;
			case 5:
				printf("Count: %d", count(&Q));
				break;
			default:
				puts(helpString);
		}
	}

	getch();
}

struct Queue createQueue() {
	struct Queue q;
	q.rear = q.front = -1;
	q.counter = 0;
	return q;
}

void enqueue(int data, struct Queue* q) {
	if (isFull(q)) {
		printf("Queue Overflow");
	}
	else {
		if (q->counter == 0) {
			// Enqueuing empty queue
			q->front = q->rear = 0;
		}
		else if (q->rear == SIZE - 1) {
			// Enqueued element at end of array
			q->rear = 0;
		}
		else {
			// Enqueued element in between in array
			q->rear += 1;
		}
		q->data[q->rear] = data;
		q->counter += 1;
	}
}

int dequeue(struct Queue* q) {
	if (isEmpty(q)) {
		printf("Queue Underflow");
		return -1;
	}
	else {
		int data = q->data[q->front];
		if (q->front == SIZE - 1) {
			// Front at end of array
			q->front = 0;
		}
		else {
			// Front in between of array
			q->front += 1;
		}
		q->counter -= 1;

		if (q->counter == 0) {
			// Only one element in Queue
			q->front = q->rear = -1;
		}

		return data;
	}
}

int count(struct Queue* q) {
	return q->counter;
}

int isFull(struct Queue* q) {
	return (q->counter == SIZE);
}

int isEmpty(struct Queue* q) {
	return (q->counter == 0);
}

void displayRear(struct Queue* q) {
	if (q->counter != 0) {
		printf("Rear: %d", (q->data[q->rear]));
	}
	else {
		printf("Queue is empty");
	}
}

void displayFront(struct Queue* q) {
	if (q->counter != 0) {
		printf("Front: %d", (q->data[q->front]));
	}
	else {
		printf("Queue is empty");
	}
}

/** Output
1: enqueue, 2: dequeue, 3: displayRear, 4: displayFront, 5: count, -1: exit
Front, Rear, Count: -1 -1 0
Choice: 1
Data to be enqueued: 1
Rear, Front, Count: 0 0 1
Choice: 1
Data to be enqueued: 2
Rear, Front, Count: 1 0 2
Choice: 1
Data to be enqueued: 3
Rear, Front, Count: 2 0 3
Choice: 1
Data to be enqueued: 4
Rear, Front, Count: 3 0 4
Choice: 1
Data to be enqueued: 5
Rear, Front, Count: 4 0 5
Choice: 1
Queue Overflow
Choice: 2
Dequeued: 1
Rear, Front, Count: 4 1 4
Choice: 1
Data to be enqueued: 23
Rear, Front, Count: 0 1 5
Choice: 2
Dequeued: 2
Rear, Front, Count: 0 2 4
Choice: 2
Dequeued: 3
Rear, Front, Count: 0 3 3
Choice: 2
Dequeued: 4
Rear, Front, Count: 0 4 2
Choice: 2
Dequeued: 5
Rear, Front, Count: 0 0 1
Choice: 2
Dequeued: 23
Rear, Front, Count: -1 -1 0
Choice: 2
Queue Underflow
Rear, Front, Count: -1 -1 0
Choice: -1
*/
