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

  auto buttons = Container::Horizontal({btn1, btn2}, 0);

  auto component = Renderer(buttons, [&] {
    return vbox ({
      filler(),
      filler(),
      DisplaySprite("21spr", {1, 1}),
      filler(),
      hbox ({
        filler(),
        filler(),
        btn1->Render(),
        filler(),
        btn2->Render(),
        filler(),
        filler()
      }),
      filler(),
      filler()
    });
  });

  auto screen = ScreenInteractive::Fullscreen();

  screen.Loop(component);
}

Element Window::DisplaySprite(string sprNameToDisplay, pair<int, int> amtOfFiller)
{
  string spriteFilePath = string(current_path().parent_path()) + "/sprites/" + sprNameToDisplay + ".txt";
  vector<Element> allLines;

  if (!exists(spriteFilePath))
  {
    allLines.push_back(text("Sprite not found!"));
  }

  else
  {
    ifstream spriteFile(spriteFilePath);
    string lineRead;

    for (int counter = amtOfFiller.first; counter != 0; counter--)
    {
      allLines.push_back(filler());
    }

    while (getline(spriteFile, lineRead))
    {
      allLines.push_back(text(lineRead + "\n"));
    }

    for (int counter = amtOfFiller.second; counter != 0; counter--)
    {
      allLines.push_back(filler());
    }
  }

  return hbox(allLines);
}