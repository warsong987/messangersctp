#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <errno.h>
#include <stdarg.h>
#include <syslog.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SERV_MAX_SCTP_STRM 10
#define MAXLINE  	4096

#define SERV_PORT 	9877

#define SA struct sockaddr

int  Socket(int, int, int);
int  Bind(int, const struct sockaddr*, socklen_t);
void Setsockopt(int, int, int, const void*, socklen_t);
void Close(int);

int  inet_pton(int, const char *, void *);

void Inet_pton(int, const char* , void *);
void sctpstr_cli(FILE*, int, struct sockaddr *, socklen_t);
void sctpstr_cli_echoall(FILE *, int, struct sockaddr *, socklen_t);

void err_dump(const char *, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);