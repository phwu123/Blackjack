#pragma once
#ifndef DECK_SETUP_H
#define DECK_SETUP_H

void printCard(const Card &card);
std::array<Card, 52> createDeck();
void printDeck(const std::array<Card, 52> &deck);
void swapCards(Card &card1, Card &card2);
void shuffleDeck(std::array<Card, 52> &deck);
int getCardValue(const Card &card);
bool loopPlay();

#endif