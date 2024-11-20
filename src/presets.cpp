#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <vector>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp" 
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/event.hpp" 

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
  screens = { {"mainMenu", 1}, {"cardTest", 2}, {"tableTest", 3}, {"escScreen", 4}};
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

void ScreenPresets::MainMenuScreen() //*                        MAIN MENU
{
  auto screen = ScreenInteractive::Fullscreen();

  auto startBtn = Button("start", [&] { screen.ExitLoopClosure()(); system("clear"); CardTest(); }, Style());
  auto quitBtn = Button("quit", [&] { system("clear"); exit(0); }, Style());

  auto mainMenu = Container::Horizontal({startBtn, quitBtn}, 0);

  auto renderer = Renderer(mainMenu, [&] {
    return vbox ({
      filler(),
      DisplaySprite("21spr") | center,
      filler(),
      hbox ({
        filler(),
        filler(),
        startBtn->Render() | flex,
        filler(),
        quitBtn->Render() | flex,
        filler(),
        filler()
      }),
      filler(),
      filler()
    });
  });

  screen.Loop(renderer);
}

void ScreenPresets::EscScreen() //*                           ESC SCREEN 
{
  auto screen = ScreenInteractive::Fullscreen();
  
  auto resumeBtn = Button("resume", [&] { screen.ExitLoopClosure()(); system("clear"); });
  auto quitBtn = Button("quit", [&] { system("clear"); exit(0); }, Style());

  auto escMenu = Container::Vertical({resumeBtn, quitBtn}, 0);

  auto renderer = Renderer(escMenu, [&] {
    return vbox ({
      filler(),
      hbox ({
        filler(),
        resumeBtn->Render(),
        quitBtn->Render(),
        filler()
      }),
      filler()
    });
  });

  screen.Loop(renderer);
}

//* END OF PRESETS -----------------------------------------------------
//* TESTS START --------------------------------------------------------

void ScreenPresets::CardTest()
{
  auto screen = ScreenInteractive::Fullscreen();

  auto renderer = Renderer([&] {
    return vbox ({
      filler(),
      hbox ({
        filler(),
        GETcardSprite({"Ace", "Spades"}, 1),
        GETcardSprite({"Ace", "Hearts"}, 1),
        filler()
      })
    });
  });

  auto component = CatchEvent(renderer, [&](Event event) {
    if (event == Event::Escape) {
      screen.ExitLoopClosure()();
      return true;
    }
    return false;
  });

  bool isPaused = false;

  while (true)
  {
    if (!isPaused)
    {
      screen.Loop(component);
    }

    else
    {
      EscScreen();
    }
    
    isPaused = !isPaused;
  }
}

void ScreenPresets::TableTest()
{
  auto screen = ScreenInteractive::Fullscreen();
  auto renderer = Renderer([&] {
    return vbox ({
      DisplaySprite("tablespr")
    });
  });

  screen.Loop(renderer);
}

//* END OF TESTS ------------------------------------------------------