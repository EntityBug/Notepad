cmake_minimum_required(VERSION 3.16)

project(Notepad VERSION 1.0.6 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Notepad
        src/main/main.cpp
        src/Notepad/Notepad.cpp
        src/Notepad/Notepad.h
        src/Notepad/Notepad.ui
        src/Dialog/Dialog.cpp
        src/Dialog/Dialog.h
        src/Dialog/Dialog.ui
        src/Setting/Setting.cpp
        src/Setting/Setting.h
        src/Setting/Setting.ui
        src/Strings/Strings.h
        src/Strings/Strings.cpp)

target_link_libraries(Notepad PRIVATE Qt6::Widgets)
