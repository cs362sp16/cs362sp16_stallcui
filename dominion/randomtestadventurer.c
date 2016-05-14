#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

int oracle(struct gameState g, int szhand, int szdeck, int ncoins, int ndiscard)
{
	int r;
	r = g.handCount[0];
	cassert(r != szhand, "# cards in hand has changed");
	r = g.deckCount[0];
	cassert(r != szdeck, "# cards in deck has changed");
	r = g.coins;
	cassert(r != ncoins, "# coins in hand has changed");
	r = g.discardCount[0];
	cassert(r != ndiscard, "# cards in dscd has changed");

	//for failing test cases, dump results?
	if (failure == 1)
	{
		//DUMP
		printf("FAILURE DETECTED\n");
		printHand(0,&g);
		printDeck(0,&g);
		printDiscard(0,&g);
		printPlayed(0,&g);
		printState(&g);
		printSupply(&g);
		//perhaps tailor dump to type of error?
	}

	//reset failure variable
	failure = 0;
}

int stategen(struct gameState g)
{
	int i, q, r, s;
	char* name;
	//how many cards to add to deck? 
	//either random # between 0 and 100
	s = rand() % 50;
	for (i = 0; i < s; i++)
	{
		r = rand() % treasure_map + 1;
		cardNumToName(r, name);
		q = 0;
		while (g.supplyCount[r] == -1)
		{
			r = rand() % treasure_map + 1;
			cardNumToName(r, name);
			q++;
			if (q > 99) //hard cap of 100 attempts to find a valid card
				break;
		}
		if (q > 99)
		{
			break;
		}
		gainCard(r, &g, 1, 0);	
	}
	shuffle(0,&g);
	//set pre-conditions here
	int szhand = g.handCount[0];
//	printf("Hand now has %d cards\n", szhand);
	int szdeck = g.deckCount[0];
//	printf("Deck now has %d cards\n", szdeck);
	int ncoins = g.coins;
//	printf("There is $%d in hand\n", ncoins);
	int ndiscard = g.discardCount[0];
//	printf("There are %d cards in discard\n",ndiscard);
	//gain an adventurer
	gainCard(7, &g, 2, 0);
	//since gainCard is broken, desired card goes to hand, so just play it 
	playCard(5,0,0,0,&g);

	//run tests
	oracle(g, szhand, szdeck, ncoins, ndiscard);

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
	printf("RANDOM TESTING - adventurer\n");
	int i;
	int seed = atoi(argv[1]);	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	seedchkargs(argc, seed); //note: does not accept 0 for random # seed
	srand(seed);
	for (i = 0; i < rand() % 100; i++)
		casegen(k);
	return 0;
}
