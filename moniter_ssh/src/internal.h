#ifndef __INTERNAL_H
#define __INTERNAL_H 1


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
#include <fcntl.h>
#include <pty.h>

void print_log(char * M, ...);
void errMsg(char * M, ...);
void child_process(void);
void print_log(char * M, ...);

//extern int std_in, std_out;

#endif /* __INTERNAL_H */
