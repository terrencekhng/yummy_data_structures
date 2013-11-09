#ifndef _QUEUE_H
#define _QUEUE_H

#define QUEUE_MAX_SIZE 4096

struct QUEUE_NODE {
	char *string;
	struct QUEUE_NODE *next;
}queue_node;

struct COMMON_QUEUE {
	struct QUEUE_NODE *q_node;
}common_queue;

struct COMMON_QUEUE *C_init_queue();
void C_destroy_queue(struct COMMON_QUEUE *);
int C_enqueue(struct COMMON_QUEUE *, char *);
char *C_dequeue(struct COMMON_QUEUE * );
int C_get_queue_length(struct COMMON_QUEUE * );

#endif
