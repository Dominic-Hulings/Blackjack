#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <ftxui/dom/elements.hpp>

#include "game.h"

class Window
{
  public:
    Window();
  private:
    void StartGame();
    ftxui::Element DisplaySprite(std::string sprToDisplay);

    ftxui::Screen staticFullScreen;
};

#endif