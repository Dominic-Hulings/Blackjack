#ifndef PLAYER_H
#define PLAYER_H

//#include <string>
#include <vector>

#include "base.h"

class Player : BasePlayerData
{
public:
  Player();
  std::string GETPlayerName();
private:
  std::vector<Card> playerHand;
  int playerStack;
};

#endif