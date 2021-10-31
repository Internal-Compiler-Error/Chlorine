//
// Created by liangwang on 2021-10-30.
//

#ifndef CHLORINE_MAIN_WINDOW_H
#define CHLORINE_MAIN_WINDOW_H

#include <gtkmm.h>

namespace chlorine::ui {
    class main_window : public Gtk::ApplicationWindow {
    public:
        main_window();

    private:
        Gtk::Box box_{Gtk::Orientation::HORIZONTAL};
        Gtk::Button button_{"hit me"};
    };
}// namespace chlorine::ui


#endif//CHLORINE_MAIN_WINDOW_H
