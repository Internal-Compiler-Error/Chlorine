cmake_minimum_required(VERSION 3.16)
project(Chlorine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm REQUIRED QUIET IMPORTED_TARGET gtkmm-4.0)

find_package(fmt CONFIG REQUIRED)

add_executable(Chlorine src/main.cpp)

add_library(ChlorineCore src/UI/main_application.cpp src/UI/main_application.h src/UI/main_window.cpp src/UI/main_window.h src/UI/about_dialog.cpp src/UI/about_dialog.h)

target_compile_options(ChlorineCore PRIVATE -pthread)
target_link_libraries(ChlorineCore PUBLIC PkgConfig::gtkmm)
target_link_libraries(ChlorineCore PRIVATE fmt::fmt)

target_link_libraries(Chlorine PRIVATE ChlorineCore)

# by default gcc won't show color when using Ninja, this forces it to use it
add_compile_options(Chlorine PRIVATE -fdiagnostics-color=always)