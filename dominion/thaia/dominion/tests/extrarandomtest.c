#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../dominion.h"
#include "../rngs.h"

// Random Test Baron

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s\n", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed){
    printf("TEST SUCCESSFULLY COMPLETED.\n\n");
  }
}

int main(int argc, char *argv[]){
  int i, j, r, numplayers, randSeed, prevb, buys;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  int choice[4];
  srand(time(NULL)); // Seed rng

  struct gameState g;

  printf("``baron`` -- RANDOM TESTS START \n");

  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }else{
    randSeed = rand();
  }

  numplayers = rand() % 2 + 2;  // ensure at least 2 players
  //randSeed = rand();
  initializeGame(numplayers, k, randSeed, &g);

  for (i = 0; i < numplayers; i++){
    g.handCount[i] = rand() % MAX_HAND;
    g.discardCount[i] = rand() % MAX_HAND;
    // Generating choices to be used in cardEffect()
    for (j = 0; j < 3; j++){
      choice[j] = rand() % 2 + 1;
    }
    prevb = g.numBuys;  // number of buys before baron is used
    r = cardEffect(baron, choice[0], choice[1], choice[2], &g, 0, 0);
    buys = g.numBuys; // # should increase by 1

    assertTF(buys == prevb + 1, "Buys increased by 1\n"); 
    assertTF(r == 0, "Baron played successfully\n");
  }
  printf("``baron`` -- RANDOM TESTING COMPLETE \n");
  
  checkasserts();
}
