#ifndef _STACK_H
#define _STACK_H

#define STACK_SIZE 1024
#define STRING_SIZE 4096

struct COMMON_STACK {
	char *string;
	int size;
	int top;
}common_stack;

struct STRING_STACK {
	char *string[STACK_SIZE];
	int size;
	int top;
}string_stack;

/* common stack operations */
int init_stack(struct COMMON_STACK *, int );
void destroy_stack(struct COMMON_STACK *);
int is_stack_empty(struct COMMON_STACK *);
int is_stack_full(struct COMMON_STACK *);
void push(struct COMMON_STACK *, char);
char pop(struct COMMON_STACK *);

/* string stack operations */
int S_init_stack(struct STRING_STACK *, int );
void S_destroy_stack(struct STRING_STACK *);
int S_is_stack_empty(struct STRING_STACK *);
int S_is_stack_full(struct STRING_STACK *);
void S_push(struct STRING_STACK *, char *);
char *S_pop(struct STRING_STACK *);

#endif

