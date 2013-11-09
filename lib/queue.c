#include"error.h"
#include"queue.h"

#include<stdio.h>
#include<stdlib.h>

struct COMMON_QUEUE *C_init_queue() {
	struct COMMON_QUEUE *new_queue;
	new_queue = malloc(sizeof(struct COMMON_QUEUE));
	if (new_queue==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_queue->next = NULL;
	new_queue->string = NULL;

	return new_queue;
}


