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

#include "window.h"
 
using std::string, std::ifstream, std::pair, std::map, std::vector, std::filesystem::current_path;
using namespace ftxui;

Window::Window(string screen)
{
  if (screen != "NULL")
  {
    GETscreen(screen);
  }
}

void Window::GETscreen(string screen)
{
  switch(screens.at(screen))
  {
    case 1:
      MainMenuScreen();
      break;
    case 2:
      CardTest();
      break;
    default:
      break;
  }
}

Element Window::GETcardSprite(Card cardToGet, int typeOfCard)
{
  string spriteFilePath = string(current_path().parent_path()) + "/sprites/cardNums.txt";
  vector<Element> cardSprite;
  ifstream spriteFile(spriteFilePath);
  string lineRead;
  int counter = 4;
  int otherCounter = 10;
  bool foundVal = false;

  switch(typeOfCard)
  {
    case 1: //* PLAYER CARD 1
      cardSprite.push_back(hbox(text(" ______________________________")));
      while(getline(spriteFile, lineRead))
      {
        if (!foundVal)
        {
          if (lineRead == cardToGet.first)
          {
            foundVal = true;
          }

          else
          {
            continue;
          }
        }

        else if (counter != 0)
        {
          counter--;
          cardSprite.push_back(hbox(text(lineRead)));
        }

        else if (otherCounter != 0)
        {
          otherCounter--;
          cardSprite.push_back(hbox(text("|                              |")));
          counter = 4;
        }

        else if (counter != 0)
        {
          counter--;
          cardSprite.push_back(hbox(text(lineRead)));
        }
      }

      cardSprite.push_back(hbox(text("|______________________________|")));
      
      break;
    default:
      break;
  }
}