#include <stdio.h>
#include "../dominion.h"
//#include "assert.h"

// Test 1 - Game initialization

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s\n", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  }
}

int main(){
  struct gameState g;
  int kingdomCards[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine,
                          ambassador, outpost, baron, tribute};
  int kCards[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine,
                    ambassador, outpost, baron, baron};

  int status = initializeGame(2, kingdomCards, 5, &g);
  assertTF(status == 0, "Game properly initialized");

  status = initializeGame(2, kCards, 5, &g);
  assertTF(status == -1, "Duplicate card in setup --> Failure");

  status = initializeGame(500, kingdomCards, 5, &g);
  assertTF(status == -1, "There are too many players!");

  checkasserts();
}
