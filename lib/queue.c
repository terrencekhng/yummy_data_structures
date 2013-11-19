#include"error.h"
#include"queue.h"
#include"common.h"

#include<stdio.h>
#include<stdlib.h>


void C_init_queue(struct COMMON_QUEUE *new_queue) {
	new_queue->front = new_queue->rear = malloc(sizeof(struct QUEUE_NODE));
	if (!new_queue->front) {
		fprintf(stderr, "Insufficient memory!!!");
		return;
	}
	new_queue->front->next = NULL;
}

void C_destroy_queue(struct COMMON_QUEUE *q) {
	while (q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

int C_enqueue(struct COMMON_QUEUE *q, char *in) {
	struct QUEUE_NODE *new_node;
	new_node = malloc(sizeof(struct QUEUE_NODE));
	if (new_node==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return ERROR;
	}

	new_node->string = in;
	new_node->next = NULL;
	q->rear->next = new_node;
	q->rear = new_node;

	return OK;
}

char *C_dequeue(struct COMMON_QUEUE *q) {
	if (q->front==q->rear) {
		fprintf(stderr, "Linked-list queue is empty!!!");
		return NULL;
	}
	struct QUEUE_NODE *temp;
	char *out;

	temp = q->front->next;
	out = temp->string;
	if (q->rear==temp) {
		q->rear = q->front;
	}
	else {
		q->front->next = temp->next;
	}
	return out;
}

/* cyclic queue operations */
void CQ_init_queue(struct CYCLIC_QUEUE *new_queue, int queue_size) {
	char *new_string[queue_size];
	int i;

	for (i = 0; i < queue_size; ++i) {
		new_string[i] = (char *)malloc(sizeof(char) * STRING_SIZE);
		if (new_string[i]==NULL) {
			fprintf(stderr, "Insufficient memory!!!");
			return ;
		}
		else {
			new_queue->string[i] = new_string[i];
		}
	}
	new_queue->size = queue_size;
	new_queue->top = 0;
	new_queue->base = 0;

}

/*TODO free() bugs here*/
void CQ_destroy_queue(struct CYCLIC_QUEUE *q) {
	int i;
	
	for (i = 0; i < q->size; ++i) {
		q->string[i] = NULL;
		free(q->string[i]);
		//q->string[i] = NULL;
	}
	q->size = 0;
	q->top = q->base = 0;
}

int CQ_is_queue_empty(struct CYCLIC_QUEUE *q) {
	if (q->top==q->base) {
		return YES;
	}

	return NO;
}

int CQ_is_queue_full(struct CYCLIC_QUEUE *q) {
	if ((q->top+1)%q->size==q->base) {
		printf("now: %d\n", (q->top + 1)%q->size);
		return YES;
	}

	return NO;
}

int CQ_get_queue_length(struct CYCLIC_QUEUE *q) {
	/*if (CQ_is_queue_full(q)==YES) {
		return q->size;
	}
	else if (CQ_is_queue_empty(q)==YES) {
		return 0;
	}*/

	int count;
	count = 0;
	int pos;
	pos = q->base;

	while (pos<q->top) {
		pos  = (pos + 1) % q->size;
		count += 1;
	}

	return count;
}

void CQ_enqueue(struct CYCLIC_QUEUE *q, char *in) {
	if (CQ_is_queue_full(q)==YES) {
		fprintf(stderr, "Cyclic queue is full!!!");
		return;
	}
	printf("_%d_", q->top);
	q->string[q->top] = in;
	//printf("_%s_", q->string[q->top]);
	q->top = (q->top + 1) % q->size;

}

char *CQ_dequeue(struct CYCLIC_QUEUE *q) {
/*	if (CQ_is_queue_empty(q)==YES) {
		fprintf(stderr, "Cyclic queue is empty!!!");
		return NULL;
	}*/
	char *temp;
	temp = q->string[q->base];
	q->base = (q->base - 1) % q->size;

	return temp;
}
