#ifndef PRESETS_H
#define PRESETS_H

#include <ftxui/dom/elements.hpp>
#include <map>
#include <string>

class ScreenPresets
{
  public:
    ScreenPresets();
  protected:
    void MainMenuScreen();

    ftxui::Element DisplaySprite(std::string sprNameToDisplay);
    std::map<std::string, int> screens;
};



#endif