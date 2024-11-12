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
  std::pair<std::vector<Card>, int> GETDealerHand();
  void SETp2Player(Player* p2Player);
  void TAKECard( Card cardGiven, bool isFaceDown );
  Deck* GETDealerDeck();
  Player* GETpPlayer();
private:
  std::string dealerName;
  Player* pPlayer;
  Deck DealerDeck;
  std::vector<Card> dealerHand;
  int dealerHandValue;
};

#endif