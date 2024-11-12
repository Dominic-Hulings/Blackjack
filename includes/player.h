#ifndef PLAYER_H
#define PLAYER_H

// #include <string>
#include <vector>

#include "base.h"

class Player : BasePlayerData
{
public:
  Player();
  std::string GETPlayerName();
  std::vector<Card> GETPlayerHand();
  int GETPlayerStack();
  void SETp2Dealer( void* inp2Dealer );
  void TAKECard( Card cardGiven, bool isFaceDown );

private:
  void* p2Dealer;
  std::vector<Card> playerHand;
  int playerStack;
};

#endif