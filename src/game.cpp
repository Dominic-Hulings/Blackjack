//#include <iostream>

#include "game.h"

using std::string, std::pair;

Game::Game()
{
  this->GameDealer.SETp2Player(&this->GamePlayer);
  this->GamePlayer.SETp2Dealer(&this->GameDealer);
  this->GameDealer.WonHand(this->GameDealer.Hand());
}