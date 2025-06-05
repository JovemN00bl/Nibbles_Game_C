cmake_minimum_required(VERSION 3.28)
project(teste12 C)

set(CMAKE_C_STANDARD 11)

add_executable(teste12 main.c)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
target_link_libraries(  teste12 ${CURSES_LIBRARIES} )
