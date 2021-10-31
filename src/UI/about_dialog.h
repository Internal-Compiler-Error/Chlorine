//
// Created by liangwang on 2021-10-30.
//

#ifndef CHLORINE_ABOUT_DIALOG_H
#define CHLORINE_ABOUT_DIALOG_H

#include <gtkmm.h>

namespace chlorine::ui {
    class about_dialog : public Gtk::AboutDialog {
    public:
        about_dialog() noexcept;
        ~about_dialog() override = default;
    };
}// namespace chlorine::ui


#endif//CHLORINE_ABOUT_DIALOG_H
