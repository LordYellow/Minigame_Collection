//
// Created by Raphael Straub on 16.09.18.
//

#ifndef MINIGAME_COLLECTION_GAME_HPP
#define MINIGAME_COLLECTION_GAME_HPP

#include "./definitions.hpp"

#include <SDL2/SDL.h>
#include <unordered_map>

class game{
public:
    game(SDL_Window *win, SDL_Renderer *renner, bool* running);

    virtual ~game() = default;

    virtual void run() = 0;

protected:

    virtual void handleEvents();

    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool *running;
};

#endif //MINIGAME_COLLECTION_GAME_HPP
