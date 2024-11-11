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
  std::vector<Card> GETPlayerHand();
  int GETPlayerHandValue();
  void SETp2Dealer(void* inp2Dealer);
  int TAKECard(Card cardGiven, void* checkp2Dealer);
private:
  void* p2Dealer;
  std::vector<Card> playerHand;
  int playerStack;
  int playerHandValue;
};

#endif