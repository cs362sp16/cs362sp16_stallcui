#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

int main()
{
	printf("CARD TEST TWO -- RUNNING\n");

	struct gameState g;
	int r;
	int k[10] = {village, smithy, salvager, cutpurse, council_room, sea_hag, treasure_map, ambassador, tribute, minion};

	initializeGame(2, k, 5, &g);

	//give player 0 a smithy
	gainCard(smithy, &g, 2, 0);
	r = g.hand[0][5];
	cassert(r == smithy, "card 5 in hand is smithy");

	testfun("playCard with card = smithy");
	r = playCard(5, 0, 0, 0, &g);
	cassert(r == 0, "smithy played");

	r = g.handCount[0];
	cassert(r == 8, "# cards = 8");

	printf("CARD TEST TWO -- FINISHED\n\n");

	return 0;
}
