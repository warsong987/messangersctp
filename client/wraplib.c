#include "unp.h"

void Inet_pton(int family, const char *strptr, void *addrptr)
{
	int n;
	if((n = inet_pton(family, strptr, addrptr))<0)
	{
		err_sys("Inet_pton error for %s", strptr);
	} else if(n == 0)
	{
		err_quit("Inet_pton, error for %s", strptr);
	}
}