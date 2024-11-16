#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <map>
#include <ftxui/dom/elements.hpp>

//#include "base.h"

class Window
{
  public:
    Window();
    void AddElement(std::string element);
  private:
    std::map<std::string, ftxui::Element*> presetElements;
    ftxui::Screen staticScreenFull;
};

#endif