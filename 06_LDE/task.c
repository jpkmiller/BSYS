#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int arg = atoi(argv[argc - 1]);
	struct timeval begin, end;
	long usec;

	for (int i = 0; i < arg; i++) {
		gettimeofday(&begin, (struct timezone *) 0);
		read(0, NULL, 0); //read 0-bytes from stdin
		gettimeofday(&end, (struct timezone *) 0);
		if (strcmp(argv[1],"-l") == 0)
			printf("test-no. %d: %ld\n", i, end.tv_usec - begin.tv_usec);
		usec += end.tv_usec - begin.tv_usec;
	}

	printf("time for 0 Byte read: %ld\n", usec / arg);
}
