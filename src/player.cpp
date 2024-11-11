//#include <iostream>

#include "player.h"

using std::string, std::vector;

typedef CT::Card Card;

Player::Player()
{
  this->playerName = "Hank";
  this->playerStack = 500;
}

//* GET METHODS \\

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

//* END OF GET METHODS \\