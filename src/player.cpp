//#include <iostream>

#include "player.h"

using std::string, std::vector;

typedef CT::Card Card;

Player::Player()
{
  this->playerName = "Hank";
  this->playerStack = 500;
}

//* GET METHODS \\ ------------------------------------------

string Player::GETPlayerName()
{
  return this->playerName;
}

vector<Card> Player::GETPlayerHand()
{
  return this->playerHand;
}

int Player::GETPlayerHandValue()
{
  return this->playerHandValue;
}

//* END OF GET METHODS \\ -----------------------------------
//* SET METHODS \\ ------------------------------------------

void Player::SETp2Dealer(void* inp2Dealer)
{
  this->p2Dealer = inp2Dealer;
}
//* END OF SET METHODS \\ -----------------------------------
//* TAKE METHODS \\ -----------------------------------------

int Player::TAKECard(Card cardGiven, void* checkp2Dealer)
{
  if (checkp2Dealer == this->p2Dealer)
  {
    this->playerHand.push_back(cardGiven);
    return 1;
  }

  else
  {
    return 0;
  }
}

//* END OF TAKE METHODS \\ ----------------------------------