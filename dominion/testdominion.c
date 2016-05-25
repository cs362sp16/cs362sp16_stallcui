#include "dominion.h"
#include "interface.h"
#include "tests.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define VERBOSE 1 

int takeTurn(struct gameState *g, int pnum)
{
	int r, i, j, numActionsHand;
	numActionsHand = 0;
	if (VERBOSE == 1)
	{	
		printHand(pnum,g);
		printDeck(pnum,g);
	}

	//ACTION PHASE
	
	if (VERBOSE == 1)
		printHand(pnum, g);

	for (i = 0; i < g->handCount[pnum]; i++)
		if (g->hand[pnum][i] > 6)
			numActionsHand++;

	if (VERBOSE == 1)
		printf("numActionsHand = %d\n", numActionsHand);

	if (numActionsHand == 1)
		for (i = 0; i < g->handCount[pnum]; i++)
			if (g->hand[pnum][i] > 6)
				playCard(i, rand() % 7, rand() % 7, rand() % 7, g);
	j = 0;
	if (numActionsHand > 1)
	{
		if (VERBOSE == 1)
			printf("trying to play a card\n");
		while (g->numActions > 0)
		{
			j++;
			if (j > 100)
				break;
	
			r = rand() % g->handCount[pnum];
			if (VERBOSE == 1)
				printf("trying to play card %d\n", r);
			playCard(r, rand() % 7, rand() % 7, rand() % 7, g);
		}
	}

	if (VERBOSE == 1)
		printSupply(g);

	for (i = 0; i < 10; i++) //up to 10 times...
	{
		r = rand() % 27; //try to buy random card
		if (-1 != buyCard(r, g))
			if (VERBOSE == 1)
				printf("bought card %d\n", r);
	}

	if (VERBOSE == 1)
		printDiscard(pnum,g);	
	endTurn(g);

	if (VERBOSE == 1)
		printf("turn over\n");

	return 0;
}

int main(int argc, char* argv[])
{
	int r, i, j, numPlayers;
	int seed = atoi(argv[1]);
	seedchkargs(argc, seed); //check the seed for OK-ness
	srand(seed); //seed random # generator
	struct gameState G;
	struct gameState *g = &G;

	//declare random set of kingdom cards
	int k[10];
	for(i = 0; i < 10; i++) 
	{
		r = rand() % 20 + 7;
		for (j = 0; j < 10; j++)
		{
			while (k[j] == r)
			{
				r = rand() % 20 + 7;
				j = 0;
			}
		}	
		if (VERBOSE == 1)
			printf("r = %d\n", r);
		k[i] = r;
	}

	//initialize game
	r = rand() % 3 + 2;
	if (VERBOSE == 1)
		printf("# players = %d\n", r);
	numPlayers = r;
	r = initializeGame(numPlayers, k, seed, g);
	if (r != 0)
	{
		printf("error in initializeGame\n");
		exit(1);
	}

	j=0;
	//while game isn't over, take turns
	while (!isGameOver(g))
//	for (j = 0; j < 3; j++)
	{
		printf("~~~~ROUND %d~~~~\n", j);
		j++;
		for (i = 0; i < numPlayers; i++)
		{
			r = takeTurn(g, i);	
		}
	}

	

	return 0;
}
