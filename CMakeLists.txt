cmake_minimum_required(VERSION 3.12)
project(Minigame_Collection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Minigame_Collection_SOURCE_DIR}/cmake")

include_directories(.)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(Minigame_Collection
        main.cpp core/header/debug.hpp core/header/definitions.hpp menue/menue.cpp menue/menue.hpp)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(Minigame_Collection ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})