#include <stdio.h>
#include "../dominion.h"

// Card Test 3 - Steward 

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
  int k[10] = {steward, smithy, adventurer, gardens, embargo, cutpurse, mine,
               outpost, baron, tribute};

  int choice2 = 0;
  int choice3 = 0;
  int handPos = 0;

  initializeGame(2, k, 5, &g);
  g.hand[0][0] = steward;
  g.whoseTurn = 0;  

  int num = numHandCards(&g);
  playCard(handPos, 1, choice2, choice3, &g);
  int numa = numHandCards(&g);
  
  // Steward adds two cards to the hand if choice1 == 1
  assertTF(numa = num + 2, "Add 2 card to hand\n");

  int coins = g.coins;
  // Steward adds two coins if choice1 == 2
  printf("coins b: %d\n", g.coins);
  playCard(handPos, 2, choice2, choice3, &g);
  assertTF(g.coins == coins + 2, "Add 2 coins\n");
  printf("coins a: %d\n", g.coins);

  num = numHandCards(&g);
  // Steward trashes two cards if choice1 == 3
  playCard(handPos, 3, choice2, choice3, &g); 
  numa = numHandCards(&g);
  assertTF(numa == num - 3, "Trash 2 cards\n");

  checkasserts();
}
