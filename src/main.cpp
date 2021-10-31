#include "UI/main_application.h"
#include <gtkmm.h>

int main(int argc, char *argv[]) {
    auto app = chlorine::ui::main_application::create();

    return app->run(argc, argv);
}
