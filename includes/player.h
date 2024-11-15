#ifndef PLAYER_H
#define PLAYER_H

// #include <string>
#include <vector>

#include "base.h"

class Player : CT
{
public:
  Player();
  std::string GETPlayerName();
  std::vector<Card> GETPlayerHand();
  int GETPlayerStack();
  void FundTransfer(int amt, bool isTaking);
  void SETp2Dealer( void* inp2Dealer );
  void TAKECard( Card cardGiven, bool isFaceDown );

private:
  void* p2Dealer;
  std::string playerName;
  std::vector<Card> playerHand;
  int playerStack;
};

#endif