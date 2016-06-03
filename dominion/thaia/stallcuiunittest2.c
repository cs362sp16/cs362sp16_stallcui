#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "interface.h"
#include "tests.h"

//testing buyCard

int main()
{
	printf("UNIT TEST TWO -- RUNNING\n");
	
	struct gameState g;
	int r, i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};	

	initializeGame(2, k, 5, &g);

	//used some code from playdom.c to simulate playing/buying dominion cards
	int money = 0;

	//total money for hand	
	for (i = 0; i < numHandCards(&g); i++)
	{
		if (handCard(i, &g) == copper)
			money++;
		else if (handCard(i, &g) == silver)
			money += 2;
		else if (handCard(i, &g) == gold)
			money += 3;
		
	}
	//money in hand is going to be 4
	cassert(money == 4, "money in hand is 4");

	//buy a silver
	testfun("buyCard, buying silver");
	if (money >= 3)
		buyCard(silver, &g);

	//assert silver is in discard
	r = g.discard[0][0];
	cassert(r == 5, "card in discard is silver");

	//assert # coins remaining is 1
	r = g.coins;
	cassert(r == 1, "1 money left");

	printf("UNIT TEST TWO -- FINISHED\n\n");

	return 0;
}
