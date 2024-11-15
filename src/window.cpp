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

#include "window.h"
 
using std::string, std::ifstream, std::filesystem::exists, std::filesystem::current_path, std::vector;
using namespace ftxui;

Window::Window(int winToGet)
{
  switch (winToGet)
  {
    case 1:
      this->MainMenuPre();
      break;
    default:
      break;
  }
}