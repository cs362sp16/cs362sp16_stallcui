#include <stdlib.h>
#include <stdio.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

//test endTurn

int main()
{
	printf("UNIT TEST FOUR -- RUNNING\n");

	struct gameState g;
	int r, i;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 5, &g);

	endTurn(&g);

	r = whoseTurn(&g);
	cassert(r == 1, "player 1's turn");

	printf("UNIT TEST FOUR -- FINISHED\n\n");

	return 0;
}
