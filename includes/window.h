#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <ftxui/dom/elements.hpp>

class Window
{
  public:
    Window();
  private:
    std::string DisplaySprite(std::string sprToDisplay);
    ftxui::Element AllLinesOfSprite(std::string sprFilePath, int lineNum);
};

#endif