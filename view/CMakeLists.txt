cmake_minimum_required(VERSION 3.5)

project(view VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR}PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        # Main
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        # Graph
        graphwindow.cpp
        graphwindow.h
        graphwindow.ui
        qcustomplot.cpp
        qcustomplot.h
        # Credit
        creditwindow.h
        creditwindow.cpp
        creditwindow.ui
        # Debit
        debitwindow.h
        debitwindow.cpp
        debitwindow.ui

        # Backend
        ./../smart_calc_controller.c
        ./../smart_calc_controller.h
        ./../modules/calculate.c
        ./../modules/headers/calculate.h
        ./../modules/from_infix_to_polish.c
        ./../modules/headers/from_infix_to_polish.h
        ./../modules/input_validation.c
        ./../modules/headers/input_validation.h
        ./../modules/lexems_divider.c
        ./../modules/headers/lexems_divider.h
        ./../modules/stack.c
        ./../modules/headers/stack.h
        ./../modules/creditCalc.c
        ./../modules/headers/creditCalc.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(view
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET view APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(view SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(view
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(view PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(view PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(view PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(view)
endif()
