#include <stdio.h>
#include "../dominion.h"

// Test 2 - updateCoins

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

  int handPos = 1;
  int choice1 = 1;
  int choice2 = 2;
  int choice3 = 3;

  initializeGame(2, k, 5, &g);
  int status = playCard(handPos, choice1, choice2, choice3, &g); 
  
  g.phase = 0;
  status = playCard(handPos, choice1, choice2, choice3, &g); 
  assertTF(status == 0, "Correct phase\n");

  g.numActions = 1;
  status = playCard(handPos, choice1, choice2, choice3, &g);
  assertTF(status == -1, "Valid amount of actions to play card\n");

  g.numActions = 0;
  status = playCard(handPos, choice1, choice2, choice3, &g);
  assertTF(status == -1, "No actions left\n");

  g.numActions = 1;
  g.phase = 1;
  status = playCard(handPos, choice1, choice2, choice3, &g);  
  assertTF(status == -1, "Incorrect phase to play card\n");

  checkasserts();
}
