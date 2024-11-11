#ifndef DEALER_H
#define DEALER_H

#include <stack>
#include <vector>
// #include <string>

#include "deck.h"
#include "player.h"

class Dealer : CT
{
  public:
    Dealer();
  protected:
    class DealerDeck : Deck{};
};

#endif