//
// Created by Raphael Straub on 16.09.18.
//

#include <core/header/game.hpp>

game::game(SDL_Window *win, SDL_Renderer *renner, bool *running) {
    this->win = win;
    this->renner = renner;
    this->running = running;
}

