cmake_minimum_required(VERSION 3.17)
project(NaviTEC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(NaviTEC
        main.c
        main.h Kids/RegisterKids.c Kids/RegisterKids.h Elfs/RegisterElfs.c Elfs/RegisterElfs.h Toys/RegisterToys.c Toys/RegisterToys.h Places/RegisterPlaces.c Places/RegisterPlaces.h Behavior/RegisterBehavior.c Behavior/RegisterBehavior.h Letters/RegisterLetters.c Letters/RegisterLetters.h)
