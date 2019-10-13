#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	
	int rc = fork();
	
	if (rc < 0) {
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello\n");
	} else {
		sleep(1);
		printf("goodbye\n");
	}
	
	return 0;
}
