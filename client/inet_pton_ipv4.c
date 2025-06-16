#include "unp.h"

int inet_aton(const char *, struct in_addr *);

int inet_pton(int family, const char *strptr, void *addrptr)
{
	if(family == AF_INET)
	{
		struct in_addr in_val;

		if(inet_aton(strptr, &in_val))
		{
			memcpy(addrptr, &in_val, sizeof(struct in_addr));
			return 1;
		}
		return 0;
	}
	errno = EAFNOSUPPORT;
	return -1;
}