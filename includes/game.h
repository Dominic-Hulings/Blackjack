#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "dealer.h"
#include "player.h"

class Game : CT
{
  public:
    Game();
  private:
    class GameDealer : Dealer{};
};

#endif