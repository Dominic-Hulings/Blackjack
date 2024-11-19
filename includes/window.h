#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <stack>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

#include "presets.h"
#include "global.h"

class Window : protected ScreenPresets
{
  public:
    Window(std::string screen = "NULL");
    void GETscreen(std::string screen);
  protected:
    ftxui::Element GETcardSprite(Card cardToGet, int typeOfCard);
    ftxui::Element DisplaySprite(std::string sprNameToDisplay);
};

#endif