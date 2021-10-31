//
// Created by liangwang on 2021-10-29.
//

#include "main_application.h"
#include <fmt/format.h>
#include <memory>

using namespace chlorine;

ui::main_application::main_application()
    : Gtk::Application("com.internal-compiler-error.chlorine"), action_group_{Gio::SimpleActionGroup::create()}, gtk_builder_{Gtk::Builder::create()},
      main_window_{std::make_unique<ui::main_window>()}, about_dialog_{std::make_unique<about_dialog>()} {
    Glib::set_application_name("Chlorine");
}
void ui::main_application::on_new_pressed() const noexcept { fmt::print("new button pressed\n"); }
void ui::main_application::on_about_pressed() const noexcept {
    about_dialog_->show();
}
void ui::main_application::on_startup() {
    Application::on_startup();

    add_action("new", [this]() { on_new_pressed(); });
    add_action("about", [this]() { on_about_pressed(); });


    Glib::ustring ui_info = "<interface>"
                            "  <!-- menubar -->"
                            "  <menu id='main-menu'>"
                            "    <submenu>"
                            "      <attribute name='label' translatable='yes'>_File</attribute>"
                            "      <section>"
                            "        <item>"
                            "          <attribute name='label' translatable='yes'>New</attribute>"
                            "          <attribute name='action'>app.new</attribute>"
                            "        </item>"
                            "      </section>"
                            "    </submenu>"
                            "    <submenu>"
                            "      <attribute name='label' translatable='yes'>_Help</attribute>"
                            "      <section>"
                            "        <item>"
                            "          <attribute name='label' translatable='yes'>_About</attribute>"
                            "          <attribute name='action'>app.about</attribute>"
                            "        </item>"
                            "      </section>"
                            "    </submenu>"
                            "  </menu>"
                            "</interface>";


    try {
        gtk_builder_->add_from_string(ui_info);
    } catch (...) { fmt::print("err wtf!"); }

    auto gmenu = gtk_builder_->get_object<Gio::Menu>("main-menu");

    if (!gmenu) {
        g_warning("err wtf");
    } else {
        set_menubar(gmenu);
    }
}
std::shared_ptr<chlorine::ui::main_application> ui::main_application::create() { return Glib::make_refptr_for_instance(new main_application); }
void ui::main_application::on_activate() {
    Application::on_activate();
    add_window(*main_window_);

    main_window_->set_show_menubar();
    main_window_->show();
}
