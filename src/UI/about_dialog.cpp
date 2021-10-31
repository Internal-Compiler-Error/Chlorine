//
// Created by liangwang on 2021-10-30.
//

#include "about_dialog.h"
chlorine::ui::about_dialog::about_dialog() noexcept : Gtk::AboutDialog{} {
    set_title("About Chlorine");
    set_name("Chlorine");
    set_hide_on_close(true);
    set_authors({"Liang Wang"});
    set_logo_default();
    set_modal(true);
    set_comments("Chlorine is another attempt at wrinting a high performance downloader");
    set_license_type(Gtk::License::GPL_2_0);
}
