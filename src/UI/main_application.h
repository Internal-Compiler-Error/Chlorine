//
// Created by liangwang on 2021-10-29.
//

#ifndef CHLORINE_MAIN_APPLICATION_H
#define CHLORINE_MAIN_APPLICATION_H
#include "about_dialog.h"
#include "main_window.h"
#include <gtkmm.h>

namespace chlorine::ui {
    class main_application : public Gtk::Application, std::enable_shared_from_this<main_application> {
    public:
        static std::shared_ptr<main_application> create();

    protected:
        void on_startup() override;
        void on_activate() override;

        void on_new_pressed() const noexcept;
        void on_about_pressed() const noexcept;

    private:
        main_application();

        std::shared_ptr<Gio::SimpleActionGroup> action_group_;
        std::shared_ptr<Gtk::Builder> gtk_builder_;
        std::unique_ptr<main_window> main_window_;
        std::unique_ptr<about_dialog> about_dialog_;
    };
}// namespace chlorine::ui

#endif// CHLORINE_MAIN_APPLICATION_H
