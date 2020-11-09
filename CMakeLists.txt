cmake_minimum_required(VERSION 3.17)
project(VirusSPL)

set(CMAKE_CXX_STANDARD 14)

add_executable(VirusSPL main.cpp Session.cpp Agents/Agent.cpp Tree/Tree.cpp examples/rule_of_5.cpp)