cmake_minimum_required(VERSION 2.8)


project(cyber_club)

include_directories(files_managers)

include_directories(cyber_club)

include_directories(cyber_data)

include_directories(events)

include_directories(club_data)

include_directories(time)

include_directories(exception)

add_executable(
main
main.cpp
cyber_club/cyber_club.cpp
files_managers/reader.cpp
files_managers/writer.cpp
club_data/client_queue.cpp
club_data/club_data.cpp
club_data/table_manager.cpp
events/event.cpp
events/error.cpp
events/client_arrived.cpp
time/my_time.cpp
)