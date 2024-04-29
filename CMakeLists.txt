cmake_minimum_required(VERSION 3.5)

project(Ecommerce-Cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Ecommerce-Cpp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mainwindow2.h mainwindow2.cpp mainwindow2.ui
        mainwindowadm.h mainwindowadm.cpp mainwindowadm.ui
        mainwindowadm2.h mainwindowadm2.cpp mainwindowadm2.ui
        mainwindowseller.h mainwindowseller.cpp mainwindowseller.ui
        mainwindowseller2.h mainwindowseller2.cpp mainwindowseller2.ui
        mainwindowseller3.h mainwindowseller3.cpp mainwindowseller3.ui
        mainwindowseller4.h mainwindowseller4.cpp mainwindowseller4.ui
        mainwindowuser.h mainwindowuser.cpp mainwindowuser.ui
        AdminTableLogic.cpp Login_Filing.cpp
        mainwindoweditinfo.h mainwindoweditinfo.cpp mainwindoweditinfo.ui
        mainwindowuser2.h mainwindowuser2.cpp mainwindowuser2.ui
        mainwindowuser3.h mainwindowuser3.cpp mainwindowuser3.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Ecommerce-Cpp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Ecommerce-Cpp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Ecommerce-Cpp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Ecommerce-Cpp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Ecommerce-Cpp)
endif()
set_target_properties(Ecommerce-Cpp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Ecommerce-Cpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Ecommerce-Cpp)
endif()
