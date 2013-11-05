#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#define STRING_SIZE 4096

struct LINK_LIST {
	char *string;
	struct LINK_LIST *next;
}link_list;

struct DOUBLE_LINK_LIST {
	char *string;
	struct DOUBLE_LINK_LIST *pre;
	struct DOUBLE_LINK_LIST *next;
}double_link_list;

/* single linked list operations */
struct LINK_LIST *init_link_list();
void destroy_link_list(struct LINK_LIST *);
int is_empty(struct LINK_LIST *);
int get_length(struct LINK_LIST *);
char *get_element(struct LINK_LIST *, int );
int create(struct LINK_LIST *, char *);
int tail_create(struct LINK_LIST *, char *);
int insert(struct LINK_LIST *, int, char *);
int del(struct LINK_LIST *, int);

/* double linked list operations */
struct DOUBLE_LINK_LIST *init_double_link_list();
void D_destroy_link_list(struct DOUBLE_LINK_LIST *);
int D_is_empty(struct DOUBLE_LINK_LIST *);
int D_get_length(struct DOUBLE_LINK_LIST *);
char *D_get_element(struct DOUBLE_LINK_LIST *, int );
int D_create(struct DOUBLE_LINK_LIST *, char *);
int D_insert(struct DOUBLE_LINK_LIST *, int, char *);
int D_del(struct DOUBLE_LINK_LIST *, int );

#endif
