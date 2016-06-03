#include <stdio.h>
#include "../dominion.h"

// Test 4 - Game over

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s\n", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed){
    printf("TEST SUCCESSFULLY COMPLETED\n");
  }
}

int main(){
  
  // setup an empty game
  struct gameState g; //= calloc(1, sizeof(struct gameState));
  
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, province, curse,
               mine, outpost, tribute};
  
  initializeGame(2, k, 5, &g);

  int status = isGameOver(&g);
  assertTF(status == 0, "Newly initialized game. Should not be over\n");

  // Force game end by setting province supply to 0
  g.supplyCount[province] = 0;
  status = isGameOver(&g);
  assertTF(status == 1, "All Province cards have been used\n");

  // Reset province, set three other supply cards to 0
  g.supplyCount[province] = 2;
  g.supplyCount[curse] = 0;
  g.supplyCount[adventurer] = 0;
  g.supplyCount[cutpurse] = 0;

  status = isGameOver(&g);
  assertTF(status == 1, "At least three supply piles have been emptied\n");

  checkasserts();
}
