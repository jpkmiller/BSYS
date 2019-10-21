#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[]) {

	int it = atoi(argv[argc - 1]);
	
	int PtoC[2],CtoP[2], child;
	pipe(PtoC);
	pipe(CtoP);
	long int time1[it], time2[it], t1, t2;
	int i = 0;

	cpu_set_t set;
	CPU_ZERO(&set);

	struct timespec begin1C, end1C, begin2C, end2C;

	if ((child = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (child == 0) {
		close(PtoC[1]);

		CPU_SET(0, &set);
		sched_setaffinity(getpid(), sizeof(set), &set);
		while(i < it) {
			clock_gettime(CLOCK_REALTIME, &end1C);
			t1 = (( end1C.tv_sec - begin1C.tv_sec) * 1000000000) + end1C.tv_nsec - begin1C.tv_nsec;
			printf("coming from parent w/ cs time: %ld\n", t1);
			write(CtoP[1], &t1, sizeof(long int));
			
			clock_gettime(CLOCK_REALTIME, &begin2C);
			read(PtoC[0], &time2[++i] , sizeof(long int)); //context switch to paren

		}
		printf("pipe finished\n");
		exit(0);
	} else {

		CPU_SET(0, &set);
		sched_setaffinity(getpid(), sizeof(set), &set);

		while (i < it) {


			printf("switch to child\n");
			clock_gettime(CLOCK_REALTIME, &begin1C);
			read(CtoP[0], &time1[++i], sizeof(long int)); //context switch to child process

			clock_gettime(CLOCK_REALTIME, &end2C);
			t2 = ((end2C.tv_sec - begin2C.tv_sec) * 1000000000) + end2C.tv_nsec - begin2C.tv_nsec;
			printf("comming back from child w/ cs time: %ld\n", t2);
			close(PtoC[0]);
			write(PtoC[1], &t2, sizeof(long int));
		}
		printf("waiting for child\n");
	}
	//kill(child, 0);
	return 0;
}
