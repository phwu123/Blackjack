#include "stdafx.h"
#include <iostream>
#include "BlackjackGame.h"

int BlackjackGame::getDealerTotal() const
{
  return m_dealerTotal;
}

int BlackjackGame::getPlayerTotal() const
{
  return m_playerTotal;
}

Deck BlackjackGame::getDeck() const
{
  return m_playDeck;
}

void BlackjackGame::playerDraw()
{
  m_drawnCard = m_playDeck.dealCard().getCardValue();
  m_playerTotal += m_drawnCard;
  if (m_drawnCard == 11) m_playerAce += 1;
}

void BlackjackGame::dealerDraw()
{
  m_drawnCard = m_playDeck.dealCard().getCardValue();
  m_dealerTotal += m_drawnCard;
  if (m_drawnCard == 11) m_dealerAce += 1;
}

void BlackjackGame::firstDraw()
{
  std::cout << "Dealer is initializing hand:\n";
  m_firstCard = m_playDeck.dealFirstCard().getCardValue();
  if (m_firstCard == 11) m_dealerAce += 1;
}

void BlackjackGame::showDealerTotal() const
{
  std::cout << "Dealer has a total of " << m_dealerTotal;
}

bool BlackjackGame::dealerWinFirst()
{
  m_dealerTotal += m_firstCard;
  if (m_dealerTotal == 21)
  {
    std::cout << "Dealer flips over the face-down card, revealing the ";
    m_playDeck.printFirstCard();
    std::cout << ", totaling to 21\n\nYou lose!\n";
    return true;
  }
  return false;
}

void BlackjackGame::showPlayerTotal() const
{
  std::cout << "You have a total of " << m_playerTotal;
  if (m_playerAce > 0)
  {
    std::cout << " and " << m_playerAce << " aces counting as 11";
  }
  std::cout << '\n';
}

