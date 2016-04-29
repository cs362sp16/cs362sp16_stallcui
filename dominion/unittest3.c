#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"


int main()
{
	printf("UNIT TEST THREE -- RUNNING\n");

	struct gameState g;
	int r, i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 5, &g);

	testfun("supplyCount");

	//assert # silvers in supply is 40
	r = supplyCount(silver, &g);
	cassert(r == 40, "# silvers in supply is 40");

	//printf("%d\n", g.coins);
	buyCard(silver, &g);

	r = supplyCount(silver, &g);
	cassert(r == 39, "# silvers in supply is 39 after 1 is bought");

	printf("UNIT TEST THREE -- FINISHED\n\n");

	return 0;
}
