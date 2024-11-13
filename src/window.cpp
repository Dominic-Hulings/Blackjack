#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp" 
#include "ftxui/dom/elements.hpp"

#include "window.h"
 
using std::cout;
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
  auto btn2 = Button("quit", [&] { cout << "quit works\n"; }, Style());

  auto component = Renderer([&] {
    return vbox ({
      filler(),
      filler(),
      hbox ({
        filler(),
        text("Blackjack") | center | flex,
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