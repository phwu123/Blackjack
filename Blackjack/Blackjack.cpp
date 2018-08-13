#include "stdafx.h"
#include <iostream>
#include <array>
#include "enums_struct.h"
#include "deck_setup.h"

int main()
{
    std::array<Card, 52> deck{createDeck()};
    printDeck(deck);
    return 0;
}

