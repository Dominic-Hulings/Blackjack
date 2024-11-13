#ifndef DEALER_H
#define DEALER_H

#include <vector>

#include "deck.h"
#include "player.h"

class Dealer : CT
{
public:
  Dealer();
  std::string GETDealerName();
  std::vector<Card> GETDealerHand();
  void SETp2Player(Player* p2Player);
  void TAKECard( Card cardGiven, bool isFaceDown );
  Deck* GETDealerDeck();
  Player* GETpPlayer();
  std::pair<int, int> Hand(); //* First int is who won (1 for player, 2 for dealer, 3 for tie) and second int is amt won
  void WonHand(std::pair<int, int> wonAndAmt);
  int EvalHandValue(std::vector<Card> hand);
private:
  //int startHand();
  std::string dealerName;
  Player* pPlayer;
  Deck DealerDeck;
  std::vector<Card> dealerHand;
  int dealerHandValue;
};

#endif