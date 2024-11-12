#include <iostream>
#include <vector>

#include "dealer.h"

using std::string, std::pair, std::vector, std::cout, std::cin;
typedef CT::Card Card;

Dealer::Dealer()
{
  this->dealerName = "DealerName";
}

string Dealer::GETDealerName()
{
  return this->dealerName;
}

Deck* Dealer::GETDealerDeck()
{
  return &this->DealerDeck;
}

pair<vector<Card>, int> Dealer::GETDealerHand()
{
  return {this->dealerHand, this->dealerHandValue};
}

Player* Dealer::GETpPlayer()
{
  return this->pPlayer;
}

void Dealer::SETp2Player(Player* p2Player)
{
  this->pPlayer = p2Player;
}

void Dealer::TAKECard(Card cardGiven, bool isFaceDown)
{
  this->dealerHand.push_back(cardGiven);
}

int Dealer::startHand()
{
  //* BETTING ------------------------------------------------------

  int inNumToBet = 0;
  int amtBet = 0;
  cout << "How much to bet on this hand?\n";
  cout << "You have " << pPlayer->GETPlayerStack() << " total.\n";
  cin >> inNumToBet;

  if (inNumToBet <= pPlayer->GETPlayerStack())
  {
    amtBet = inNumToBet;
  }
  
  else
  {
    cout << "error1";
    return 0;
  }

  

  //* END OF BETTING -----------------------------------------------
  this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->TAKECard(this->DealerDeck.GETTopMainDeck(), true);



  return 1;
}

