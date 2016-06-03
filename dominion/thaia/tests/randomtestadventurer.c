#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../dominion.h"
#include "../rngs.h"

// Random Test Adventurer

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s", msg);
    failed = 1;
  }
}

/*void checkasserts(){
  if (!failed){
    printf("TEST SUCCESSFULLY COMPLETED.\n\n");
  }
}*/

int main(int argc, char *argv[]){
  int i, j, r, ff, numplayers, randSeed;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  int choice[4];
  srand(time(NULL)); // Seed rng
  
  struct gameState g;

  printf("``adventurer`` -- RANDOM TESTS START \n");

  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }
  else{
    randSeed = rand();
  }

  numplayers = rand() % 2 + 2;
  initializeGame(numplayers, k, randSeed, &g);

  for (i = 0; i < numplayers; i++){
    g.deckCount[i] = rand() % MAX_DECK;
    g.handCount[i] = rand() % MAX_HAND;
    g.discardCount[i] = rand() % MAX_HAND;
    // Randomly generating choices to be played in cardEffect
    for (j = 0; j < 3; j++){
      choice[j] = rand() % 2 + 1;
    }
    r = cardEffect(adventurer, choice[0], choice[1], choice[2], &g, 0, 0);
    assertTF(r == 0, "Adventurer played successfully\n");
  }
  // ff = force fail to check that cardEffect isn't arbitrarily passing
  g.handCount[i] = MAX_HAND + 1;
  ff = cardEffect(adventurer, choice[0], choice[1], choice[2], &g, 0, 0);
  assertTF(ff = 0, "Adventurer played successfully\n");

  printf("``adventurer`` -- RANDOM TESTING COMPLETE \n\n");
  
  //failed = 0; // reset flag to 0 after ff -- otherwise checkasserts() fails
  //checkasserts();
 
  /* For some reason, using checkasserts() in place of a return/exit statement
     Causes the following to be printed in the coverage results:
    
        File '<built-in>'
        No executable lines
        Removing '<built-in>.gcov'

    So to avoid that, I'm returning zero here instead of using checkasserts()
    Note: I'm only making the change in this file */
  
  return 0;
}
