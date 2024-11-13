#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

#include "window.h"
 
Window::Window()
{
  using namespace ftxui;
 
  // Define the document
  Element document =
    vbox ({
      filler(),
      hbox({
        filler(),
        text("middle"),
        filler()
      }),
      filler(),
    });
 
  auto screen = Screen::Create(
    Dimension::Full(),       // Width
    Dimension::Full()        // Height
  );
  Render(screen, document);
  screen.Print();
}