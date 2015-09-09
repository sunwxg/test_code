#define  _BSD_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>
#include <stdarg.h>

static int ip = 10;

void print_log(char * M, ...)
{
	char buf[2048], usrMsg[2048];
	va_list argList;

	va_start(argList, M);

	vsnprintf(usrMsg, sizeof(buf), M, argList);
	snprintf(buf, sizeof(buf), usrMsg, argList);
	syslog(LOG_INFO, buf, argList);

	va_end(argList);
}

void errMsg(char * M, ...)
{
	va_list argList;

	va_start(argList, M);
	syslog(LOG_ERR, M, argList);
	va_end(argList);

	exit(1);
}

void child_process(void)
{
	execlp("./run", "./run"); 

	/*wget --server-response --timeout=2 www.google.com*/
}

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
	
	daemon(0, 0);

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
