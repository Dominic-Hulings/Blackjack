#include <iostream>

#include "game.h"

using std::string;

Game::Game()
{
  this->GameDealer.SETPointers(&this->GamePlayer, &this->GameDealer);
  this->GamePlayer.SETp2Dealer(&this->GameDealer);
}