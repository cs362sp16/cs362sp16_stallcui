#include <stdio.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

int main()
{

	printf("UNIT TEST ONE -- RUNNING\n");	

	struct gameState g;
	int r, i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	//test initializeGame
	testfun("initializeGame");
	r = initializeGame(2, k, 5, &g);
	cassert(r == 0, "call to initializeGame with 2 players, k array");
	r = g.handCount[0];
	cassert(r == 5, "#cards in player 0's hand is 5"); 	
	r = g.handCount[1];
	cassert(r == 0, "#cards in player 1's hand is 0");

	printf("UNIT TEST ONE -- FINISHED\n\n");
}
