#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

int main()
{
	printf("CARD TEST FOUR -- RUNNING\n");

	struct gameState g;
	int r, prevcoins;
	int k[10] = {village, smithy, salvager, cutpurse, council_room, sea_hag, treasure_map, ambassador, tribute, minion};

	initializeGame(2, k, 5, &g);
	prevcoins = g.coins;

	//give player a cutpurse
	gainCard(cutpurse, &g, 2, 0);
	r = g.hand[0][5];
	cassert(r == cutpurse, "card 5 in hand is cutpurse");

	testfun("playCard with card = cutpurse");
	r = playCard(5, 0, 0, 0, &g);
	cassert(r == 0, "cutpurse played");

	r = g.coins;
	cassert(r != prevcoins, "# coins has changed");

	r = g.handCount[1];
	cassert(r == 4, "# cards in player 1's hand is 4 as they have copper");
	printf("# cards in player 1's hand is %d\n", r);

	printf("CARD TEST FOUR -- FINISHED\n\n");

	return 0;
}
