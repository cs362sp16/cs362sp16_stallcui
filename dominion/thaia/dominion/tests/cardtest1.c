#include <stdio.h>
#include "../dominion.h"

// Card Test 1 - Smithy 

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

  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int handPos = 0;

  initializeGame(2, k, 5, &g);
  g.hand[0][0] = smithy;
  g.whoseTurn = 0;
  
  int num = numHandCards(&g);

  playCard(handPos, choice1, choice2, choice3, &g);

  int numa = numHandCards(&g);
  
  // Smithy adds 3 cards to the hand, but remove card after playing
  assertTF(numa = num + 2, "Smithy played\n");

  checkasserts();
}
