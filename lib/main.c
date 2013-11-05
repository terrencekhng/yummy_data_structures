#include"stack.h"
#include"error.h"
#include"link_list.h"

int main() {

	struct COMMON_STACK test;

	if(init_stack(&test, 5)==ERROR) {
		exit(1);
	}

	push(&test, '!');
	push(&test, 'd');
	push(&test, 'c');
	push(&test, 'b');
	push(&test, 'a');
	
	int i;
	for (i = 0; i < test.size; ++i) {
		printf("%c", pop(&test));
	}
	printf("\n");

	destroy_stack(&test);

	struct STRING_STACK test1;

	if (S_init_stack(&test1, 5)==ERROR) {
		exit(1);
	}

	S_push(&test1, "!");
	S_push(&test1, "world");
	S_push(&test1, "the");
	S_push(&test1, "are");
	S_push(&test1, "we");

	for (i = 0; i < test1.size; ++i) {
		printf("%s ", S_pop(&test1));
	}
	printf("\n");
	
	S_destroy_stack(&test1);

	/* link list examples */
	struct LINK_LIST *test2;
	struct LINK_LIST *test3;

	test2 = init_link_list();
	test3 = init_link_list();

	create(test2, "hello");
	create(test2, ", ");
	create(test2, "world");
	create(test2, "!");

	tail_create(test3, "I ");
	tail_create(test3, "have ");
	tail_create(test3, "a ");
	tail_create(test3, "dream.");

	printf("length: %d\n", get_length(test2));
	printf("length: %d\n", get_length(test3));

	insert(test2, 3, "_good_");
	printf("before deletion: ");
	for (i = 1; i <= get_length(test2); ++i) {
		printf("%s", get_element(test2, i));
	}
	printf("\n");

	del(test2, 3);

	printf("after deletion: ");
	for (i = 1; i <= get_length(test2); ++i) {
		printf("%s", get_element(test2, i));
	}
	printf("\n");

	for (i = 1; i <= get_length(test3); ++i) {
		printf("%s", get_element(test3, i));
	}
	printf("\n");

	destroy_link_list(test2);
	destroy_link_list(test3);

	/* double linked list examples */
	struct DOUBLE_LINK_LIST *test4;

	test4 = init_double_link_list();

	D_create(test4, "Viva ");
	D_create(test4, "La ");
	D_create(test4, "Vida");

	printf("#length: %d\n", D_get_length(test4));

	for (i = 1; i <= D_get_length(test4); ++i) {
		printf("%s", D_get_element(test4, i));
	}
	printf("\n");

	D_destroy_link_list(test4);

	return 0;
}
