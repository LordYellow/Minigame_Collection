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

    virtual void run() = 0;

protected:

    virtual void handleEvents();

    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool *running;
};

game::game(SDL_Window *win, SDL_Renderer *renner, bool* running) {
    this->win = win;
    this->renner = renner;
    this->running = running;
}

void game::handleEvents() {
    if(SDL_PollEvent(&this->event)){
        switch(this->event.type){
            case SDL_QUIT: *this->running = false; break;
            case SDL_KEYDOWN: this->keys[this->event.key.keysym.sym] = 1; break;
            case SDL_KEYUP: this->keys[this->event.key.keysym.sym] = 0; break;
        }
    }
}

#endif //MINIGAME_COLLECTION_GAME_HPP
