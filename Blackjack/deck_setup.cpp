#include "stdafx.h"
#include <iostream>
#include <array>
#include <random>
#include <string>
#include "enums_struct.h"

void printCard(const Card &card)
{
  switch (card.rank)
  {
  case RANK_2:      std::cout << "2";   break;
  case RANK_3:      std::cout << "3";   break;
  case RANK_4:      std::cout << "4";   break;
  case RANK_5:      std::cout << "5";   break;
  case RANK_6:      std::cout << "6";   break;
  case RANK_7:      std::cout << "7";   break;
  case RANK_8:      std::cout << "8";   break;
  case RANK_9:      std::cout << "9";   break;
  case RANK_10:     std::cout << "10";  break;
  case RANK_JACK:   std::cout << "J";   break;
  case RANK_QUEEN:  std::cout << "Q";   break;
  case RANK_KING:   std::cout << "K";   break;
  case RANK_ACE:    std::cout << "A";   break;
  }
  switch (card.suit)
  {
  case SUIT_CLUB:     std::cout << "C"; break;
  case SUIT_DIAMOND:  std::cout << "D"; break;
  case SUIT_HEART:    std::cout << "H"; break;
  case SUIT_SPADE:    std::cout << "S"; break;
  }
}

std::array<Card, 52> createDeck()
{
  std::array<Card, 52> deck;
  int cardNum{ 0 };
  for (int suit{ 0 }; suit < MAX_SUITS; ++suit)
    for (int rank{ 0 }; rank < MAX_RANKS; ++rank)
    {
      deck[cardNum].rank = static_cast<CardRank>(rank);
      deck[cardNum].suit = static_cast<CardSuit>(suit);
      ++cardNum;
    }
  return deck;
}


void printDeck(const std::array<Card, 52> &deck)
{
  for (const Card &card : deck)
  {
    printCard(card);
    std::cout << " ";
  }
  std::cout << '\n';
}

void swapCards(Card &card1, Card &card2)
{
  Card temp{ card1 };
  card1 = card2;
  card2 = temp;
}

void shuffleDeck(std::array<Card, 52> &deck)
{
  std::random_device rd;
  std::mt19937 mersenne(rd());
  std::uniform_int_distribution<> die(0, 51);
  for (int card{ 0 }; card < 52; card++)
    swapCards(deck[card], deck[die(mersenne)]);
}

int getCardValue(const Card &card)
{
  switch (card.rank)
  {
  case RANK_2:      return 2;
  case RANK_3:      return 3;
  case RANK_4:      return 4;
  case RANK_5:      return 5;
  case RANK_6:      return 6;
  case RANK_7:      return 7;
  case RANK_8:      return 8;
  case RANK_9:      return 9;
  case RANK_10:
  case RANK_JACK:
  case RANK_QUEEN:
  case RANK_KING:   return 10;
  case RANK_ACE:    return 11;
  default:          return 0;
  }
}

bool loopPlay()
{
  do {
    std::cout << "\nPlay again? (y/n) \n";
    std::string loop;
    std::cin >> loop;
    if (std::cin.fail() || loop != "y" && loop != "n")
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input\n";
    }
    else if (loop == "y")
      return 1;
    else if (loop == "n")
      return 0;
  } while (1);
}