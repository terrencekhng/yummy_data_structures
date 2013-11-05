#include"stack.h"
#include"error.h"

#include<stdio.h>
#include<stdlib.h>

/* common stack operations */
int init_stack(struct COMMON_STACK *new_stack, int stack_size) {
	
	char *new_string;
	new_string = (char *)malloc(sizeof(char)*stack_size);
	if (new_string==NULL) {
		fprintf(stderr, "Insufficient memory");
		return ERROR;
	}
	new_stack->size = stack_size;
	new_stack->string = new_string;
	new_stack->top = -1;
	
	return OK;
}

void destroy_stack(struct COMMON_STACK *stack) {
	free(stack->string);

	stack->string = NULL;
	stack->top = -1;
	stack->size = 0;
}

int is_stack_empty(struct COMMON_STACK *stack) {
	if (stack->top==-1) {
		return YES;
	}
	return NO;
}

int is_stack_full(struct COMMON_STACK *stack) {
	if (stack->top==stack->size-1) {
		return YES;
	}
	return NO;
}

void push(struct COMMON_STACK *stack, char in) {
	if (is_stack_full(stack)==YES) {
		fprintf(stderr, "Stack is full!!!");
		return;
	}
	else {
		stack->string[++stack->top] = in;
	}
}

char pop(struct COMMON_STACK *stack) {
	if (is_stack_empty(stack)==YES) {
		fprintf(stderr, "Stack is empty!!!");
		return ERROR;
	}
	else {
		return stack->string[stack->top--];
	}
}


/* string stack operations */
int S_init_stack(struct STRING_STACK *new_stack, int stack_size) {
	char *new_string[stack_size];
	int i;
	for (i = 0; i < stack_size; ++i) {
		new_string[i] = (char *)malloc(sizeof(char) * STRING_SIZE);
		if (new_string[i]==NULL) {
			fprintf(stderr, "Insufficient memory!!!");
			return ERROR;
		}
		else {
			new_stack->string[i] = new_string[i];
		}
	}

	new_stack->size = stack_size;
	new_stack->top = -1;

	return OK;
}

void S_destroy_stack(struct STRING_STACK *stack) {
	int i;
	for (i = 0; i < stack->size; ++i) {
		stack->string[i] = NULL;
		free(stack->string[i]);
	}

	stack->top = -1;
	stack->size = 0;
}

int S_is_stack_empty(struct STRING_STACK *stack) {
	if (stack->top==-1) {
		return YES;
	}
	return NO;
}

int S_is_stack_full(struct STRING_STACK *stack) {
	if (stack->top==stack->size-1) {
		return YES;
	}
	return NO;
}

void S_push(struct STRING_STACK *stack, char *in) {
	if (S_is_stack_full(stack)==YES) {
		fprintf(stderr, "Stack is full!!!");
		return;
	}
	else {
		stack->string[++stack->top] = in;
	}
}

char *S_pop(struct STRING_STACK *stack) {
	if (S_is_stack_empty(stack)==YES) {
		fprintf(stderr, "Stack is empty!!!");
		return NULL;
	}
	else {
		return stack->string[stack->top--];
	}
}

