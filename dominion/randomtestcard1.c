#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "dominion.h"
#include "interface.h"

int main(int argc, char* argv[])
{
	int i;
	int seed = atoi(argv[1]);	
	seedchkargs(argc, seed); //note: does not accept 0 for random # seed
	srand(seed);
	printf("Random testing. Here there be dragons\n");
	struct gameState g;
}
