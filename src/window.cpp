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
 
using std::string, std::ifstream, std::vector, std::filesystem::current_path, std::filesystem::exists;
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
    default:
      break;
  }
}