//#include <iostream>

#include <stack>

#include "logic.h"

using std::string, std::stack;

GameLogic::GameLogic(Dealer* inpDealer)
{
  this->pDealer = inpDealer;
  this->pCurrentDeck = this->pDealer->GETDealerDeck();
}

void GameLogic::NewHand()
{
  this->InitialDeal();
}

int GameLogic::InitialDeal()
{

}