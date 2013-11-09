#include"error.h"
#include"queue.h"

#include<stdio.h>
#include<stdlib.h>

struct COMMON_QUEUE *C_init_queue() {
	struct QUEUE_NODE *head;
	head = malloc(sizeof(struct QUEUE_NODE));
	if (head==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	struct COMMON_QUEUE *new_queue;
	new_queue = malloc(sizeof(struct COMMON_QUEUE));
	if (new_queue==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	head->next = NULL;
	head->string = NULL;

	new_queue->q_node = head;
	new_queue->top = -1;
	new_queue->base = -1;

	return new_queue;
}

void C_destroy_queue(struct COMMON_QUEUE *q) {
	struct QUEUE_NODE *temp;
	struct QUEUE_NODE *curr;
	temp = malloc(sizeof(struct QUEUE_NODE));
	curr = malloc(sizeof(struct QUEUE_NODE));
	if (temp==NULL || curr==NULL) {
		return;
	}
	curr = q->q_node;
	while(curr->next!=NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
		temp->next = NULL;
		temp->string = NULL;
	}
	q->top = -1;
	q->base = -1;
}

int C_get_queue_length(struct COMMON_QUEUE *q) {
	int count;
	count = 0;

	while (q->q_node->next!=NULL) {
		count += 1;
		q->q_node = q->q_node->next;
	}

	return count;
}

int C_enqueue(struct COMMON_QUEUE *q, char *in) {
	if (C_get_queue_length(q)>=QUEUE_MAX_SIZE) {
		fprintf(stderr, "Linked queue is full!!!");
		return ERROR;
	}
	struct QUEUE_NODE *new_node;
	new_node = malloc(sizeof(struct QUEUE_NODE));
	if (new_node==NULL) {
		return ERROR;
	}
	new_node->next = q->q_node->next;
	q->q_node->next = q->q_node;
	new_node->string = in;

	return OK;
}


