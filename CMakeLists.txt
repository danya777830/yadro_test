cmake_minimum_required(VERSION 2.8)


project(cyber_club)

include_directories(files_managers)

include_directories(cyber_club)

include_directories(events)

add_executable(
main 
main.cpp 
cyber_club/cyber_club.cpp
)