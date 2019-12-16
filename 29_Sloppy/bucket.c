#define _GNU_SOURCE
#define BUCKETS (101)
#include "linked_list.h"
#include <stdlib.h>
#include <pthread.h>

typedef struct __hash_t {
	list_t lists[BUCKETS];
} hash_t;

typedef struct __hash_arg {
	int tid;
	hash_t *H;
} hash_arg;

void Hash_Init(hash_t *H) {
	int i;
	for (i = 0; i < BUCKETS; i++) {
		List_Init(&H->lists[i]);
	}
}

void Hash_Insert(hash_t *H, int key) {
	int bucket = key % BUCKETS;
	List_Insert(&H->lists[bucket], key);
}

int Hash_Lookup(hash_t *H, int key) {
	int bucket = key % BUCKETS;
	return List_Lookup(&H->lists[bucket], key);
}

void *Hash_Repeat(void *arg) {
	hash_arg *args = (hash_arg *) arg;
	for (int i = 0;; i++) {
		Hash_Insert(args->H, i);
		printf("%d put %d\n", args->tid, i);
		pthread_yield();
	}
}

int main(void) {
	pthread_t p1, p2, p3, p4;

	hash_t *h = malloc(sizeof(hash_t));
	Hash_Init(h);
	hash_arg a1 = {0, h};
	hash_arg a2 = {1, h};
	hash_arg a3 = {2, h};
	hash_arg a4 = {3, h};



	pthread_create(&p1, NULL, Hash_Repeat, &a1);
	pthread_create(&p2, NULL, Hash_Repeat, &a2);
	pthread_create(&p3, NULL, Hash_Repeat, &a3);
	pthread_create(&p4, NULL, Hash_Repeat, &a4);

	for (int i = 0;; i = i + 2) {
		if (Hash_Lookup(h, i) == 0) {
			printf("found %d\n", i);
		} else {
			printf("not found %d\n", i);
		}
		pthread_yield();
	}
	return 0;
}
