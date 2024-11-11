#ifndef GAME_H
#define GAME_H

#include "dealer.h"
#include "player.h"

class Game : CT
{
  public:
    Game();
  private:
    Player GamePlayer;
    Dealer GameDealer;
};

#endif