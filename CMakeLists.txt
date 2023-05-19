cmake_minimum_required(VERSION 3.5)

project(Notakto VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH C:/Qt/6.5.0/mingw_64/lib/cmake/)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    GUI/src/main.cpp
    GUI/lib/mainwindow.h
    GUI/src/mainwindow.cpp
    GUI/src/mainwindow.ui
    GUI/lib/valikuteleht.h
    GUI/src/valikuteleht.cpp
    GUI/src/valikuteleht.ui
    CLI/src/AI.cpp
    CLI/lib/AI.h
    CLI/src/manguvali.cpp
    CLI/lib/manguvali.h
    CLI/src/laud.cpp
    CLI/lib/laud.h
)

set(CLI_SOURCES
        CLI/src/AI.cpp
        CLI/lib/AI.h
        CLI/src/manguvali.cpp
        CLI/lib/manguvali.h
        CLI/src/laud.cpp
        CLI/lib/laud.h
)

add_executable(CLI ${CLI_SOURCES} CLI/src/main.cpp)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Notakto
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Notakto APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Notakto SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Notakto
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Notakto PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Notakto PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Notakto
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Notakto)
endif()
