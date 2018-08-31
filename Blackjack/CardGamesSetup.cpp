#include "stdafx.h"
#include "CardGamesSetup.h"
#include <iostream>


bool yesNo()
{
  while (1)
  {
    char choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
      std::cin.clear();
    else if (choice == 'y')
      return true;
    else if (choice == 'n')
      return false;
    else
      std::cout << "Invalid response\n\nPlease answer with y/n";
  }
}

int pickGame()
{
  while (1)
  {
    std::cout << "Pick a game: 1 (Blackjack): ";
    int gameChoice;
    std::cin >> gameChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
      std::cin.clear();
    else
      return gameChoice;
  }
}

const void displayWinLoss(const int won, const int lost)
{
  std::cout << "\n\nBlackjack W/L: " << won << "/" << lost << "\n\n";
}