#include "UI/main_window.h"
#include <gtkmm.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<chlorine::ui::main_window>(argc, argv);
}
