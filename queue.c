#include <stdio.h>
#include <stdlib.h>

// A linked list (LL) node to store a queue entry 
struct node
{
	int key;
	struct node *next;
};

// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct queue
{
	struct node *front, *rear;
};

// A utility function to create an empty queue 
struct queue* createqueue()
{
	struct queue* q = (struct queue*) malloc (sizeof(struct queue));
	q->front = q->rear = NULL;
	return q;
}

// A utility function to create a new linked list node.
struct node* newnode(int k)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// The function to add a key k to q 
void insert(struct queue* q, int k)
{
	struct node* temp = newnode(k);
	if (q->rear == NULL)
	{
		q->front = q->rear = temp; 
		return; 
	}
	q->rear->next = temp; 
	q->rear = temp;
}

// Function to remove a key from given queue q 
void remove_node(struct queue* q)
{
	struct node* temp;
	/* If queue is empty, return NULL. */
	if (q->front == NULL)
		return; 

	// Store previous front and move front one node ahead 
	temp = q->front; 

	q->front = q->front->next; 

	// If front becomes NULL, then change rear also as NULL 
	if (q->front == NULL)
		q->rear = NULL;

	free(temp); 
}

// Driver Program to test anove functions 
int main()
{
	struct queue* q;
	q = createqueue(); 
	insert(q, 10); 
	insert(q, 20); 
	remove_node(q); 
	remove_node(q); 
	insert(q, 30); 
	insert(q, 40); 
	insert(q, 50); 
	remove_node(q); 
	printf("Queue Front : %d \n", q->front->key); 
	printf("Queue Rear : %d \n", q->rear->key); 
	return 0; 
} 
