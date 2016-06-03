#include <stdio.h>
#include "../dominion.h"

// Card Test 2 - Village 

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
  int k[10] = {village, smithy, adventurer, gardens, embargo, cutpurse, mine,
            outpost, baron, tribute};

  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int handPos = 0;

  initializeGame(2, k, 5, &g);
  g.hand[0][0] = village;
  g.whoseTurn = 0;
  g.numActions = 1;  

  int num = numHandCards(&g);
  playCard(handPos, choice1, choice2, choice3, &g);
  int numa = numHandCards(&g);
 
  // Amount of cards in hand should be same as start
  assertTF(numa == num, "Number of cards in hand shouldn't change\n");

  // # of actions should == 2 (Subtract 1 to play card, add 2 after playing
  assertTF(g.numActions == 2, "Number of actions should increase by 2\n");

  checkasserts();
}
