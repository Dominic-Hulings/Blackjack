//#include <iostream>
#include <vector>

#include "dealer.h"

using std::string, std::pair, std::vector;
typedef CT::Card Card;

Dealer::Dealer()
{
  this->dealerName = "DealerName";
}

string Dealer::GETDealerName()
{
  return this->dealerName;
}

pair<vector<Card>, int> Dealer::GETDealerHand()
{
  return {this->dealerHand, this->dealerHandValue};
}

void Dealer::SETp2Player(Player* p2Player)
{
  this->pPlayer = p2Player;
}

