#ifndef PLAYER_H
#define PLAYER_H

//#include <string>
#include <vector>

#include "global.h"

class Player : CT
{
public:
  Player();
private:
  std::vector<Card> playerHand;
};

#endif