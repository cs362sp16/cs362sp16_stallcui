#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

int oracle(struct gameState g, int szhand, int szdeck)
{
	int r;
	r = g.handCount[0];
	cassert(r != szhand, "# cards in hand has changed");
	r = g.deckCount[0];
	cassert(r != szdeck, "# cards in deck has changed");

	if (failure == 1)
	{
		//DUMP
		printf("FAILURE DETECTED\n");
		printHand(0, &g);
		printDeck(0, &g);
	}

	failure = 0;
	return 0;
}

int stategen(struct gameState g)
{
	int r, s, q, i;
	int badbit = 0; //intentionally bad input
	//test smithy
	s = rand() % 500; //run lots of times!
	//add random # of random valid cards to the deck
	for (i = 0; i < s; i++)
	{
		//add in a chance to insert a truly bad card into the deck in order
		//to screw up drawCard in play_smithy().
		badbit = 0;
		
		r = rand() % treasure_map + 1;
		
		
		if ((i== 19) && (r % 25	== 0))
		{
			printf("Bad doggy!\n");
			g.deck[0][g.deckCount[0]] = -1;
			g.deckCount[0]++;
			badbit = 1;
			break;
		}
		if (badbit == 1)
			printf("oops, not supposed to be here.\n");	
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

//	printf("test case generated\n");

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
	int i, j;
	int seed = atoi(argv[1]);	
	int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, smithy};
	seedchkargs(argc, seed); //note: does not accept 0 for random # seed
	srand(seed);
	j = rand() % 1000;
	printf("%d tests\n", j);
	for (i = 0; i < j; i++)
		casegen(k);
	return 0;
}
