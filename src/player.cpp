//#include <iostream>

#include "player.h"

using std::string;

Player::Player()
{
  this->playerName = "Hank";
  this->playerStack = 500;
}

string Player::GETPlayerName()
{
  return this->playerName;
}