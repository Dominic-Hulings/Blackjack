#ifndef BASE_H
#define BASE_H

#include <stack>
#include <string>

#include "global.h"

class BaseCardData : protected CT
{
  protected:
    std::stack<Card> MainDeck;
};

class BasePlayerData : protected CT
{
  protected:
    std::string playerName;
};

#endif