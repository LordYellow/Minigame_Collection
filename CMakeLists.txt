cmake_minimum_required(VERSION 3.12)
project(Minigame_Collection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Minigame_Collection_SOURCE_DIR}/cmake")

include_directories(.)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(Minigame_Collection
        main.cpp core/header/debug.hpp core/header/definitions.hpp menue/source/menue.cpp menue/header/menue.hpp core/header/game.hpp Minigames/Testgame/test.cpp Minigames/Testgame/test.hpp core/source/game.cpp menue/source/gamePreview.cpp menue/header/gamePreview.hpp core/source/texture.cpp core/header/texture.hpp Minigames/Chess/source/chess.cpp Minigames/Chess/header/chess.hpp core/source/gameUtilities.cpp core/header/gameUtilities.hpp Minigames/Chess/header/piece.hpp Minigames/Chess/source/piece.cpp Minigames/Chess/source/pawn.cpp Minigames/Chess/header/pawn.hpp)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(Minigame_Collection ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})