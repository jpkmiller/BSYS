#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void sig_handler(int signo) {
	if (signo == SIGINT)
		printf("received interrupt signal\n");
} 

int main(void) {
	int ret;
	signal(SIGINT, sig_handler);

	while(1)
		sleep(1);
	printf("ret : %d", ret);
	return 0;
}
