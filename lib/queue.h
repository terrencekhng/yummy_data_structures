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

struct CYCLIC_QUEUE {
	char *string[QUEUE_MAX_SIZE];
	int size;
	int base;
	int top;
}cyclic_queue;

/* linked-list queue */
struct COMMON_QUEUE *C_init_queue();
void C_destroy_queue(struct COMMON_QUEUE *);
int C_enqueue(struct COMMON_QUEUE *, char *);
char *C_dequeue(struct COMMON_QUEUE * );
int C_get_queue_length(struct COMMON_QUEUE * );

/* cyclic queue */
void CQ_init_queue(struct CYCLIC_QUEUE *, int );
void CQ_destroy_queue(struct CYCLIC_QUEUE *);
void CQ_enqueue(struct CYCLIC_QUEUE *, char *);
char *CQ_dequeue(struct CYCLIC_QUEUE *);
int CQ_get_queue_length(struct CYCLIC_QUEUE *);
int CQ_is_queue_empty(struct CYCLIC_QUEUE *);
int CQ_is_queue_full(struct CYCLIC_QUEUE *);

#endif
