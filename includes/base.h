#ifndef BASE_H
#define BASE_H

#include <stack>
#include <ftxui/dom/elements.hpp>
//#include <string>

#include "global.h"

class BaseCardData : protected CT
{
  protected:
    std::stack<Card> MainDeck;
};

#endif