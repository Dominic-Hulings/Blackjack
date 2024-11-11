#ifndef DEALER_H
#define DEALER_H

#include <vector>
// #include <string>

#include "deck.h"
#include "player.h"

class Dealer : CT
{
  public:
    Dealer();
    std::string GETDealerName();
    void* GETpDealer();
    void SETPointers(Player* p2Player, Dealer* p2Dealer);
    Deck DealerDeck;
  protected:
  private:
    Player* pPlayer;
    Dealer* pDealer;
    std::vector<Card> dealerHand;
    std::string dealerName;
};

#endif