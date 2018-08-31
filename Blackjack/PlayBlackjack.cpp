#include "stdafx.h"
#include "PlayBlackjack.h"
#include <chrono>
#include <thread>

bool hitStand()
{
  while (1)
  {
    std::cout << "Your turn.  h (Hit) or s (Stand): ";
    char choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cout << "Invalid choice\n";
    }
    else if (choice == 'h')
    {
      std::cout << "\nHit!\n";
      return true;
    }
    else if (choice == 's')
    {
      std::cout << "\nStand\n";
      return false;
    }
  }
}

bool playBlackjack()
{
  Deck deck;
  deck.shuffleDeck();
  deck.printDeck();
  BlackjackGame game(deck);
  game.firstDraw();
  game.dealerDraw();
  game.showDealerTotal();
  std::cout << " plus the face-down card\n\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  if (game.dealerWinFirst())
    return false;
  std::cout << "Your hand is being initialized:\n";
  game.playerDraw();
  game.playerDraw();
  game.showPlayerTotal();
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  while (hitStand())
  {
    game.playerDraw();
    game.showPlayerTotal();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if (game.getPlayerTotal() > 21)
    {
      std::cout << "You busted!\n\nToo bad, you lose\n\n";
      return false;
    }
  }
  std::cout << "Your turn has ended";
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "\n\nDealer's turn\nDealer flips the face-down card over and reveals the ";
  game.getDeck().printFirstCard();
  game.showDealerTotal();
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "\n\n";
  while (game.getDealerTotal() < 17)
  {
    std::cout << "Dealer has less than 17, and will hit\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    game.dealerDraw();
    game.showDealerTotal();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if (game.getDealerTotal() > 21)
    {
      std::cout << "Dealer busted!\n\nLucky, you win!\n\n";
      return true;
    }
  }
  std::cout << "Dealer has over 17 and will stand\n\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Your total: " << game.getPlayerTotal() << "\nDealer's total: " << game.getDealerTotal() << "\n\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  if (game.getPlayerTotal() > game.getDealerTotal())
  {
    std::cout << "You win!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return true;
  }
  std::cout << "You lose, better luck next time\n";
  return true;
}