#ifndef PRESETS_H
#define PRESETS_H

#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <map>
#include <string>

#include "global.h"

class ScreenPresets : public CT
{
  public:
    ScreenPresets();
  protected:
    void MainMenuScreen();
    void CardTest();
    void TableTest();
    ftxui::Element DisplaySprite(std::string sprNameToDisplay);
    ftxui::Element GETcardSprite(Card cardToGet, int typeOfCard);
    std::map<std::string, int> screens;
};



#endif