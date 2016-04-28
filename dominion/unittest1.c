#include <stdio.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

int main()
{

	printf("UNIT TEST ONE -- RUNNING\n");	

	struct gameState g;

	int k[10] = {adventurer, council_room,
	  feast, gardens, mine, smithy, village, baron, minion, tribute};

	int r = initializeGame(2, k, 5, &g);
	cassert(r, "initializeGame failure");
	if (r == 0)
		printState(&g);
	
}
