#pragma once
#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include <iostream>
#include "deck.h"

class BlackjackGame
{
private:
  Deck m_playDeck;
  int m_playerTotal{ 0 }, m_dealerTotal{ 0 }, m_playerAce{ 0 }, m_dealerAce{ 0 }, m_drawnCard, m_firstCard;

public:
  BlackjackGame(Deck &deck) : m_playDeck(deck)
  {
    std::cout << "\nWelcome to Blackjack! \n\n";
  }
  int getDealerTotal() const;
  int getPlayerTotal() const;
  Deck getDeck() const;
  void playerDraw();
  void dealerDraw();
  void firstDraw();

  void showDealerTotal() const;
  bool dealerWinFirst();
  void showPlayerTotal() const;
};


#endif