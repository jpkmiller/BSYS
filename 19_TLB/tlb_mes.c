#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <unistd.h>

int meassurement(unsigned int, unsigned int, unsigned int);

int main(int argc, char *argv[]) {

	if (argc != 3) {
		printf("Please restart with %s num-of-pages num-of-trials\n", argv[0]);
		exit(1);
	}

	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	sched_setaffinity(getpid(), sizeof(set), &set);

	unsigned int PAGESIZE = getpagesize();
	unsigned int NUMPAGES = atoi(argv[1]);
	unsigned int NUMTRIALS = atoi(argv[2]);
	unsigned int jump = PAGESIZE / sizeof(int); //1024



	int time = meassurement(NUMPAGES, NUMTRIALS, jump);

	printf("%d %d\n", NUMPAGES, time);

	return 0;
}

int meassurement(unsigned int NUMPAGES, unsigned int NUMTRIALS, unsigned int jump){


	struct timespec start,end;
	struct timespec forStart;
	unsigned long precision = 0;
	unsigned int precisionFaktor = 10000000;


	for (unsigned int i = 0; i < precisionFaktor; i++){
	  	clock_gettime(CLOCK_REALTIME, &start);
	  	clock_gettime(CLOCK_REALTIME, &end);
	  	precision += (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
	}
	precision /= precisionFaktor;

	unsigned long long *a = (unsigned long long *) calloc(NUMPAGES * jump, sizeof(unsigned long long));
	if(a == NULL){
		perror("Alloc failed a");
	}

	unsigned long sum = 0;


	for (unsigned int j = 0; j < NUMTRIALS; j++)
	{
		for (unsigned int i = 0; i < NUMPAGES * jump; i += jump)
		{
	  	clock_gettime(CLOCK_REALTIME, &start);
	   	a[i] += 1;
	  	clock_gettime(CLOCK_REALTIME, &end);
	  	sum += (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec) - precision;

	//	printf("%d -> %d\n", i, times[i]);
		}
	}

	free(a);
	return sum / (NUMPAGES * NUMTRIALS); 
}
