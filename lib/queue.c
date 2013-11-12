#include"error.h"
#include"queue.h"
#include"common.h"

#include<stdio.h>
#include<stdlib.h>

/* linked-list queue operations */
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
}

int C_get_queue_length(struct COMMON_QUEUE *q) {
	int count;
	count = 0;

	struct QUEUE_NODE *temp;
	temp = malloc(sizeof(struct QUEUE_NODE));
	if (temp==NULL) {
		return ERROR;
	}
	temp = q->q_node;

	while (temp->next!=NULL) {
		count += 1;
		temp = temp->next;
	}

	return count;
}

int C_enqueue(struct COMMON_QUEUE *q, char *in) {
	if (C_get_queue_length(q)>=QUEUE_MAX_SIZE) {
		fprintf(stderr, "Linked queue is full!!!");
		return ERROR;
	}
	struct QUEUE_NODE *new_node;
	struct QUEUE_NODE *temp;
	new_node = malloc(sizeof(struct QUEUE_NODE));
	temp = malloc(sizeof(struct QUEUE_NODE));
	if (new_node==NULL || temp==NULL) {
		return ERROR;
	}
	new_node->next = NULL;
	new_node->string = NULL;

	temp = q->q_node;

	while (temp->next!=NULL) {
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	new_node->string = in;

	return OK;
}

char *C_dequeue(struct COMMON_QUEUE *q) {
	if (C_get_queue_length(q)==0) {
		fprintf(stderr, "Linked queue is empty!!!");
		return NULL;
	}
	struct QUEUE_NODE *p;
	p = malloc(sizeof(struct QUEUE_NODE));
	if (p==NULL) {
		return NULL;
	}
	p->next = NULL;
	p->string = NULL;
	p = q->q_node;

	char *temp;
	temp = p->next->string;
	p = p->next;
	q->q_node->next = p->next;
	free(p);
	p->next = NULL;
	p->string = NULL;
	
	return temp;
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
		free(q->string[i]);
		q->string[i] = NULL;
	}
	q->size = 0;
	q->top = q->base = 0;
}

int CQ_is_queue_empty(struct CYCLIC_QUEUE *q) {
	if (q->size==0) {
		return YES;
	}

	return NO;
}

int CQ_is_queue_full(struct CYCLIC_QUEUE *q) {

	return NO;
}

void CQ_enqueue(struct CYCLIC_QUEUE *q, char *in) {
	/*if (CQ_is_queue_full(q)==YES) {
		fprintf(stderr, "Cyclic queue is full!!!");
		return;
	}*/
	q->string[q->top] = in;
	q->top = (q->top + 1) % q->size;

}

char *CQ_dequeue(struct CYCLIC_QUEUE *q) {
	if (CQ_is_queue_empty(q)==YES) {
		fprintf(stderr, "Cyclic queue is empty!!!");
		return NULL;
	}
	char *temp;
	temp = q->string[q->base];
	q->base = (q->base - 1) % q->size;

	return temp;
}
