#ifndef __INTERNAL_H
#define __INTERNAL_H 1


#define  _BSD_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>
#include <stdarg.h>

void print_log(char * M, ...);
void errMsg(char * M, ...);
void child_process(void);
void print_log(char * M, ...);

#endif /* __INTERNAL_H */
