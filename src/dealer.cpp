#include <iostream>

#include "dealer.h"

using std::string;

Dealer::Dealer()
{
  this->dealerName = "DealerName";
}

string Dealer::GETDealerName()
{
  return this->dealerName;
}

void* Dealer::GETpDealer()
{
  return this->pDealer;
}

void Dealer::SETPointers(Player* p2Player, Dealer* p2Dealer)
{
  this->pPlayer = p2Player;
  this->pDealer = p2Dealer;
}

