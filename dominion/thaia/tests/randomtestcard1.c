#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../dominion.h"
#include "../rngs.h"

// Random Test Cutpurse

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s\n", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed){
    printf("TEST SUCCESSFULLY COMPLETED\n\n");
  }
}

int main(int argc, char *argv[]){
  int i, j, r, numplayers, randSeed;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  int choice[4];
  srand(time(NULL)); // Seed rng

  struct gameState g;

  printf("``cutpurse`` -- RANDOM TESTS START \n");

  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }else{
    randSeed = rand();
  }

  numplayers = rand() % 2 + 2;
  //randSeed = rand();
  initializeGame(numplayers, k, randSeed, &g);

  for (i = 0; i < numplayers; i++){
    g.handCount[i] = rand() % MAX_HAND;
    // Inner loop randomly generates choices from 1-3 for function cardEffect
    for (j = 0; j < 3; j++){
      choice[i] = rand() % 2 + 1;
    }
    r = cardEffect(cutpurse, choice[0], choice[1], choice[2], &g, 0, 0);
    assertTF(r == 0, "Cutpurse played successfully\n");
  }
  printf("``cutpurse`` -- RANDOM TESTING COMPLETE \n");
  
  checkasserts();
}
