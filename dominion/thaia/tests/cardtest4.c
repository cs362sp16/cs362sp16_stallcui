#include <stdio.h>
#include "../dominion.h"

// Card Test 4 - Great Hall 

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
  int k[10] = {great_hall, smithy, adventurer, gardens, embargo, cutpurse, mine,
               outpost, baron, tribute};

  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int handPos = 0;

  initializeGame(2, k, 5, &g);
  g.hand[0][0] = great_hall;
  g.whoseTurn = 0;
  
  int num = numHandCards(&g);
  playCard(handPos, choice1, choice2, choice3, &g);
  int numa = numHandCards(&g);
  int actions = g.numActions;

  // Great Hall adds a card to the hand
  assertTF(numa = num, "Number of cards in hand should stay the same\n");
  // It also gives the player +1 actions
  assertTF(g.numActions == actions, "# of actions should stay the same\n");

  checkasserts();
}
