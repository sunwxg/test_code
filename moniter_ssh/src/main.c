#include "internal.h"

static int ip = 10;
int std_in, std_out;

int check_status(void)
{
	int res;
	/*char cmd[255];*/

	/*snprintf(cmd, sizeof(cmd), "ping -c 1 192.168.1.%d", ip);*/
	ip--;

	/*res = system(cmd);*/
	res = ip;

	return res;
}

void parent_process(pid_t pid)
{
	print_log("child pid=%d\n", pid);

	while (1) {
		sleep(1);

		if (check_status() == 0) {
			kill(pid, SIGKILL);
			wait(NULL);

			ip = 10;
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	pid_t pid;
	
	std_in = dup(0);
	std_out =dup(1);

	/*daemon(0, 0);*/

	pid = getpid();
	print_log("parent pid=%d", pid);


	int i = 3;
	while (i--) {
		pid = fork();
		if (pid == 0) {
			child_process();
			break;

		} else if (pid != 0) {
			parent_process(pid);

		} else {
			print_log("fork error");
			return 1;
		}
	}

	return 0;
}
