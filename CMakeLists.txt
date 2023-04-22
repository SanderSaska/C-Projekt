cmake_minimum_required(VERSION 3.25)
project(Projekt)

set(CMAKE_CXX_STANDARD 20)

set(Projekt src/main.cpp)

add_executable(Projekt src/main.cpp src/laud.cpp lib/laud.h src/manguvali.cpp lib/manguvali.h src/AI.cpp lib/AI.h)
