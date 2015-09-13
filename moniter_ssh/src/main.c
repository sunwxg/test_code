#include "internal.h"

#define CHECK_INTERNAL 60

char *cmd, *cmd_check;
char tmp_file[255];

int check_status(void)
{
	char buf[255];
	memset(buf, 0, sizeof(buf));
	memset(tmp_file, 0, sizeof(tmp_file));

	snprintf(tmp_file, sizeof(tmp_file), "/tmp/%d.pid", getpid());

	snprintf(buf, sizeof(buf), "%s %s", cmd_check, tmp_file);

	return system(buf)>>8;
}

void kill_child(FILE *fp)
{
	char buf[255];
	pid_t pid;

	memset(buf, 0, sizeof(buf));
	while (fgets(buf, sizeof(buf), fp) != 0) {
		pid = atoi(buf);
		print_log("pid=%d is killed\n", pid);
		kill(pid, SIGKILL);
		wait(NULL);
	}
}

void child_process(void)
{
	print_log("start: %s", cmd);
	execlp(cmd, cmd, (char *)NULL);
	print_log("start %s fail", cmd);
}

void parent_process(pid_t pid)
{
	FILE *fp;

	print_log("main process: pid=%d", getpid());

	while (1) {
		sleep(CHECK_INTERNAL);

		if (check_status() != 0) {
			sleep(1);
			fp = fopen(tmp_file, "r");
			if (fp != NULL) {
				kill_child(fp);
				fclose(fp);
				break;
			}

			print_log("error open %s", tmp_file);
		}
	}

	remove(tmp_file);
}

void start(void)
{
	pid_t pid;
	int master;
	
	daemon(0, 0);

	while (1) {
		pid = forkpty(&master, NULL, NULL, NULL);

		if (pid == 0) {
			child_process();
			break;

		} else if (pid > 0) {
			parent_process(pid);

		} else {
			print_log("fork error");
			exit(1);
		}
	}

	exit(0);
}

int main(int argc, char *argv[])
{
	if ( argc != 3) {
		printf("Usage: %s cmd check_cmd\n", argv[0]);
		return 1;

	} else {
		cmd = argv[1];
		cmd_check = argv[2];
		start();
	}

	return 0;
}
