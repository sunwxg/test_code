#include "internal.h"

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
