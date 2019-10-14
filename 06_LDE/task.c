#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int arg = atoi(argv[argc - 1]);
	struct timeval begin, end;
	clock_t beginC, endC;
	long usec;
	float csec;
	
	if (strcmp(argv[1], "gettime") == 0) {

		for (int i = 0; i < arg; i++) {
			gettimeofday(&begin, (struct timezone *) 0); //gettimeofday -> writes in struct
			read(0, NULL, 0); //read 0-bytes from stdin
			gettimeofday(&end, (struct timezone *) 0);
			if (strcmp(argv[2],"-l") == 0)
				printf("test-no. %d: %ld\n", i, end.tv_usec - begin.tv_usec);
			usec += end.tv_usec - begin.tv_usec;
		}

		printf("average time %ld\n", usec / arg); //time measurement with gettimeofday()

	} else if (strcmp(argv[1], "clock") == 0) {

		for (int i = 0; i < arg; i++) {
			beginC = clock(); //use clock
			read(0, NULL, 0); //read 0-bytes from stdin
			endC = clock();
			if (strcmp(argv[2], "-l") == 0)
				printf("test-no. %d: %ld\n", i, endC - beginC);
			csec += endC - beginC;
		}

		printf("average time %f in sec | %f in usec\n", (csec / arg) / CLOCKS_PER_SEC, csec / arg);  //time measurement  with clock()

	}
}
