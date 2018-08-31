#include "stdafx.h"
#include <iostream>
#include <array>
#include <random>
#include <cassert>
#include "deck.h"

void Deck::swapCards(Card &c1, Card &c2)
{
  Card temp{c1};
  c1 = c2;
  c2 = temp;
}

Deck::Deck()
{
  int cardNum{0};
  for (int suit{ 0 }; suit < Card::MAX_SUITS; ++suit)
    for (int rank{ 0 }; rank < Card::MAX_RANKS; ++rank)
      m_deck[cardNum++] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
}

void Deck::printDeck() const
{
  for (const Card &card : m_deck)
  {
    card.printCard();
    std::cout << " ";
  }
  std::cout << '\n';
}

void Deck::shuffleDeck()
{
  std::random_device rd;
  std::mt19937_64 mersenne(rd());
  std::uniform_int_distribution<> die(0, 51);
  for (int card{ 0 }; card < 52; ++card)
    swapCards(m_deck[card], m_deck[die(mersenne)]);
}

const Card &Deck::dealCard()
{
  assert(m_cardIndex < 52);
  std::cout << "Dealer deals the ";
  m_deck[m_cardIndex].printCard();
  std::cout << '\n';
  return m_deck[m_cardIndex++];
}

const Card &Deck::dealFirstCard()
{
  assert(m_cardIndex < 1);
  std::cout << "Dealer draws a card and places it face-down\n";
  return m_deck[m_cardIndex++];
}

void Deck::printFirstCard() const
{
  m_deck[0].printCard();
  std::cout << '\n';
}