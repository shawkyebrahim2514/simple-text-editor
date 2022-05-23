cmake_minimum_required(VERSION 3.5)

project(Text_Editor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
	all_functions.h
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        addtextwindow.cpp
        addtextwindow.h
        addtextwindow.ui
        addfilenamewindow.cpp
        addfilenamewindow.h
        addfilenamewindow.ui
        howsavewindow.cpp
        howsavewindow.h
        howsavewindow.ui
        searchwordwindow.cpp
        searchwordwindow.h
        searchwordwindow.ui
        showcontentwindow.cpp
        showcontentwindow.h
        showcontentwindow.ui
        mainfilename.cpp
        mainfilename.h
        mainfilename.ui
        wordtimeswindow.cpp
        wordtimeswindow.h
        wordtimeswindow.ui
        savenewfilename.cpp
        savenewfilename.h
        savenewfilename.ui
        messagewindow.cpp
        messagewindow.h
        messagewindow.ui
	Img.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Text_Editor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Text_Editor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Text_Editor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Text_Editor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Text_Editor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Text_Editor PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Text_Editor)
endif()
