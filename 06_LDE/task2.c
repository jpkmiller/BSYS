int main(void) {

	int fd[2];
	if ((pid_t child = fork()) < 0) {
		perror("fork");
	} else if (child) {
		
	}
	return 0;	
}
