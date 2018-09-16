//
// Created by Raphael Straub on 16.09.18.
//

#include <core/header/game.hpp>

game::game(SDL_Window *win, SDL_Renderer *renner, bool *running) {
    this->win = win;
    this->renner = renner;
    this->running = running;
}

void game::handleEvents() {
    if (SDL_PollEvent(&this->event)) {
        switch (this->event.type) {
            case SDL_QUIT:
                *this->running = false;
                break;
            case SDL_KEYDOWN:
                this->keys[this->event.key.keysym.sym] = 1;
                break;
            case SDL_KEYUP:
                this->keys[this->event.key.keysym.sym] = 0;
                break;
        }
    }
}
