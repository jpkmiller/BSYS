#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[]) {

	int it = atoi(argv[argc - 1]);
	
	//pipe setup
    int PtoC[2]; //pipe parent to child
	int CtoP[2]; //pipe child to parent
	int child; //pid of child
	pipe(PtoC);
	pipe(CtoP);

	//use only core 0
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	sched_setaffinity(getpid(), sizeof(set), &set);

	//time measuring
	struct timespec begin1C; 
	struct timespec end1C;
	unsigned long times[it];


	struct timespec start;
	struct timespec stop;
	clock_gettime(CLOCK_REALTIME, &start);
	clock_gettime(CLOCK_REALTIME, &stop);
	long precision = stop.tv_nsec - start.tv_nsec;


	if ((child = fork()) < 0) {
        //fork failed
		perror("fork");
		exit(1);

	} else if (child == 0) {
		unsigned long mesDif, mesEnd;

		while(i < it) {
            //writes start time in pipe Child to Parent
          	clock_gettime(CLOCK_REALTIME, &end1C);
        	mesEnd = (end1C.tv_sec * 1000000000) + end1C.tv_nsec;
          	write(CtoP[1], &mesEnd, sizeof(unsigned long));

			//reads difference from pipe Parent to Child
			read(PtoC[0], &mesDif, sizeof(unsigned long));
            times[++i] = mesDif;
		}



        for(size_t j = 0; j < (unsigned long) it; j++) {
      		printf("%lu %lu\n", j, times[j]);
      	}

        printf("jump back to parent\n");
		exit(0);

	} else {
        unsigned long mesDif, mesEnd;

		while (1) {
            clock_gettime(CLOCK_REALTIME, &begin1C);
      		read(CtoP[0], &mesEnd, sizeof(unsigned long)); //context switch to child process
          	
            mesDif = mesEnd - ((begin1C.tv_sec * 1000000000) + begin1C.tv_nsec);
			write(PtoC[1], &mesDif, sizeof(unsigned long));
		}
	}
	return 0;
}
