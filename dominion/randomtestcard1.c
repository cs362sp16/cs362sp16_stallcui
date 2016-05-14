#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

int stategen(struct gameState g)
{
	int r, s, q, i;
	//test smithy
	s = rand() % 50;
	//add random # of random valid cards to the deck
	for (i = 0; i < s; i++)
	{
		r = rand() & treasure_map + 1;
		q = 0; //counter to ensure we don't try to find valid card infinitely
		while (g.supplyCount[r] == -1)
		{
			r = rand() % treasure_map + 1;
			q++; //increment q on failure to find good card
			if (q > 99)
				break; //stop looking if already looked 99 times
		}
		if (q > 99)
			break; //stop adding cards to deck since we're out
				//probability that supply is not exhausted if
				//99 attempts to give new card have been made
				//is truly mind-boggling
		gainCard(r, &g, 1, 0); //gain card to deck
	}
	shuffle(0, &g); //shuffle when we're done, be considerate! don't cheat

	//collect some stuff for oracle here
	
	gainCard(smithy,&g,2,0);
	playCard(5,0,0,0,&g);

	//run oracle here
	
	return 0;
}


int casegen(int k[10])
{
	struct gameState g;
	initializeGame(2, k, 5, &g);
	stategen(g);
	return 0;
}

int main(int argc, char* argv[])
{
	int i;
	int seed = atoi(argv[1]);	
	int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, smithy};
	seedchkargs(argc, seed); //note: does not accept 0 for random # seed
	srand(seed);
	for (i = 0; i < rand() % 100; i++)
		casegen(k);
	return 0;
}
