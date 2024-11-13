//#include <iostream>
//#include <algorithm>

#include "player.h"

using std::string, std::vector, std::pair;

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

int Player::GETPlayerStack()
{
  return this->playerStack;
}

//* END OF GET METHODS \\ -----------------------------------
//* SET METHODS \\ ------------------------------------------

void Player::SETp2Dealer(void* inp2Dealer)
{
  this->p2Dealer = inp2Dealer;
}
//* END OF SET METHODS \\ -----------------------------------
//* TAKE METHODS \\ -----------------------------------------

void Player::TAKECard(Card cardGiven, bool isFaceDown)
{
  this->playerHand.push_back(cardGiven);
}

//* END OF TAKE METHODS \\ ----------------------------------

void Player::FundTransfer(int amt, bool isTaking)
{
  if (isTaking)
  {
    this->playerStack -= amt;
  }

  else
  {
    this->playerStack += amt;
  }
}