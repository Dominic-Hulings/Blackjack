#ifndef LOGIC_H
#define LOGIC_H

#include <stack>

#include "dealer.h"
#include "deck.h"
#include "global.h"

class GameLogic : CT
{
protected:
  GameLogic(Dealer* inpDealer);
  void NewHand();
  int InitialDeal();
  Dealer* pDealer;
  Deck* pCurrentDeck;

};






#endif