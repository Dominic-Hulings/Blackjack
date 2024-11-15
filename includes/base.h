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

class WinPresets
{
  protected:
    ftxui::Element DisplaySprite(std::string sprNameToDisplay);
    void MainMenuPre();
};

#endif