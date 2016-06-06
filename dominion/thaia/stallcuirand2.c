#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

int oracle(struct gameState g, int ndiscards, int szhand, int* discards, int ncoins, int nbuys, int choice)
{
	int r;
	r = g.numBuys;
	cassert(r != nbuys, "# buys is same");
	if (choice == 1) //if chosen, discard estate, +$4
	{
		r = g.handCount[0];
		cassert(r != szhand, "# cards in hand has changed");
		printDiscard(0,&g);
		r = g.discardCount[0];
		cassert(r != ndiscards, "discarded cards has changed"); 
		r = g.coins;
		cassert(r != ncoins, "number of coins changed");
	}
	else //estate should be added to discard
	{
		printDiscard(0,&g);
		r = g.discardCount[0];
		cassert(r != ndiscards, "estate added to discard");
	}

	if (failure == 1)
	{
		//DUMP
		printf("FAILURE DETECTED\n");
//		printHand(0, &g);
//		printDeck(0, &g);
//		printDiscard(0, &g);
	}

	failure = 0;
	return 0;
}

int stategen(struct gameState g)
{
	int r, s, q, i;
	//test baron
	s = rand() % 80; //run lots of times!
	//add random # of random valid cards to the deck

	printf("new test\n");
	gainCard(baron, &g, 2, 0);
	//	printf("%d\n",gainCard(baron, &g, 2, 0));
//	printHand(0,&g);
	for (i = 0; i < s; i++)
	{
		r = rand() % treasure_map + 1;
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
				//probability that supply is not basically exhausted if
				//99 attempts to give new card have been made
				//is truly mind-boggling
		gainCard(r, &g, 1, 0); //gain card to deck
	}
	shuffle(0, &g); //shuffle when we're done, be considerate! don't cheat

	//collect some stuff for oracle here
	
	int szhand = g.handCount[0];
	int* discards = g.discard[0];
	int ndiscards = g.discardCount[0];
	int ncoins = g.coins;
	int nbuys = g.numBuys;
	//printHand(0,&g);
	int choice = rand() % 2;
	printDiscard(0, &g);
//	printf("choice=%d\n",choice);
	playCard(5,choice,0,0,&g);

//	printHand(0,&g);
//	printf("# coins = %d\n",g.coins);
	//run oracle here
	oracle(g, ndiscards, szhand, discards, ncoins, nbuys, choice);

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
	printf("test\n");
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
