#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

int stategen(struct gameState g)
{
	int r, i;
	//determine # players
	r = rand() % 3;
	printf("# players = %d\n", r+2);

	//determine kingdom cards randomly (note chosen card must be
	//present hence the 9 iterations instead of 10)
	r = rand() % 26;
	printf("rand1: %d\n", r);
	printf("testing: %d\n", getCost(r));
	return 0;
}

int main(int argc, char* argv[])
{
	printf("RANDOM TESTING - adventurer\n");
	int i;
	int seed = atoi(argv[1]);	
	seedchkargs(argc, seed); //note: does not accept 0 for random # seed
	srand(seed);
	struct gameState g;
	stategen(g);
}
