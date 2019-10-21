#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[]) {

	int it = atoi(argv[argc - 1]);

	int fd1[2],fd2[2], child;
	pipe(fd1);
	pipe(fd2);
	long int time1[it], time2[it], t1, t2;
	int i = 0;

	struct timespec begin1C, end1C, begin2C, end2C;

	if ((child = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (child) {
		close(fd1[1]); //close output of first pipe
		close(fd2[0]); //close input of second pipe

		clock_gettime(CLOCK_REALTIME, &end1C);
		t1 = (((int) end2C.tv_sec - (int) begin2C.tv_sec) * 1000000000) + (int) end2C.tv_nsec - (int) begin2C.tv_nsec;
		write(fd1[1], &t1, sizeof(int));

		printf("reading from parent %d\n", i);
		clock_gettime(CLOCK_REALTIME, &begin2C);
		read(fd2[0], &time2[i++] , sizeof(int)); 

	} else {
		while (i < it) {
			close(fd2[1]); //close input of first pipe
			close(fd1[0]); //close output of second pipe

			printf("reading from child %d %d\n", i, it);
			clock_gettime(CLOCK_REALTIME, &begin1C);
			read(fd1[0], &time1[i++], sizeof(int)); //context switch to child process

			//return from child
			clock_gettime(CLOCK_REALTIME, &end2C);
			t2 = (((int) end1C.tv_sec - (int) begin1C.tv_sec) * 1000000000) + (int) end1C.tv_nsec - (int) begin1C.tv_nsec;
			write(fd2[1], &t2, sizeof(int));
		}
	}
	return 0;	
}
