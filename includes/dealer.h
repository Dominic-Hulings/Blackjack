#ifndef DEALER_H
#define DEALER_H

#include <vector>
// #include <string>

#include "deck.h"

class Dealer : CT
{
  public:
    Dealer();
    std::string GETDealerName();
  protected:
    Deck DealerDeck;
  private:
    std::vector<Card> dealerHand;
    std::string dealerName;
};

#endif