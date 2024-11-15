#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <ftxui/dom/elements.hpp>

class Window
{
  public:
    Window();
  private:
    ftxui::Element DisplaySprite(std::string sprToDisplay);
};

#endif