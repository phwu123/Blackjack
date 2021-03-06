#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <array>
#include <cstdlib>
#include "CardGamesSetup.h"

int main()
{
  int blackjackWon{0}, blackjackLost{0};
  int totalWon{0}, totalLost{0};
  do
  {
    switch (pickGame())
    {
    case 1:
    {
      do
      {
        if (playBlackjack())
          blackjackWon += 1;
        else
          blackjackLost += 1;
        displayWinLoss(blackjackWon, blackjackLost);
        std::cout << "Play again? (y/n): ";
      } while (yesNo());
      std::cout << "\nBack to lobby\n\n";
      break;
    }
    default:
      std::cout << "\n\nInvalid choice\n\n";
    }
    std::cout << "Play another game? (y/n): ";

  } while (yesNo());

  return 0;
}
