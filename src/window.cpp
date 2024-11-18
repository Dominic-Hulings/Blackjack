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
 
using std::string, std::ifstream, std::pair, std::map, std::vector;
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
  vector<Element> cardSprite;

  switch(typeOfCard)
  {
    case 1: //* PLAYER CARD 1
      break;
    default:
      break;
  }
}