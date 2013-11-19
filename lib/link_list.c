#include"link_list.h"
#include"error.h"
#include"common.h"

#include<stdio.h>
#include<stdlib.h>

/* single linked list */
struct LINK_LIST *init_link_list() {
	struct LINK_LIST *new_link = malloc(sizeof(struct LINK_LIST));
	if (new_link==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_link->string = NULL;
	new_link->next = NULL;

	return new_link;
}

void destroy_link_list(struct LINK_LIST *link) {
	struct LINK_LIST *temp = init_link_list();
	while(link!=NULL) {
		temp = link;
		link = link->next;
		free(temp);
		temp->next = NULL;
		temp->string = NULL;
	}
}

int is_empty(struct LINK_LIST *link) {
	if (link->next==NULL) {
		return YES;
	}
	return NO;
}

int get_length(struct LINK_LIST *link) {
	int count;
	count = 0;

	while(link->next!=NULL) {
		count += 1;
		link = link->next;
	}

	return count;
}

char *get_element(struct LINK_LIST *link, int pos) {
	int i;

	if (is_empty(link)==YES) {
		return NULL;
	}
	if (pos <= 0 || pos > get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		exit(1);
	}
	else {
		for (i = 0; i < pos; ++i) {
			link = link->next;
		}
	}
	return link->string;
}

int create(struct LINK_LIST *link, char *in) {
	if (get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Link list is full!!!");
		return ERROR;
	}
	else {
		struct LINK_LIST *new_node;
		new_node = init_link_list();
		if (new_node==NULL) {
			return ERROR;
		} 
		new_node->next = link->next;
		link->next = new_node;
		new_node->string = in;
	}

	return OK;
}

int tail_create(struct LINK_LIST *link, char *in) {
	if (get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Link list is full!!!");
		return ERROR;
	}
	else {
		while (link->next!=NULL) {
			link = link->next;
		}
		struct LINK_LIST *new_node;
		new_node = init_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		link->next = new_node;
		new_node->string = in;
	}
	
	return OK;
}

int insert(struct LINK_LIST *link, int pos, char *in) {
	int i;

	if (get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Link list is full!!!");
		return ERROR;
	}
	else {
		if (pos <= 0 || pos > get_length(link)) {
			fprintf(stderr, "Invalid position");
			return ERROR;
		}
		else {
			for (i = 1; i <= pos-1; ++i) {
				link = link->next;
			}
			struct LINK_LIST *new_node;
			new_node = init_link_list();
			if (new_node==NULL) {
				return ERROR;
			}
			new_node->next = link->next;
			link->next = new_node;
			new_node->string = in;
		}
	}

	return OK;
}

int del(struct LINK_LIST *link, int pos) {
	int i;

	if (is_empty(link)==YES) {
		fprintf(stderr, "Link list is empty!!!");
		return ERROR;
	}
	else {
		if (pos <= 0 || pos > get_length(link))	 {
			fprintf(stderr, "Invalid position!!!");
			return ERROR;
		}
		else {
			for (i = 1; i <= pos-1; ++i) {
				link = link->next;
			}
			struct LINK_LIST *temp;
			temp = init_link_list();
			if (temp==NULL) {
				return ERROR;
			}
			temp = link->next;
			link->next = temp->next;
			free(temp);
			temp->next = NULL;
			temp->string = NULL;
		}
	}

	return OK;
}

int find(struct LINK_LIST *link, char *key) {
	int pos;
	pos = 0;

	if (is_empty(link)==YES) {
		return -1;
	}
	while(link!=NULL) {
		if (link->string==key) {
			return pos;
		}
		else {
			pos += 1;
			link = link->next;
		}
	}

	return -1;
}

char *get_next(struct LINK_LIST *link, char *key) {
	if (is_empty(link)==YES) {
		return NULL;
	}
	while(link->next!=NULL) {
		if (link->string==key) {
			return link->next->string;
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

/* double linked list */
struct DOUBLE_LINK_LIST *init_double_link_list() {
	struct DOUBLE_LINK_LIST *new_link = malloc(sizeof(struct DOUBLE_LINK_LIST));
	if (new_link==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_link->string = NULL;
	new_link->pre = NULL;
	new_link->next = NULL;

	return new_link;
}

void D_destroy_link_list(struct DOUBLE_LINK_LIST *link) {
	struct DOUBLE_LINK_LIST *temp = init_double_link_list(); /* TODO */
	while (link!=NULL) {
		temp = link;
		link = link->next;
		free(temp);
		temp->next = NULL;
		temp->pre = NULL;
		temp->string = NULL;
	}
}

int D_is_empty(struct DOUBLE_LINK_LIST *link) {
	if (link->next==NULL) {
		return YES;
	}

	return NO;
}

int D_get_length(struct DOUBLE_LINK_LIST *link) {
	int count;
	count = 0;
	
	while (link->next!=NULL) {
		count += 1;
		link = link->next;
	}

	return count;
}

char *D_get_element(struct DOUBLE_LINK_LIST *link, int pos) {
	int i;
	
	if (D_is_empty(link)==YES) {
		return NULL;
	}
	if (pos <= 0 || pos > D_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		return NULL;
	}
	else {
		for (i = 0; i < pos; ++i) {
			link = link->next;
		}
	}

	return link->string;
}

int D_create(struct DOUBLE_LINK_LIST *link, char *in) {
	if (D_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Double link list is full!!!");
		return ERROR;
	}
	else {
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		new_node->pre = link;
		link->next = new_node;
		if(new_node->next!=NULL) {
			new_node->next->pre = new_node;
		}
		new_node->string = in;
	}

	return OK;
}

int D_tail_create(struct DOUBLE_LINK_LIST *link, char *in) {
	if (D_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Double link list is full!!!");
		return ERROR;
	}
	else {
		while(link->next!=NULL) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		new_node->pre = link;
		link->next = new_node;
		new_node->string = in;
	}

	return OK;
}

int D_insert(struct DOUBLE_LINK_LIST *link, int pos, char *in) {
	int i;

	if (D_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Double link list is full!!!");
		return ERROR;
	}
	else {
		for (i = 1; i <= pos-1; ++i) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		new_node->next = link->next;
		new_node->pre = link;
		link->next = new_node;
		if (new_node->next!=NULL) {
			new_node->next->pre = new_node;
		}
		new_node->string = in;
	}

	return OK;
}

int D_del(struct DOUBLE_LINK_LIST *link, int pos) {
	int i;

	if (D_is_empty(link)==YES) {
		fprintf(stderr, "Double link list is empty!!!");
		return ERROR;
	}
	else {
		if (pos <=0 || pos > D_get_length(link)) {
			return ERROR;
		}
		for (i = 1; i <= pos-1; ++i) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *temp;
		temp = init_double_link_list();
		if (temp==NULL) {
			return ERROR;
		}
		temp = link->next;
		link->next = temp->next;
		link->next->pre = link;
		free(temp);
		temp->next = NULL;
		temp->pre = NULL;
		temp->string = NULL;
	}

	return 0;
}

int D_find(struct DOUBLE_LINK_LIST *link, char *key) {
	int pos;
	pos = 0;
	
	if (D_is_empty(link)==YES) {
		return -1;
	}
	while (link!=NULL) {
		if (link->string==key) {
			return pos;
		}
		else {
			link = link->next;
			pos += 1;
		}
	}

	return -1;
}

char *D_get_next(struct DOUBLE_LINK_LIST *link, char *key) {
	if (D_is_empty(link)==YES) {
		return NULL;
	}
	while (link->next!=NULL) {
		if (link->string==key) {
			return link->next->string;
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

char *D_get_pre(struct DOUBLE_LINK_LIST *link, char *key) {
	if (D_is_empty(link)==YES) {
		return NULL;
	}
	while(link!=NULL) {
		if (link->string==key) {
			return link->pre->string;
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

/* cyclic double linked list */
struct DOUBLE_LINK_LIST *init_cyclic_double_link_list() {
	struct DOUBLE_LINK_LIST *new_link = malloc(sizeof(struct DOUBLE_LINK_LIST));
	if (new_link==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_link->string = NULL;
	new_link->next = new_link;
	new_link->pre = new_link;

	return new_link;
}

void CD_destroy_link_list(struct DOUBLE_LINK_LIST *link) {
	struct DOUBLE_LINK_LIST *temp = init_cyclic_double_link_list();
	if (temp==NULL) {
		return;
	}
	//struct DOUBLE_LINK_LIST *temp1 = init_cyclic_double_link_list();
	/*if (temp==NULL || temp1==NULL) {
		return;
	}
	while(link->next!=link) {
		link = link->next;
	}
	temp = link->next;
	free(link);
	link->next = NULL;
	link->pre = NULL;
	link->string = NULL;

	while(temp!=NULL) {
		temp1 = temp;
		temp = temp->next;
		free(temp1);
		temp1->next = NULL;
		temp1->pre = NULL;
		temp1->string = NULL;
	}*/

	struct DOUBLE_LINK_LIST *head = init_cyclic_double_link_list();
	if (head==NULL) {
		return;
	}
	head = link;
	link = link->next;
	while(link!=head) {
		temp = link;
		link = link->next;
		free(temp);
		temp->next =NULL;
		temp->pre = NULL;
		temp->string = NULL;
	}
	free(head);
	head->next = NULL;
	head->pre = NULL;
	head->string = NULL;

}

int CD_is_empty(struct DOUBLE_LINK_LIST *link) {
	if (link->next==link && link->pre==link) {
		return YES;
	}

	return NO;
}

int CD_get_length(struct DOUBLE_LINK_LIST *link) {
	int count;
	count = 0;

	struct DOUBLE_LINK_LIST *head = init_cyclic_double_link_list();
	if (head==NULL) {
		return -1;
	}
	head = link;

	while (link->next!=head) {
		count += 1;
		link = link->next;
	}

	return count;
}

int CD_create(struct DOUBLE_LINK_LIST *link, char *in) {
	if (CD_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Cyclic double linked list is full!!!");
		return ERROR;
	}
	struct DOUBLE_LINK_LIST *new_node;
	new_node = init_cyclic_double_link_list();
	if (new_node==NULL) {
		return ERROR;
	}
	new_node->pre = link;
	new_node->next = link->next;
	if (link->next==link) {
		link->pre = new_node;
	}
	link->next = new_node;
	new_node->string = in;

	return 0;
}

int CD_tail_create(struct DOUBLE_LINK_LIST *link, char *in) {
	if (CD_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Cyclic double linked list is full!!!");
		return ERROR;
	}
	struct DOUBLE_LINK_LIST *head = init_cyclic_double_link_list();
	if (head==NULL) {
		return ERROR;
	}
	head = link;

	while (link->next!=head) {
		link = link->next;
	}
	struct DOUBLE_LINK_LIST *new_node;
	new_node = init_cyclic_double_link_list();
	if (new_node==NULL) {
		return ERROR;
	}
	new_node->next = head;
	link->next = new_node;
	new_node->pre = link;
	head->pre = new_node;
	new_node->string = in;

	return OK;
}

int CD_insert(struct DOUBLE_LINK_LIST *link, int pos, char *in) {
	int i;

	if (CD_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Cyclic double link list is full!!!");
		return ERROR;
	}
	struct DOUBLE_LINK_LIST *head;
	head = init_cyclic_double_link_list();
	if (head==NULL) {
		return ERROR;
	}
	if (pos<=0 || pos-1 > CD_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		return ERROR;
	}
	else {
		for (i = 1; i <= pos-1; ++i) {
			link = link->next;
		}
		struct DOUBLE_LINK_LIST *new_node;
		new_node = init_cyclic_double_link_list();
		if (new_node==NULL) {
			return ERROR;
		}
		if (link->next==head) {
			new_node->next = head;
			link->next = new_node;
			new_node->pre = link;
			head->pre = new_node;
		}
		else {
			new_node->next = link->next;
			new_node->pre = link;
			link->next = new_node;
			new_node->next->pre = link;
		}
		new_node->string = in;
	}

	return OK;
}

char *CD_get_element(struct DOUBLE_LINK_LIST *link, int pos) {
	int i;

	if (CD_is_empty(link)==YES) {
		return NULL;
	}
	if (pos<=0 || pos > CD_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		return NULL;
	}
	else {
		for (i = 1; i <= pos; ++i) {
			link = link->next;
		}
	}

	return link->string;
}

int CD_del(struct DOUBLE_LINK_LIST *link, int pos) {
	int i;

	struct DOUBLE_LINK_LIST *head;
	struct DOUBLE_LINK_LIST *temp;
	head = init_cyclic_double_link_list();
	temp = init_cyclic_double_link_list();
	if (head==NULL || temp==NULL) {
		return ERROR;
	}
	head = link;

	if (CD_is_empty(link)==YES) {
		fprintf(stderr, "Cyclic double link list is empty!!!");
		return ERROR;
	}
	if (pos<=0 || pos > CD_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		return ERROR;
	}
	else {
		for (i = 1; i <= pos-1; ++i) {
			link = link->next;
		}
		temp = link->next;
		if (temp->next==head) {
			link->next = head;
			head->pre = link;
		}
		else {
			link->next = temp->next;
			link->next->pre = link;
		}
		free(temp);
		temp->next = NULL;
		temp->pre = NULL;
		temp->string = NULL;
	}

	return OK;
}

int CD_find(struct DOUBLE_LINK_LIST *link, char *key) {
	int pos;
	pos = 1;  /* we set pos is 1, because it skip the head node */

	if (CD_is_empty(link)==YES) {
		return -1;
	}
	struct DOUBLE_LINK_LIST *head;
	head = init_cyclic_double_link_list();
	if (head==NULL) {
		return ERROR;
	}
	head = link;
	link = link->next;

	while(link!=head) {
		if (link->string==key) {
			return pos;
		}
		pos += 1;
		link = link->next;
	}

	return -1;
}

char *CD_get_next(struct DOUBLE_LINK_LIST *link, char *key) {
	if (CD_is_empty(link)==YES) {
		return NULL;
	}
	struct DOUBLE_LINK_LIST *head;
	head = init_cyclic_double_link_list();
	if (head==NULL) {
		return NULL;
	}
	head = link;
	link = link->next;

	while (link!=head) {
		if (link->string==key) {
			if (link->next==head) {
				return link->next->next->string;
			}
			else {
				return link->next->string;
			}
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

char *CD_get_pre(struct DOUBLE_LINK_LIST *link, char *key) {
	if (CD_is_empty(link)==YES) {
		return NULL;
	}
	struct DOUBLE_LINK_LIST *head;
	head = init_cyclic_double_link_list();
	if (head==NULL) {
		return NULL;
	}
	head = link;
	link = link->next;

	while (link!=head) {
		if (link->string==key) {
			if (link->pre==head) {
				return link->pre->pre->string;
			}
			else {
				return link->pre->string;
			}
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

/* cyclic signly linked list */
struct LINK_LIST *init_cyclic_link_list() {
	struct LINK_LIST *new_link;
	new_link = malloc(sizeof(struct LINK_LIST));
	if (new_link==NULL) {
		fprintf(stderr, "Insufficient memory!!!");
		return NULL;
	}
	new_link->next = new_link;
	new_link->string = NULL;

	return new_link;
}

void CS_destroy_link_list(struct LINK_LIST *link) {
	struct LINK_LIST *head;
	struct LINK_LIST *temp;
	head = init_cyclic_link_list();
	temp = init_cyclic_link_list();

	if (head==NULL || temp==NULL) {
		return;
	}
	head = link;
	link = link->next;
	
	while (link!=head) {
		temp = link;
		link = link->next;
		free(temp);
		temp->next = NULL;
		temp->string = NULL;
	}
	free(head);
	head->next = NULL;
	head->string = NULL;
}

int CS_get_length(struct LINK_LIST *link) {
	int count;
	count = 0;

	struct LINK_LIST *head;
	head = init_cyclic_link_list();
	if (head==NULL) {
		return -1;
	}
	head = link;

	while (link->next!=head) {
		count += 1;
		link = link->next;
	}

	return count;
}

int CS_is_empty(struct LINK_LIST *link) {
	if (link->next==link) {
		return YES;
	}

	return NO;
}

int CS_tail_create(struct LINK_LIST *link, char *in) {
	if (CS_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Cyclic singly linked list is full!!!");
		return ERROR;
	}
	struct LINK_LIST *head;
	head = init_cyclic_link_list();
	if (head==NULL) {
		return ERROR;
	}
	head = link;

	while(link->next!=head) {
		link = link->next;
	}
	struct LINK_LIST *new_node;
	new_node = init_cyclic_link_list();
	if (new_node==NULL) {
		return ERROR;
	}
	new_node->next = link->next;
	link->next = new_node;
	new_node->string = in;

	return OK;
}

int CS_create(struct LINK_LIST *link, char *in) {
	if (CS_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Cyclic singly linked list is full!!!");
		return ERROR;
	}

	struct LINK_LIST *new_node;
	new_node = init_cyclic_link_list();
	if (new_node==NULL) {
		return ERROR;
	}
	new_node->next = link->next;
	link->next = new_node;
	new_node->string = in;

	return OK;
}

int CS_insert(struct LINK_LIST *link, int pos, char *in) {
	if (CS_get_length(link)>=STRING_SIZE) {
		fprintf(stderr, "Cyclic singly linked list is full!!!");
		return ERROR;
	}
	if (pos <= 0 || pos-1 > CS_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		return ERROR;
	}
	int i;

	struct LINK_LIST *head;
	struct LINK_LIST *new_node;
	head = init_cyclic_link_list();
	new_node = init_cyclic_link_list();
	if (new_node==NULL || head==NULL) {
		return ERROR;
	}
	head = link;

	for (i = 1; i <= pos-1; ++i) {
		link = link->next;
	}
	if (link->next==head) {
		new_node->next = head;
	}
	else {
		new_node->next = link->next;
	}
	link->next = new_node;
	new_node->string = in;

	return OK;
}

int CS_del(struct LINK_LIST *link, int pos) {
	if (CS_is_empty(link)==YES) {
		fprintf(stderr, "Cyclic singly linked list is empty!!!");
		return ERROR;
	}
	if (pos <= 0 || pos > CS_get_length(link)) {
		fprintf(stderr, "Invalid position!!!");
		return ERROR;
	}
	int i;

	struct LINK_LIST *temp;
	temp = init_cyclic_link_list();
	if (temp==NULL) {
		return ERROR;
	}
	for (i = 1; i <= pos-1; ++i) {
		link = link->next;
	}
	temp = link->next;

	link->next = temp->next;
	free(temp);
	temp->next = NULL;
	temp->string = NULL;

	return OK;
}

char *CS_get_element(struct LINK_LIST *link, int pos) {
	int i;

	if (CS_is_empty(link)==YES) {
		return NULL;
	}
	if (pos <= 0 || pos > CS_get_length(link)) {
			fprintf(stderr, "Invalid position!!!");
			return NULL;
		}
	else {
		for (i = 1; i <= pos; ++i) {
			link = link->next;
		}
	}

	return link->string;
}

/* TODO bugs here */
int CS_find(struct LINK_LIST *link, char *key) {
	if (CS_is_empty(link)==YES) {
		return -1;
	}
	struct LINK_LIST *head;
	head = init_cyclic_link_list();
	if (head==NULL) {
		return -1;
	}
	head = link;
	link = link->next;

	int pos;
	pos = 0;

	while(link!=head) {
		if (link->string==key) {
			return pos;
		}
		else {
			pos += 1;
			link = link->next;
		}
	}
	
	return -1;
}

char *CS_get_next(struct LINK_LIST *link, char *key) {
	struct LINK_LIST *head;
	head = init_cyclic_link_list();
	if (head==NULL) {
		return NULL;
	}
	head = link;
	link = link->next;

	while (link!=head) {
		if (link->string==key) {
			if (link->next==head) {
				return link->next->next->string;
			}
			else {
				return link->next->string;
			}
		}
		else {
			link = link->next;
		}
	}

	return NULL;
}

