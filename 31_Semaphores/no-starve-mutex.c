#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define __MAX_THREADS 1

typedef struct __nomutex {
	sem_t lock;
	sem_t acquire;
} nomutex;

void init_lock(nomutex *nm) {
	assert(sem_init(&nm->lock) == 0);
}

void acquire_lock(nomutex *nm) {
	sem_wait(&nm->acquire);
}

void *child(void *arg) {
	
}

int main(int argc, char *argv[]) {
	pthread_t t[__MAX_THREADS];

	for (int i = 0; i < __MAX_THREADS; i++) {
		pthread_create(&t[i], NULL, child, (void *) (long long int) i);
	}

	for (int i = 0; i < __MAX_THREADS; i++) {
		pthread_join(t[i], NULL);
	}
}
