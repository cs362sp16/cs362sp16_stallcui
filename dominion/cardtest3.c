#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

int main()
{
	printf("CARD TEST THREE -- RUNNING\n");
	
	struct gameState g;
    int r, prevcoins;
    int k[10] = {village, smithy, cutpurse, minion, council_room, sea_hag,treasure_map, ambassador, tribute, salvager};
    initializeGame(2, k, 5, &g);
	prevcoins = g.coins;
	printf("# coins before minion = %d\n", prevcoins);
	//give player 0 a minion
	gainCard(minion, &g, 2, 0);
	r = g.hand[0][5];
	cassert(r == minion, "card 5 in hand is minion");

	testfun("playCard with card = minion, +2 coins");
	r = playCard(5, 1, 0, 0, &g); //choice 1; +2 coins
	cassert(r == 0, "minion played");

	r = g.numActions;
	cassert(r == 1, "# actions = 1"); //assert # actions is 1

	printf("# coins after minion = %d\n", g.coins);
	r = g.coins;
	cassert(r != prevcoins, "# coins changed"); //assert # coins is 2 more

	printf("CARD TEST THREE -- FINISHED\n\n");

	return 0;
}
