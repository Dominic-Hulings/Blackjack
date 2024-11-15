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
 
using std::cout, std::string, std::ifstream, std::pair, std::filesystem::exists, std::filesystem::current_path, std::vector;
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

Window::Window()
{
  auto btn1 = Button("start", [&] { cout << "start works\n"; }, Style());
  auto btn2 = Button("quit", [&] { system("clear"); exit(0); }, Style());

  auto mainMenu = Container::Horizontal({btn1, btn2}, 0);

  auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
  Render(screen, DisplaySprite("21spr"));

  screen.Print();
}

Element Window::DisplaySprite(string sprNameToDisplay)
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