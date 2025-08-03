#include "netwatch.hpp"

namespace netw 
{
    Application::Application()
    {
        auto heading = ftxui::hbox({
            ftxui::text("Welcome to NETWATCH") 
            | ftxui::bold 
            | ftxui::color(ftxui::Color::Yellow) 
            | ftxui::bgcolor(ftxui::Color::Blue) 
            | ftxui::center,
      }) | ftxui::border | ftxui::center;
        
      std::string buffer;
      auto screen = ftxui::ScreenInteractive::TerminalOutput();
      bool show_input = false;

      ftxui::ButtonOption option;
      option.transform = [](const ftxui::EntryState& state) 
      {
          return ftxui::text(state.label) | size(ftxui::WIDTH, ftxui::EQUAL, 20) | ftxui::border;
      };

      auto button = ftxui::Button("click to input text", [&] { show_input = true; });
      auto input = ftxui::Input(&buffer, ": ");

      auto container = ftxui::Container::Vertical({ button, input });

      ftxui::Component renderer = ftxui::Renderer(container, [&] {
          ftxui::Elements elements;
          elements.push_back(button->Render());  // Always show button

        if (show_input) 
            elements.push_back(input->Render()); 

        return vbox(std::move(elements));
      });

      auto with_events = renderer | ftxui::CatchEvent([&](ftxui::Event event) {
          if (event == ftxui::Event::Escape)          { screen.Exit(); }
          if (event == ftxui::Event::Character(' '))  { show_input = true; }
        return false;
      });

      screen.Loop(with_events);
    }
}
