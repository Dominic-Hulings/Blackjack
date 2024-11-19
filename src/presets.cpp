#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp" 
#include "ftxui/dom/elements.hpp"

#include "presets.h"

using std::string, std::ifstream, std::vector, std::cout, std::filesystem::current_path, std::filesystem::exists;
using namespace ftxui;

ButtonOption Style() {
  auto option = ButtonOption::Animated();
  option.transform = [](const EntryState& s) {
    auto element = text(s.label);
    if (s.focused) {
      element |= bold;
    }
    return element | center | borderEmpty | flex;
  };
  return option;
}

ScreenPresets::ScreenPresets()
{
  screens = { {"mainMenu", 1}, {"cardTest", 2}};
}

Element ScreenPresets::DisplaySprite(string sprNameToDisplay)
{
  string spriteFilePath = string(current_path().parent_path()) + "/sprites/" + sprNameToDisplay + ".txt";

  if (!exists(spriteFilePath))
  {
    return text("Sprite not found!");
  }

  else
  {
    ifstream spriteFile(spriteFilePath);
    string lineRead;
    vector<Element> documentElements;

    while (getline(spriteFile, lineRead))
    {
      documentElements.push_back(hbox(text(lineRead)));
    }

    return vbox(documentElements);
  }
}

Element ScreenPresets::GETcardSprite(Card cardToGet, int typeOfCard)
{
  string numFilePath = string(current_path().parent_path()) + "/sprites/cardNums.txt";
  string suitFilePath = string(current_path().parent_path()) + "/sprites/cardSuits.txt";
  vector<Element> cardSprite;
  ifstream numFile(numFilePath);
  ifstream suitFile(suitFilePath);
  string lineRead;
  int counter;

  switch(typeOfCard)
  {
    case 1: //* PLAYER CARD 1
      cardSprite.push_back(hbox(text(" _____________________________")));
      cardSprite.push_back(hbox(text("|                             |")));
      
      while (getline(numFile, lineRead))
      {
        if (lineRead == cardToGet.first)
        {
          break;
        }

        else
        {
          continue;
        }
      }

      for (int counter = 4; counter != 0; counter--)
      {
        getline(numFile, lineRead);
        cardSprite.push_back(hbox(text(lineRead)));
      }

      for (int counter = 3; counter != 0; counter--)
      {
        cardSprite.push_back(hbox(text("|                             |")));
      }

      while (getline(suitFile, lineRead))
      {
        if (lineRead == cardToGet.second)
        {
          break;
        }

        else
        {
          continue;
        }
      }

      for (int counter = 3; counter != 0; counter--)
      {
        getline(suitFile, lineRead);
        cardSprite.push_back(hbox(text(lineRead)));
      }

      for (int counter = 3; counter != 0; counter--)
      {
        cardSprite.push_back(hbox(text("|                             |")));
      }

      for (int counter = 4; counter != 0; counter--)
      {
        getline(numFile, lineRead);
        cardSprite.push_back(hbox(text(lineRead)));
      }

      cardSprite.push_back(hbox(text("|_____________________________|")));
      break;

    default:
      break;
  }

  suitFile.close();
  numFile.close();
  return vbox(cardSprite);
}

//* PRESETS START -------------------------------------------------------

void ScreenPresets::MainMenuScreen()
{
  auto btn1 = Button("start", [&] { cout << "start works\n"; }, Style());
  auto btn2 = Button("quit", [&] { system("clear"); exit(0); }, Style());

  auto mainMenu = Container::Horizontal({btn1, btn2}, 0);

  auto spriteScreen = Screen::Create(Dimension::Full(), Dimension::Full());
  Render(spriteScreen, vbox({filler(), DisplaySprite("21spr") | center, filler(), filler(), filler()}));

  spriteScreen.Print();
  auto component = Renderer(mainMenu, [&] {
    return vbox ({
      hbox ({
        filler(),
        filler(),
        btn1->Render() | flex,
        filler(),
        btn2->Render() | flex,
        filler(),
        filler()
      })
    });
  });
  auto screen = ScreenInteractive::FixedSize(285, 35);
  screen.Loop(component);
}

void ScreenPresets::CardTest()
{
  auto cardSpr = GETcardSprite({"Ace", "Heart"}, 1);
  auto spriteScreen = Screen::Create(Dimension::Full(), Dimension::Full());
  Render(spriteScreen, cardSpr);
  spriteScreen.Print();
}

//* END OF PRESETS -----------------------------------------------------