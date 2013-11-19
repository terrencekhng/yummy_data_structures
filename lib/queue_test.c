#include"error.h"
#include"queue.h"

int main() {
	int i;

	/*struct CYCLIC_QUEUE test1;
	CQ_init_queue(&test1, 5);

	CQ_enqueue(&test1, "come ");
	CQ_enqueue(&test1, "fuck ");
	CQ_enqueue(&test1, "me!");

	printf("length: %d\n", CQ_get_queue_length(&test1));

	for (i = 0; i < CQ_get_queue_length(&test1); ++i) {
		printf("%s", CQ_dequeue(&test1));
	}
	printf("\n");

	CQ_destroy_queue(&test1);*/

/*	struct COMMON_QUEUE *test2;

	test2 = C_init_queue();

	C_enqueue(test2, "we ");
	C_enqueue(test2, "are ");
	C_enqueue(test2, "the ");
	C_enqueue(test2, "world!");

	printf("length: %d\n", C_get_queue_length(test2));

	for (i = 0; i < C_get_queue_length(test2); ++i) {
		printf("%s", C_dequeue(test2));
	}

	C_destroy_queue(test2);*/

	struct COMMON_QUEUE test1;

	C_init_queue(&test1);

	if (C_is_empty(&test1)==YES) {
		printf("is test1 empty? YES\n");
	}
	else {
		printf("is test1 empty? NO\n");
	}

	C_enqueue(&test1, "we ");
	C_enqueue(&test1, "are ");
	C_enqueue(&test1, "the ");
	C_enqueue(&test1, "world!");

	if (C_is_empty(&test1)==YES) {
		printf("is test1 empty? YES\n");
	}
	else {
		printf("is test1 empty? NO\n");
	}

	/* put this in comment in case to make sure that the subsequent tests
	 * work correctly.
	 *
		
	 C_clear_queue(&test1);
	 
	 */

	printf("linked-list queue \"test1\": length: %d\n", C_get_queue_length(&test1));
	printf("%s", C_dequeue(&test1));
	printf("%s", C_dequeue(&test1));
	printf("%s", C_dequeue(&test1));
	printf("%s", C_dequeue(&test1));
	printf("\n");

	C_destroy_queue(&test1);

	return 0;
}
