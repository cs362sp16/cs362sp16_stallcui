#ifndef _TESTS_H
#define _TESTS_H

#include "dominion.h"
#include <stdio.h>

int failure = 0;

int cassert(int b, char* msg)
{
	if (b == 0)
	{
		printf("FAILED ASSERTION: %s\n", msg);
		failure = 1;
		return 1;
	}
	return 0;
}

void checkassert()
{
	if (!failure)
	{
		printf("TEST COMPLETED SUCCESSFULLY.\n");
	}
}

#endif
