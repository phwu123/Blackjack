#include "stdafx.h"
#include <iostream>
#include <array>
#include "enums_struct.h"
#include "deck_setup.h"
#include "play_blackjack.h"

int main()
{
  int playerWins{0};
  int dealerWins{0};
  bool playAgain{ false };
  do {
    //initialize game state
    std::array<Card, 52> deck{ createDeck() };
    shuffleDeck(deck);
    printDeck(deck);
    if (playBlackjack(deck))
      ++playerWins;
    else
      ++dealerWins;
    std::cout << "\nYour w/l: " << playerWins << "/" << dealerWins << "\n";
    playAgain = loopPlay();
  } while (playAgain);
  std::cout << "Thanks for playing!\n\n";
  return 0;
}
