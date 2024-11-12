#include <iostream>
#include <algorithm>
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

int Dealer::EvalHandValue(vector<Card> hand, bool secAceCount = false)
{
  int totalHandValue = 0;
  for (Card card : hand)
  {
    auto it = find(Values.begin(), Values.end(), card.first);

    if (it == Values.end())
    {
      cout << "Card not found.\n";
    }

    if (it - Values.begin() + 1 > 1 && it - Values.begin() + 1 < 11)
    {
      totalHandValue += it - Values.begin() + 1;
    }

    else if (it - Values.begin() + 1 >= 11)
    {
      totalHandValue += 10;
    }

    else
    {
      (secAceCount) ? totalHandValue += 1 : totalHandValue += 11;
    }
  }

  return totalHandValue;
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
  //* INITIAL DEAL -------------------------------------------------

  this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->TAKECard(this->DealerDeck.GETTopMainDeck(), true);

  //* END OF INITIAL DEAL ------------------------------------------
  //* PLAYER TURN --------------------------------------------------

  cout << "Players hand:\n";
  for (Card card : this->pPlayer->GETPlayerHand())
  {
    cout << card.first << " of " << card.second << "\n";
  }

  cout << "Value: " << EvalHandValue(this->pPlayer->GETPlayerHand()) << "\n";

  //* END OF PLAYER TURN -------------------------------------------



  return 1;
}

