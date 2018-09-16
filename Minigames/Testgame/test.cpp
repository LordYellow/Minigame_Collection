//
// Created by Raphael Straub on 16.09.18.
//

#include "test.hpp"

test::test(SDL_Window *win, SDL_Renderer *renner, bool* running): game(win,renner,running) {

}

void test::run() {
    while(this->running){
        SDL_SetRenderDrawColor(this->renner, 0, 0, 0, 0);
        SDL_RenderClear(this->renner);

        this->handleEvents();

        SDL_RenderPresent(this->renner);\
        SDL_Delay(1);
    }
}

void test::handleEvents() {
    game::handleEvents();
}
