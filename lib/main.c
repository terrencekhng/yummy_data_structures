#include"stack.h"
#include"error.h"
#include"link_list.h"
#include"queue.h"

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

	del(test2, 6);

	printf("after deletion: ");
	for (i = 1; i <= get_length(test2); ++i) {
		printf("%s", get_element(test2, i));
	}
	printf("\n");

	for (i = 1; i <= get_length(test3); ++i) {
		printf("%s", get_element(test3, i));
	}
	printf("\n");

	printf("%d\n", find(test3, "have "));
	printf("%s@@\n", get_next(test3, "dream."));

	destroy_link_list(test2);
	destroy_link_list(test3);

	/* double linked list examples */
	struct DOUBLE_LINK_LIST *test4;
	struct DOUBLE_LINK_LIST *test5;

	test4 = init_double_link_list();
	test5 = init_double_link_list();

	D_create(test4, "Viva ");
	D_create(test4, "La ");
	D_create(test4, "Vida");

	D_tail_create(test5, "The ");
	D_tail_create(test5, "C ");
	D_tail_create(test5, "Programming ");
	D_tail_create(test5, "Language");

	D_insert(test4, 4, "_HALO_");
	D_insert(test5, 1, "_INSERT_");

	printf("#length: %d\n", D_get_length(test4));
	printf("#length: %d\n", D_get_length(test5));

	for (i = 1; i <= D_get_length(test4); ++i) {
		printf("%s", D_get_element(test4, i));
	}
	printf("\n");

	printf("before deletion: ");
	for (i = 1; i <= D_get_length(test5); ++i) {
		printf("%s", D_get_element(test5, i));
	}
	printf("\n");

	D_del(test5, 2);

	printf("after deletion: ");
	for (i = 1; i <= D_get_length(test5); ++i) {
		printf("%s", D_get_element(test5, i));
	}
	printf("\n");

	printf("find 'Language': %d\n", D_find(test5, "Language"));
	printf("%s@@%s\n", D_get_next(test5, "C "), D_get_pre(test5, "_INSERT_"));

	D_destroy_link_list(test4);
	D_destroy_link_list(test5);

	/* cyclic double linked list examples */
	struct DOUBLE_LINK_LIST *test6;
	struct DOUBLE_LINK_LIST *test7;

	test6 = init_cyclic_double_link_list();
	test7 = init_cyclic_double_link_list();

	CD_create(test6, "I ");
	CD_create(test6, "love ");
	CD_create(test6, "Google!");

	CD_tail_create(test7, "Let's ");
	CD_tail_create(test7, "fuck ");
	CD_tail_create(test7, "the ");
	CD_tail_create(test7, "world!");

	CD_insert(test6, 1, " and Facebook!");

	CD_insert(test7, CD_get_length(test7)+1, " yes, ");
	CD_insert(test7, CD_get_length(test7)+1, "and ");
	CD_insert(test7, CD_get_length(test7)+1, "you!");

	printf("@length: %d\n", CD_get_length(test6));
	printf("@length: %d\n", CD_get_length(test7));

	for (i = 1; i <= CD_get_length(test6); ++i) {
		printf("%s", CD_get_element(test6, i));
	}
	printf("\n");

	printf("before deletion: ");
	for (i = 1; i <= CD_get_length(test7); ++i) {
		printf("%s", CD_get_element(test7, i));
	}
	printf("\n");

	CD_del(test7, 7);

	printf("after deletion: ");
	for (i = 1; i <= CD_get_length(test7); ++i) {
		printf("%s", CD_get_element(test7, i));
	}
	printf("\n");

	printf("find 'and ': %d\n", CD_find(test7, "and "));
	printf("%s@@%s\n", CD_get_next(test7, "and "), CD_get_pre(test7, "Let's "));

	CD_destroy_link_list(test6);
	CD_destroy_link_list(test7);

	/* cyclic singly linked list test examples */
	struct LINK_LIST *test8;
	struct LINK_LIST *test9;

	test8 = init_cyclic_link_list();
	test9 = init_cyclic_link_list();

	CS_create(test8, "I ");
	CS_create(test8, "love ");
	CS_create(test8, "github!");

	CS_tail_create(test9, "Good ");
	CS_tail_create(test9, "Fellows");

	CS_insert(test9, CS_get_length(test9)+1, " & ");
	CS_insert(test9, CS_get_length(test9)+1, "Fargo");

	printf("length: %d\n", CS_get_length(test8));
	printf("length: %d\n", CS_get_length(test9));

	for (i = 1; i <= CS_get_length(test8); ++i) {
		printf("%s", CS_get_element(test8, i));
	}
	printf("\n");

	printf("before deletion: ");
	for (i = 1; i <= CS_get_length(test9); ++i) {
		printf("%s", CS_get_element(test9, i));
	}
	printf("\n");

	CS_del(test9, 4);

	printf("after deletion: ");
	for (i = 1; i <= CS_get_length(test9); ++i) {
		printf("%s", CS_get_element(test9, i));
	}
	printf("\n");

	printf("%d\n", CS_find(test9, " & "));
	printf("%s\n", CS_get_next(test9, " & "));
	printf("\n\n");

	CS_destroy_link_list(test8);
	CS_destroy_link_list(test9);

	/* linked queue test examples */
	struct COMMON_QUEUE *test10;

	test10 = C_init_queue();

	C_enqueue(test10, "Someone ");
	C_enqueue(test10, "like ");
	C_enqueue(test10, "you!");

	printf("length: %d\n", C_get_queue_length(test10));
	int j;

	/* it prints the first two characters */
	for (j = 0; j < C_get_queue_length(test10); j++) {
		printf("[%d %s]", j, C_dequeue(test10));
	}
	printf("\n");

	/* it prints all the characers */
	C_dequeue(test10);
	C_dequeue(test10);
	C_dequeue(test10);
	C_dequeue(test10);
	printf("\n\n\n");

	C_destroy_queue(test10);

	/* cyclic queue test examples */
	struct CYCLIC_QUEUE test11;

	//CQ_init_queue(&test11, 5);
	CQ_init_queue(&test11, 5);

	CQ_enqueue(&test11, "Come ");
	//CQ_enqueue(&test11, "fuck ");
	//CQ_enqueue(&test11, "me!");
	printf("\n\n\n");


	CQ_destroy_queue(&test11);

	return 0;
}
