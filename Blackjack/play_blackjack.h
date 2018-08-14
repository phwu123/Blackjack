#pragma once
#ifndef PLAY_BLACKJACK_H
#define PLAY_BLACKJACK_H

void incrementAce(const Card *card, int &aces);
bool playerChoice();
bool playBlackjack(const std::array<Card, 52> &deck);

#endif