#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

int main()
{
	printf("CARD TEST ONE -- RUNNING\n");

	struct gameState g;
	int r;
	int k[10] = {village, smithy, salvager, cutpurse, council_room, sea_hag, treasure_map, ambassador, tribute, minion};

	initializeGame(2, k, 5, &g);

	//give player 0 a village
	gainCard(village, &g, 2, 0);
	r = g.hand[0][5];
	cassert(r == village, "card 5 in hand is village");

	testfun("playCard with card = village");
	r = playCard(5, 0, 0, 0, &g);
	cassert(r == 0, "village played");

	r = g.numActions;
	cassert(r == 2, "# actions  = 2");

	r = g.handCount[0];
	cassert(r == 6, "# cards = 6");

	printf("CARD TEST ONE -- FINISHED\n\n");

	return 0;
}
