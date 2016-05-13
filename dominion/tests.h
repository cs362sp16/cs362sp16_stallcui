#ifndef _TESTS_H
#define _TESTS_H

#include "dominion.h"
#include <stdio.h>

int seedchkargs(int argc, int seed)
{
	if (cassert(argc == 2, "seedchkargs: # args input = 1"))
		return 1;
	else if (cassert(seed != 0, "seedchkargs: input != 0, is #"))
		return 1;
	else return 0;
}

int failure = 0;

int cassert(int b, char* msg)
{
	if (b == 0)
	{
		printf("FAILED ASSERTION: %s\n", msg);
		failure = 1;
		return 1;
	}
	else printf("assertion succeeded: %s\n", msg);
	return 0;
}

void testfun(char* name)
{
	printf("testing function %s...\n", name);
}

void checkassert()
{
	if (!failure)
	{
		printf("TEST COMPLETED SUCCESSFULLY.\n");
	}
}

#endif
