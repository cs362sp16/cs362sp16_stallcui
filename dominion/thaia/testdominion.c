#include "dominion.h"
#include "interface.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#include <math.h>
#include <time.h>

// Print pointer to array -- use for debugging
void printArr(int *ptr, size_t length){
  //for statement to print array values
  size_t i = 0;
  printf("cards:");
  for (i = 0; i < length; ++i){
    printf(" %d ", ptr[i]);
  }
  printf("\n");
}

int playerTurn(struct gameState *g, int num){
  int i, handPos, actionCards, choice1, choice2, choice3;

  actionCards = 0;  // keep track of the # of action cards in the hand

  //printHand(num, g);
  //printDeck(num, g);

  // ACTION PHASE
  for (i = 0; i < g->handCount[num]; i++){
    if (g->hand[num][i] > 6){  // cards with value 7+ are action cards
      actionCards++;
    }
  }
  //printf("Number of action cards in hand: %d\n", actionCards);

  if (actionCards == 1){  // Play the one action card in the hand
    for (i = 0; i < g->handCount[num]; i++){
      if (g->hand[num][i] > 6){
        choice1 = rand() % g->handCount[num]; 
        choice2 = rand() % g->handCount[num];
        choice3 = rand() % g->handCount[num];
        playCard(i, choice1, choice2, choice3, g);
      }
    }
  }
  
  if (actionCards > 1){ // if multiple actions, try to play one randomly
    printf("Playing a card\n");
    choice1 = rand() % g->handCount[num]; 
    choice2 = rand() % g->handCount[num];
    choice3 = rand() % g->handCount[num];

    //while(g->numActions > 0){
    //  printf("In the while loop\n");
    //  j++;
    // if (j > 25) break;  // Break out of loop after 25 unsuccessful tries
    if (g->numActions >= 1){
      handPos = rand() % g->handCount[num];
      playCard(handPos, choice1, choice2, choice3, g); 
    }
    //}
  }

  // BUY PHASE
  //printSupply(g);
  for (i = 0; i < 10; i++){
    handPos = rand() % (treasure_map + 1);
    if (buyCard(handPos, g) != -1) // buyCard is successfull
      printf("Bought: %d\n", handPos);
  }
  //printDiscard(num, g);
  endTurn(g);

  return 0;
}

int main (int argc, char** argv) {
  int i, j, card, check, dup, randSeed, round;
  struct gameState g;
  struct gameState *p = &g;

  srand(time(NULL));

  int k[10];  // declare hand
  int numPlayers = rand() % 3 + 2;  // Generate random # of players

  // Seed the game
  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }else{
    printf("Invalid number of arguments\n");
    exit(EXIT_FAILURE);
  }

  // Populate kingdomCards
  for (i = 0; i < 10; i++){
    do{
      // kingdom cards should not include any from the first 7
      // i.e. money, curses, estate, duchy, province
      card = (rand() % (treasure_map + 8)) - 7; // +8 b/c of the way mod works
      // 'feast' and 'tribute' are broken so I'm not gonna deal until I get
      // around to fixing them
      if (card == feast || card == tribute) continue;
      dup = 0;
      for (j = 0; j < 10; j++){
        if (k[j] == card){
          dup++;  // duplicate found!
        }
      }
    }while(dup != 0);
    k[i] = card;
  }
  // printArr(k, 10);  // Check that unique cards are unique
  printf ("Starting game.\n");
  
  // LATER -- Add a check for kingdomCards (function !!!)

  check = initializeGame(numPlayers, k, randSeed, p);
  if (check != 0){  // Don't fuck up here
    printf("Error in initialization\n");
    exit(EXIT_FAILURE);
  } 
  //printf("Number of players: %d\n", numPlayers);

  round = 0;  // Initialize var so we can start counting rounds...
  // Game ends when either a stack of Province cards is emptied OR
  // three supply piles are at zero
  while(!isGameOver(p)){
    printf("\nROUND %d \n", round);
    round++;
    for (i = 0; i < numPlayers; i++){
      printf("Player %d -- Score: %d\n", i, scoreFor(i, p));
      check = playerTurn(p, i);
    }
  }
  printf ("Finished game.\n\n");

  return 0;
}
