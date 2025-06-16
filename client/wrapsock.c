#include "unp.h"


int  Socket(int family, int type, int protocol)
{
  int n;
  if((n = socket(family, type, protocol)) < 0)
    err_sys("socket error");
  return n;
}


int  Bind(int fd, const struct sockaddr * sockaddr, socklen_t len)
{
  if(bind(fd, sockaddr, len) < 0)
    err_sys("bind error");
}

void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
  if(setsockopt(fd, level, optname, optval, optlen) < 0)
      err_sys("setsockopt error");
}

void Listen(int fd, int backlog)
{
  char  *ptr;

  if((ptr = getenv("LISTENQ")) != NULL)
    backlog = atoi(ptr);
  
  if(listen(fd, backlog) < 0)
    err_sys("listen error");
}