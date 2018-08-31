#pragma once
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <array>

class Deck
{
  private:
    std::array<Card, 52> m_deck;
    int m_cardIndex{0};
    static void swapCards(Card &c1, Card &c2);
  public:
    Deck();
    void printDeck() const;
    void shuffleDeck();
    const Card& dealCard();
    const Card& dealFirstCard();
    void printFirstCard() const;
  
    friend void Card::printCard() const;
};

#endif