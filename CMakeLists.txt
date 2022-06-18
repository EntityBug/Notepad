cmake_minimum_required(VERSION 3.5)

project(Notepad VERSION 1.0.6 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set(CMAKE_PREFIX_PATH "/Users/tzx/Qt/6.2.4/macos/lib/cmake")
elseif(WIN32)
<<<<<<< Updated upstream
    set(CMAKE_PREFIX_PATH "C:/Qt/6.2.3/msvc2019_64/lib/cmake")
=======
    set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")
>>>>>>> Stashed changes
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
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

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Notepad
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Notepad APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Notepad SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Notepad
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Notepad PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Notepad PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.entitybug.notepad
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Notepad)
endif()
