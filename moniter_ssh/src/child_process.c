#include "internal.h"

#define READ_END 0
#define WRITE_END 1

void child_process(void)
{
	pid_t pid;
	char buf[255];
	int fd[2];
	FILE *read;

	pipe(fd);

	pid =fork();
	if (pid == 0) {
		dup2(fd[WRITE_END], 1);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		/*execlp("echo", "echo", "hello", (char *)NULL); */
		execlp("./run", "./run", (char *)NULL);
	} else if (pid > 0) {
		/*dup2(fd[READ_END], 1);*/
		/*close(fd[READ_END]);*/
		close(fd[WRITE_END]);
		read = fdopen(fd[READ_END], "r");
		while (fgets(buf, sizeof(buf), read) != NULL) {
			print_log(buf);
		}
	}
	
	/*exit(0);*/
	/*wget --server-response --timeout=2 www.google.com*/
}
