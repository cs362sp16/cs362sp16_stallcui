#include <stdio.h>

int failure = 0;

int customassert(int b, char* msg)
{
	if (b == 0)
	{
		printf("FAILED ASSERTION: %s\n", msg);
		failure = 1;
	}
}

void checkassert()
{
	if (!failure)
	{
		printf("TEST COMPLETED SUCCESSFULLY.\n");
	}
}
