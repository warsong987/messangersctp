
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

#define BUFFSIZE 	8192
#define MAXLINE  	4096

#define SERV_PORT 	9877
#define LISTENQ 	1024 

#define SA struct sockaddr

int  Socket(int, int, int);
int  Bind(int, const struct sockaddr*, socklen_t);
void Listen(int, int);

void Setsockopt(int, int, int, const void*, socklen_t);
int  Sctp_recvmsg(int, void *, size_t, struct sockaddr*, socklen_t*, struct sctp_sndrcvinfo*, int*);
int  Sctp_sendmsg(int, void *, size_t, struct sockaddr*, socklen_t, uint32_t, uint32_t, uint16_t, uint32_t, uint32_t);

int  sctp_get_no_strms(int, struct sockaddr*, socklen_t);
sctp_assoc_t sctp_address_to_associd(int sock_fd, struct sockaddr *sa, socklen_t salen);

void err_dump(const char *, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);
