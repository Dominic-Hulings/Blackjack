#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp" 
#include "ftxui/dom/elements.hpp"

#include "window.h"
 
using std::cout, std::string, std::ifstream, std::filesystem::exists, std::filesystem::current_path;
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
      hbox ({
        filler(),
        text("placeholder") | center | flex,
        filler()
      }),
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

string Window::DisplaySprite(string sprNameToDisplay)
{
  string spriteFilePath = string(current_path().parent_path()) + "/sprites/" + sprNameToDisplay + ".txt";

  if (!exists(spriteFilePath))
  {
    return "Sprite " + spriteFilePath + " not found!";
  }

  ifstream spriteFile(spriteFilePath);
  string lineRead;

  while (getline(spriteFile, lineRead))
  {
    
  }

  return ;
}