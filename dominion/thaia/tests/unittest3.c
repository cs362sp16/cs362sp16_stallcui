#include <stdio.h>
#include "../dominion.h"

// Test 3 - check that winners are properly set in getWinners()

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
  struct gameState g;

  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};

  initializeGame(4, k, 5, &g);     
  int players[4] = {45, 21, 99, 25};
  int status = getWinners(players, &g);
  assertTF(status == 0, "Winners have been set\n");
 
  checkasserts();
}
