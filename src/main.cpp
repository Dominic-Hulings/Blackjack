#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
 
int main(void) {
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
 
  return EXIT_SUCCESS;
}