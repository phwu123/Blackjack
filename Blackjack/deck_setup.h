#pragma once
#ifndef DECK_SETUP_H
#define DECK_SETUP_H

std::array<Card, 52> createDeck();
auto printCard(const Card &card);
void printDeck(const std::array<Card, 52> &deck);

#endif