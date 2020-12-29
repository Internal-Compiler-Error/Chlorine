cmake_minimum_required(VERSION 3.16)
project(Chlorine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 COMPONENTS Core Qml Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Chlorine src/main.cpp)

# by default gcc won't show color when using Ninja, this forces it to use it
add_compile_options(Chlorine PRIVATE -fdiagnostics-color=always)
target_link_libraries(Chlorine PRIVATE Qt::Quick)