#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

	if (argc != 3) {
		printf("Please restart with %s num-of-pages num-of-trials\n", argv[0]);
		exit(1);
	}

	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	sched_setaffinity(getpid(), sizeof(set), &set);

	int PAGESITE = getpagesize();
	int NUMPAGES = atoi(argv[1]);
	int NUMTRIALS = argv[2];

	struct timespec begin;
	struct timespec end;

	long long unsigned precision;

	for (int i = 0; i < 100000; i++) {
		clock_gettime(CLOCK_REALTIME, &begin);
		clock_gettime(CLOCK_REALTIME, &end);
		precision += (end.tv_sec - begin.tv_sec) * 1000000000 + end.tv_nsec - begin.tv_nsec;
	}
	precision /= 100000;
	printf("%lld\n", precision);

	/*
	   int timediff[4096];
	   int *a = (int*) malloc(4096 * sizeof(int));
	   for (int i = 0; i < 4096; i++) {
	   clock_gettime(CLOCK_REALTIME, &begin);
	   a[i] += 1;
	   clock_gettime(CLOCK_REALTIME, &end);
	   timediff[i] = (end.tv_sec - begin.tv_sec) * 1000000000 + (end.tv_nsec - begin.tv_nsec) - precision;
	   printf("%d -> %d\n", i, timediff[i]);  
	   } */



	int jump = PAGESIZE / sizeof(int); //1024
	int a[NUMPAGES * jump]; //num of pages * 1024

	for (int j = NUMTRIALS; j < NUMTRAILS; j++)
	{
		for (int i = 0; i < NUMPAGES * jump; i += jump)
		{
			a[i] += 1;
		}
	}

	

	return 0;
}

