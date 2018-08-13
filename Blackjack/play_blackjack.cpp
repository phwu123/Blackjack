#include "stdafx.h"
#include <iostream>
#include <array>
#include <string>
#include "enums_struct.h"
#include "deck_setup.h"
#include "enums_struct.h"

bool playerChoice()
{
  std::cout << "\nYour turn\n";
  do {
    std::cout << "Type 'hit' to draw a card or 'stand' to end your turn: ";
    std::string choice;
    std::cin >> choice;
    if (std::cin.fail() || choice != "hit" && choice != "stand")
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input\n";
    }
    else if (choice == "hit")
      return 1;
    else if (choice == "stand")
      return 0;
  } while (1);

}

bool playBlackjack(const std::array<Card, 52> &deck)
{
  //initialize match
  const Card *cardptr = &deck[0];
  int dealerTotal{0}, playerTotal{0};
  std::cout << "Dealer draws a card and places it face down\n";
  int down{getCardValue(*cardptr)};
  dealerTotal += down;
  ++cardptr;
  std::cout << "\nDealer draws a ";
  printCard(*cardptr);
  dealerTotal += getCardValue(*cardptr++);
  if (dealerTotal == 21)
  {
    std::cout << "Dealer has a total of 21. You lose\n";
    return 0;
  }
  std::cout << " and has a total of " << dealerTotal - down << " plus the value of the face-down card\n";
  std::cout << "The dealer deals a ";
  printCard(*cardptr);
  playerTotal += getCardValue(*cardptr++);
  std::cout << " and a ";
  printCard(*cardptr);
  playerTotal += getCardValue(*cardptr++);
  std::cout << " to you.\n\nYou have a total of " << playerTotal << "\n";
  while (playerChoice())
  {
    std::cout << "\nThe dealer deals a ";
    printCard(*cardptr);
    playerTotal += getCardValue(*cardptr++);
    std::cout << " to you.\nYou have a total of " << playerTotal << "\n";
    if (playerTotal > 21)
    {
      std::cout << "Bust! You lose \n";
      return 0;
    }
  }
  std::cout << "\nDealer's turn\n";
  std::cout << "\nDealer flips over the face-down card, revealing a " << down << " and has a total of " << dealerTotal << '\n';
  while (dealerTotal < 17)
  {
    std::cout << "\nDealer draws a ";
    printCard(*cardptr);
    dealerTotal += getCardValue(*cardptr++);
    std::cout << " and has a total of " << dealerTotal << "\n";
    if (dealerTotal > 21)
    {
      std::cout << "Dealer busts, you win!";
      return 1;
    }
  }
  std::cout << "Dealer is over 17, and will stand\n";
  std::cout << "\nYour total is " << playerTotal << "\nDealer's total is " << dealerTotal << "\n";
  return playerTotal > dealerTotal;
}