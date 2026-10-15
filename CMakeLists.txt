
cmake_minimum_required(VERSION 3.21)
project(SlipCut VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets)

qt_add_executable(SlipCut
    src/main.cpp
)

target_link_libraries(SlipCut PRIVATE Qt6::Widgets)

if(APPLE)
    set_target_properties(SlipCut PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.slipcut.editor"
        MACOSX_BUNDLE_BUNDLE_NAME "SlipCut"
    )
endif()
