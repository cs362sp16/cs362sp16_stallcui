#include <stdio.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

//tests function initializeGame

int main()
{

	printf("UNIT TEST ONE -- RUNNING\n");	

	struct gameState g;
	int r;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	testfun("initializeGame");
	//ensure initializeGame didn't fail
	r = initializeGame(2, k, 5, &g);
	cassert(r == 0, "call to initializeGame with 2 players, k array");

	//check that it's player 0's turn
	r = whoseTurn(&g);
	cassert(r == 0, "it's player 0's turn");
	//check that it's NOT player 1's turn
	r = whoseTurn(&g); //perhaps not necessary but makes me feel better
	cassert(r != 1, "it's not player 1's turn");

	//check that # of cards in player 0's hand is 5
	r = g.handCount[0];
	cassert(r == 5, "#cards in player 0's hand is 5"); 	
	//check that # of cards in player 1's hand is 0 (not their turn)
	r = g.handCount[1];
	cassert(r == 0, "#cards in player 1's hand is 0");

	printf("UNIT TEST ONE -- FINISHED\n\n");

	return 0;
}
