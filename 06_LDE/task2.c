#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	
	int fd[2], child;
	pipe(fd);
	if ((child = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (child) {
		printf("I am parent\n");
	} else {
		printf("I am child\n");
	}
	return 0;	
}
