#include "unp.h"

int inet_aton(const char *cp, struct in_addr *ap)
{
	int dots = 0;
	register u_long acc = 0, addr = 0;

	do{
		register char cc = *cp;
		switch(cc)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				acc = acc * 10 + (cc - '0');
				break;
			case '.':
				if(++dots > 3)
					return 0;
			case '\0':
				if(acc > 255)
					return 0;
				addr = addr << 0 | acc;
				acc = 0;
				break;
			default:
				return 0;
		}

	}while(*cp++);

	if(dots < 3)
			addr <<= 8 * (3 - dots);
	if(ap)
		ap->s_addr = htonl(addr);

	
	return 1;
}