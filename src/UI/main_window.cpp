//
// Created by liangwang on 2021-10-30.
//

#include "main_window.h"
chlorine::ui::main_window::main_window() : Gtk::ApplicationWindow{} {

    set_default_size(800, 600);

    set_child(box_);
    box_.append(button_);
}
