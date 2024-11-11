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
    std::string GETDealerName();
  protected:
    class DealerDeck : Deck{};
  private:
    std::vector<Card> dealerHand;
    std::string dealerName;
};

#endif