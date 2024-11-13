#include <memory> 
#include <string> 

#include "ftxui/component/captured_mouse.hpp"      // for ftxui
#include "ftxui/component/component.hpp"           // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  

using namespace ftxui;

ButtonOption Style()
{
  auto option = ButtonOption::Animated();
  option.transform = []( const EntryState& s )
  {
    auto element = text( s.label );
    if ( s.focused )
    {
      element |= bold;
    }
    return element | center | borderEmpty;
  };
  return option;
}

int main()
{
  int value = 50;

  auto btn_01 = Button( "Finished", [&] { value -= 1; }, Style() );

  // Modify the way to render them on screen:
  auto component = Renderer( btn_01, [&] {
  return vbox( {
    text( "Fill screen to border then click the button" ),
    btn_01->Render(),
    } )| border;
} );

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop( component );

  

  return 0;
}