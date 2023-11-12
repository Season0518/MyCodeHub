cmake_minimum_required(VERSION 3.21)
project(BankSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "BankSystem")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(BankSystem main.cpp UI/mainwindow.cpp UI/mainwindow.h UI/mainwindow.ui global.h Class/userAccount.cpp Class/userAccount.h Class/fileProcess.cpp Class/fileProcess.h tools.cpp UI/depositwindow.cpp UI/depositwindow.h UI/depositwindow.ui UI/userwindow.cpp UI/userwindow.h UI/userwindow.ui)
target_link_libraries(BankSystem
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

