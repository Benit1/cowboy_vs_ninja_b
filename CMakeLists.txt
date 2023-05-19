cmake_minimum_required(VERSION 3.23)
project(cowboy_vs_ninja)

set(CMAKE_CXX_STANDARD 14)

add_executable(cowboy_vs_ninja main.cpp sources/Character.cpp sources/Character.hpp sources/Cowboy.cpp sources/Cowboy.hpp sources/Ninja.cpp sources/Ninja.hpp sources/OldNinja.cpp sources/OldNinja.hpp sources/Point.cpp sources/Point.hpp sources/SmartTeam.cpp sources/SmartTeam.hpp sources/Team.cpp sources/Team.hpp sources/Team2.cpp sources/Team2.hpp sources/TrainedNinja.cpp sources/TrainedNinja.hpp sources/YoungNinja.cpp sources/YoungNinja.hpp Test.cpp StudentTest1.cpp TestRunner.cpp TestCounter.cpp Demo.cpp)
