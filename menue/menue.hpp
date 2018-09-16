//
// Created by Raphael Straub on 15.09.18.
//

#ifndef MINIGAME_COLLECTION_MENUE_HPP
#define MINIGAME_COLLECTION_MENUE_HPP

#include "./../core/header/definitions.hpp"

#include <SDL2/SDL.h>
#include <unordered_map>
//#include "./../core/header/game.hpp"

class game;

class menue{
public:
    menue();
    ~menue();

    void display();

private:
    void handleEvents();
    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool running = true;
    game *spiel;
};

#endif //MINIGAME_COLLECTION_MENUE_HPP
